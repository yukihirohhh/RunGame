#include "GameOverScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent, "GameOverScene"),hPict_(-1)
{

}

void GameOverScene::Initialize()
{
	hPict_ = Image::Load("gameover.png");
	assert(hPict_ >= 0);
}

void GameOverScene::Update()
{
	if (Input::IsKeyDown(DIK_R)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void GameOverScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void GameOverScene::Release()
{
}
