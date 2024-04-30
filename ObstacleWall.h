#pragma once
#include "Engine/GameObject.h"
#include "PlayScene.h"

class ObstacleWall :
    public GameObject
{
	int hObstacle_;
	BoxCollider* collider_;
private:
	PlayScene* playScene_;
	int lastScore_;
	Text* pText;
public:
	float moveSpeed;
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	ObstacleWall(GameObject* parent);

	void Initialize() override;

	void Update() override;

	void Draw() override;

	void Release() override;
};