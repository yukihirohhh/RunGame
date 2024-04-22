#include "PlayScene.h"
#include "Player.h"
#include "ObstacleWall.h"
#include "Engine/Camera.h"
#include "time.h"
#include <thread>
#include <chrono>
#include "Engine/Model.h"

std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();

void PlayScene::LeftWall()
{
    ObstacleWall* obstacle1 = Instantiate<ObstacleWall>(this);
    obstacle1->SetPosition({ -1.2, 1, 20 });


    ObstacleWall* obstacle2 = Instantiate<ObstacleWall>(this);
    obstacle2->SetPosition({ 0, 1, 20 });
}

void PlayScene::RightWall()
{
    ObstacleWall* obstacle2 = Instantiate<ObstacleWall>(this);
    obstacle2->SetPosition({ 0, 1, 20 });


    ObstacleWall* obstacle3 = Instantiate<ObstacleWall>(this);
    obstacle3->SetPosition({ 1.2, 1, 20 });
}

void PlayScene::MidWall()
{
    ObstacleWall* obstacle1 = Instantiate<ObstacleWall>(this);
    obstacle1->SetPosition({ -1.2, 1, 20 });

    ObstacleWall* obstacle3 = Instantiate<ObstacleWall>(this);
    obstacle3->SetPosition({ 1.2, 1, 20 });
}

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene"), hGround_(-1)
{
}

//初期化
void PlayScene::Initialize()
{
    hGround_ = Model::Load("ground.fbx");
    assert(hGround_ >= 0);

    Instantiate<Player>(this);
    Camera::SetPosition({ 0,8,-8 });
}

//更新
void PlayScene::Update()
{
    auto currentTime = std::chrono::steady_clock::now();
    auto timeDiff = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastTime).count();

    if (timeDiff >= 2) {
        lastTime = currentTime; // 時間をリセット

        int random = rand() % 3;
        switch (random) {
        case 0:
            MidWall();
            break;
        case 1:
            RightWall();
            break;
        case 2:
            LeftWall();
            break;
        }
    }
}

//描画
void PlayScene::Draw()
{
    Model::SetTransform(hGround_, transform_);
    Model::Draw(hGround_);
}

//開放
void PlayScene::Release()
{
}

