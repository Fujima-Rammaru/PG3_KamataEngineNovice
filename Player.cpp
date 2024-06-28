#include "Player.h"

void Player::Init()
{

	center.x = float(WIN_WIDTH / 2);
	center.y = float(PLAYER_START_POSY);
	speed.x = 4.0f;
	speed.y = 4.0f;

}

void Player::Update()
{

}

void Player::Draw()
{
	Novice::DrawEllipse(int(center.x), int(center.y), radius, radius, 0.0f, WHITE, kFillModeSolid);
}

void Player::MoveRight()
{
	this->center.x += this->speed.x;
}

void Player::MoveLeft()
{
	this->center.x -= this->center.x;
}

