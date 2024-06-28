#pragma once
#include"Vector2.h"
#include "Novice.h"


class Player {

public: 
	Player();

	void Init();
	void Update();
	void Draw();
	
	void MoveRight();
	void MoveLeft();
private:
	Vector2 center;//中心座標
	Vector2 speed;
	const int  WIN_WIDTH = 1280;
	const int  WIN_HEIGHT = 720;
	const int PLAYER_START_POSY = 700;
	const int radius = 10;
	
};

