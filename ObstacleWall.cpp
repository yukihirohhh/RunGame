#include "ObstacleWall.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"
#include "PlayScene.h"

ObstacleWall::ObstacleWall(GameObject* parent)
:GameObject(parent,"Obstacle"),hObstacle_(-1),collider_(nullptr)
{
}

void ObstacleWall::Initialize()
{
    hObstacle_ = Model::Load("ConcreteWall.fbx");
    assert(hObstacle_ >= 0);

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
    AddCollider(collision);
    
}

void ObstacleWall::Update()
{
    float moveSpeed = 0.2f;
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
