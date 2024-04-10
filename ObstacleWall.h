#pragma once
#include "Engine/GameObject.h"
class ObstacleWall :
    public GameObject
{
	int hObstacle_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	ObstacleWall(GameObject* parent);

	void Initialize() override;

	void Update() override;

	void Draw() override;

	void Release() override;
};