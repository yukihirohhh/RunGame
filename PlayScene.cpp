#include "PlayScene.h"
#include "Player.h"
#include "ObstacleWall.h"
#include "Engine/Camera.h"
#include "time.h"
#include <thread>
#include <chrono>

std::chrono::steady_clock::time_point lastTime = std::chrono::steady_clock::now();

void PlayScene::LeftWall()
{
    ObstacleWall* obstacle1 = Instantiate<ObstacleWall>(this);
    obstacle1->SetPosition({ -1.2, 0, 20 });


    ObstacleWall* obstacle2 = Instantiate<ObstacleWall>(this);
    obstacle2->SetPosition({ 0, 0, 20 });
}

void PlayScene::RightWall()
{
    ObstacleWall* obstacle2 = Instantiate<ObstacleWall>(this);
    obstacle2->SetPosition({ 0, 0, 20 });


    ObstacleWall* obstacle3 = Instantiate<ObstacleWall>(this);
    obstacle3->SetPosition({ 1.2, 0, 20 });
}

void PlayScene::MidWall()
{
    ObstacleWall* obstacle1 = Instantiate<ObstacleWall>(this);
    obstacle1->SetPosition({ -1.2, 0, 20 });

    ObstacleWall* obstacle3 = Instantiate<ObstacleWall>(this);
    obstacle3->SetPosition({ 1.2, 0, 20 });
}

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
    : GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
    Instantiate<Player>(this);
    Camera::SetPosition({ 0,8,-8 });
}

//更新
void PlayScene::Update()
{
    auto currentTime = std::chrono::steady_clock::now();
    auto timeDiff = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastTime).count();

    if (timeDiff >= 1) {
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
}

//開放
void PlayScene::Release()
{
}

