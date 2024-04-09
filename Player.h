#pragma once
#include "Engine/GameObject.h"
class Player :
    public GameObject
{
    int hPlayer_;

public:
	Player(GameObject* parent);

	void Initialize() override;

	void Update() override;

	void Draw() override;

	void Release() override;
};

