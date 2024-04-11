#include "ObstacleWall.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"

ObstacleWall::ObstacleWall(GameObject* parent)
:GameObject(parent,"Obstacle"),hObstacle_(-1),collider_(nullptr)
{
}

void ObstacleWall::Initialize()
{
    hObstacle_ = Model::Load("Box.fbx");
    assert(hObstacle_ >= 0);
    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
    AddCollider(collision);
    
}

void ObstacleWall::Update()
{
    const float moveSpeed = 0.438f;
    transform_.position_.z -= moveSpeed;
    if (transform_.position_.z <= -5)
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
