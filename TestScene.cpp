#include "TestScene.h"
#include "Player.h"
#include "ObstacleWall.h"
#include "Engine/Camera.h"
#include "time.h"


void TestScene::LeftWall()
{
    ObstacleWall* obstacle1 = Instantiate<ObstacleWall>(this);
    obstacle1->SetPosition({ -1.2, 0, 20 });


    ObstacleWall* obstacle2 = Instantiate<ObstacleWall>(this);
    obstacle2->SetPosition({ 0, 0, 20 });
}

void TestScene::RightWall()
{
    ObstacleWall* obstacle2 = Instantiate<ObstacleWall>(this);
    obstacle2->SetPosition({ 0, 0, 20 });


    ObstacleWall* obstacle3 = Instantiate<ObstacleWall>(this);
    obstacle3->SetPosition({ 1.2, 0, 20 });
}

void TestScene::MidWall()
{
    ObstacleWall* obstacle1 = Instantiate<ObstacleWall>(this);
    obstacle1->SetPosition({ -1.2, 0, 20 });

    ObstacleWall* obstacle3 = Instantiate<ObstacleWall>(this);
    obstacle3->SetPosition({ 1.2, 0, 20 });
}

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	Instantiate<Player>(this);

    MidWall();

	Camera::SetPosition({ 0,8,-8 });
}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}

