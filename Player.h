#pragma once
#include "Engine/GameObject.h"
#include "ObstacleWall.h"

class Player :
    public GameObject
{
    int hPlayer_;
	ObstacleWall* obstacleWall_;
public:
	Player(GameObject* parent);

	void Initialize() override;

	void Update() override;

	void Draw() override;

	void Release() override;

	void OnCollision(GameObject* pTarget)override;
};

