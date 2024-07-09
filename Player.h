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
	void Update();
	void Draw();
	Vector2 CornerPosition(const Vector2& center, Corner corner);
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
private:
	Vector2 center_;//中心座標
	static inline const float kSpeed = 4.0f;
	static inline const float kWidth = 16.0f;
	static inline const float kHeight = 16.0f;
	int textureHandle;//画像
	bool isAppear;//矩形の出現管理フラグ
	const int  WIN_WIDTH = 720;
	const int  WIN_HEIGHT = 720;
	const int PLAYER_START_POSY = 360;
};

