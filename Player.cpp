#include "Player.h"
#include<array>
Player::Player()
{
	center_.x = float(WIN_WIDTH / 2);
	center_.y = float(PLAYER_START_POSY);
	textureHandle = Novice::LoadTexture("white1x1.png");
}

void Player::Update()
{

}

void Player::Draw()
{
	std::array<Vector2, kNumCorner> cornerPosition;
	for (int i = 0; i < cornerPosition.size(); i++) {
		cornerPosition[i] = CornerPosition(center_, static_cast<Corner>(i));
	}
	Novice::DrawQuad(
		int(cornerPosition[kLeftTop].x),
		int(cornerPosition[kLeftTop].y),
		int(cornerPosition[kRightTop].x),
		int(cornerPosition[kRightTop].y),
		int(cornerPosition[kLeftBottom].x),
		int(cornerPosition[kLeftBottom].y),
		int(cornerPosition[kRightBottom].x),
		int(cornerPosition[kRightBottom].y), 0, 0, int(kWidth), int(kHeight), textureHandle, RED
	);
}

Vector2 Player::CornerPosition(const Vector2& center, Corner corner)
{
	Vector2 offSetTable[kNumCorner] = {
		{center.x - kWidth / 2.0f,center.y - kHeight / 2.0f},//leftTop
		{center.x + kWidth / 2.0f,center.y - kHeight / 2.0f},//rightTop
		{center.x - kWidth / 2.0f,center.y + kHeight / 2.0f},//leftBottom
		{center.x + kWidth / 2.0f,center.y + kHeight / 2.0f},//rightBottom
	};

	return  offSetTable[static_cast<int>(corner)];
}



void Player::MoveRight()
{
	this->center_.x += this->kSpeed;
}

void Player::MoveLeft()
{
	this->center_.x -= this->kSpeed;
}

void Player::MoveUp()
{
	this->center_.y -= this->kSpeed;
}

void Player::MoveDown()
{
	this->center_.y += this->kSpeed;
}

