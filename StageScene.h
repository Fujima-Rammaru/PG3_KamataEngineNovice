#pragma once
#include"IScene.h"
#include"Player.h"
#include"InputHandler.h"

class StageScene :public IScene
{
private:
	const int  WIN_WIDTH = 720;
	const int  WIN_HEIGHT = 720;
	InputHandler* inputHandler_ = nullptr;
	ICommand* iCommand_ = nullptr;
	Player* player_ = nullptr;
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
public:
	void Init() override;
	void Update() override;
	void Draw() override;
};
