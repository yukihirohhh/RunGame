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
	hPlayer_ = Model::Load("Box.fbx");
	assert(hPlayer_ >= 0);

	transform_.position_.x = 0;
	transform_.position_.z = -3;
	
}

void Player::Update()
{

	if (Input::IsKeyDown(DIK_LEFT))
	{
		transform_.position_.x = max(transform_.position_.x - 1.2, -1.2); // ¶‚ÉˆÚ“®
	}
	if (Input::IsKeyDown(DIK_RIGHT))
	{
		transform_.position_.x = min(transform_.position_.x + 1.2, 1.2); // ‰E‚ÉˆÚ“®
	}

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
	AddCollider(collision);
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
