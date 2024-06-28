#pragma once
#include"IScene.h"
#include"Player.h"

class StageScene :public IScene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	Player* player = nullptr;
	struct Enemy {
		Vector2 center;
		int radius;
		Vector2 speed;
		bool isAlive;
	};
	float distance;
	Enemy enemy = {
		{640,10},
		15,
		{3,3},
	};
};
