#pragma once
#include"Vector2.h"
#include "Novice.h"

enum Corner {
	kLeftTop,
	kRightTop,
	kLeftBottom,
	kRightBottom,

	kNumCorner // 要素数
};

class Player {

public:
	Player();
	void Init();
	void Update();
	void Draw();
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

	struct Bullet {
		Vector2 center;//中心座標
		Vector2 speed;
		bool isAppearB;//矩形の出現管理フラグ
		const int radius = 5;
	};
	Bullet bullet[32];
	
private:
	Vector2 center_;//中心座標
	static inline const float kSpeed = 4.0f;
	static inline const float radius = 8.0f;
	
	int textureHandle;//画像
	bool isAppear;//矩形の出現管理フラグ
	const int  WIN_WIDTH = 720;
	const int  WIN_HEIGHT = 720;
	const int PLAYER_START_POSY = 360;
	const int PLAYER_BULLET_NUM_MAX = 32;
	char keys[256];
	char preKeys[256];
};

