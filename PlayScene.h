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
	int pScore;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
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

