#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"
#include "Engine/SceneManager.h"


Player::Player(GameObject* parent)
	:GameObject(parent, "Player"),hPlayer_(-1)
{
}

void Player::Initialize()
{
	hPlayer_ = Model::Load("Tank.fbx");
	assert(hPlayer_ >= 0);

	transform_.position_.x = 0;
	transform_.position_.y = 1;
	transform_.position_.z = -3;
	transform_.rotate_.y = 180;
	
    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.6, 0.6, 0.6));
    AddCollider(collision);

}

void Player::Update()
{


    //tank.fbx‚ÌŒü‚«‚ª‹t‚¾‚Á‚½‚©‚ç180“x•Ï‚¦‚Ä‚é
    static float targetPosition = 0.0f;
    static float moveAmount = 0.1f;
    static float targetRotation = 180.0f;
    static float rotationSpeed = 5.0f;

    if (Input::IsKeyDown(DIK_LEFT) && targetPosition > -1.2f)
    {
        targetPosition -= 1.2f;
        targetRotation = 180.0f - 45.0f;
    }

    else if (Input::IsKeyDown(DIK_RIGHT) && targetPosition < 1.2f)
    {
        targetPosition += 1.2f;
        targetRotation = 180.0f + 45.0f;
    }


    if (transform_.rotate_.y < targetRotation)
    {
        transform_.rotate_.y = min(transform_.rotate_.y + rotationSpeed, targetRotation);
        if (abs(targetRotation - transform_.rotate_.y) < rotationSpeed)
        {
            targetRotation = 180.0f;
        }
    }
    else if (transform_.rotate_.y > targetRotation)
    {
        transform_.rotate_.y = max(transform_.rotate_.y - rotationSpeed, targetRotation);
        if (abs(targetRotation - transform_.rotate_.y) < rotationSpeed)
        {
            targetRotation = 180.0f;
        }
    }

    if (transform_.position_.x < targetPosition)
    {
        transform_.position_.x = min(transform_.position_.x + moveAmount, targetPosition);
    }
    else if (transform_.position_.x > targetPosition)
    {
        transform_.position_.x = max(transform_.position_.x - moveAmount, targetPosition);
    }

   
}

void Player::Draw()
{
	Model::SetTransform(hPlayer_, transform_);
	Model::Draw(hPlayer_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
}
