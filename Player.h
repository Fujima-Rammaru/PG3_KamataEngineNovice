#pragma once
#include"Vector2.h"
#include "Novice.h"


class Player {

public: 
	void Init();
	void Update();
	void Draw();
	struct Bullet {
		Vector2 center;//中心座標
		Vector2 speed;
		bool isAppear;//矩形の出現管理フラグ
		const int radius = 5;
	};
	Bullet bullet[32];
	bool isAppear;//矩形の出現管理フラグ
private:

	const int  WIN_WIDTH = 1280;
	const int  WIN_HEIGHT = 720;
	const int PLAYER_START_POSY = 700;
	const int PLAYER_BULLET_NUM_MAX = 32;
	const int radius = 10;
	
	Vector2 center;//中心座標
	Vector2 speed;
	
	char keys[256];
	char preKeys[256];

	
};

