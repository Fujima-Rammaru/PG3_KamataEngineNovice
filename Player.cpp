#include "Player.h"

Player::Player()
{
	center.x = float(WIN_WIDTH / 2);
	center.y = float(PLAYER_START_POSY);
	speed = 4.0f;
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
	this->center.x += this->speed;
}

void Player::MoveLeft()
{
	this->center.x -= this->speed;
}

