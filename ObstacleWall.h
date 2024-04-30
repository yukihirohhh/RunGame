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
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	ObstacleWall(GameObject* parent);

	void Initialize() override;

	void Update() override;

	void Draw() override;

	void Release() override;
};