#include "ObstacleWall.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"
#include "PlayScene.h"
#include "iostream"

ObstacleWall::ObstacleWall(GameObject* parent)
:GameObject(parent,"Obstacle"),hObstacle_(-1), moveSpeed(0.2f),collider_(nullptr)
, playScene_(nullptr),lastScore_(0), pText(nullptr)
{
    playScene_ = dynamic_cast<PlayScene*>(parent);  // PlayScene‚Ö‚ÌŽQÆ‚ðŽæ“¾

}

void ObstacleWall::Initialize()
{
    hObstacle_ = Model::Load("ConcreteWall.fbx");
    assert(hObstacle_ >= 0);

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.35, 0.35, 0.35));
    AddCollider(collision);
    
}

void ObstacleWall::Update()
{
    if (playScene_->pScore >= lastScore_ + 200) {
        if (moveSpeed + 0.08f <= 0.5f) {
            moveSpeed += 0.08f;
        }
        lastScore_ += 200;
    }

    transform_.position_.z -= moveSpeed;
    if (transform_.position_.z <= -6)
    {
        KillMe();
    }
    
}

void ObstacleWall::Draw()
{
		Model::SetTransform(hObstacle_, transform_);
		Model::Draw(hObstacle_);
        

}

void ObstacleWall::Release()
{
}
