#pragma once
#include "Engine/GameObject.h"
class ObstacleWall :
    public GameObject
{
	int hObstacle_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	ObstacleWall(GameObject* parent);

	void Initialize() override;

	void Update() override;

	void Draw() override;

	void Release() override;
};