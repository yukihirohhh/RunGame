#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class PlayScene :
    public GameObject
{
	void LeftWall();
	void RightWall();
	void MidWall();
	int hGround_;
	Text* pText;

public:
	int pScore;
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

