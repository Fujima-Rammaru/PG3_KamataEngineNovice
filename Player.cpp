#include "Player.h"
#include<array>
Player::Player()
{
	isAppear = true;
	center_.x = float(WIN_WIDTH / 2);
	center_.y = float(PLAYER_START_POSY);
	textureHandle = Novice::LoadTexture("white1x1.png");
}

void Player::Init()
{
	isAppear = true;
	center_.x = float(WIN_WIDTH / 2);
	center_.y = float(PLAYER_START_POSY);
	bullet.resize(32);

	for (int i = 0; i < 32; i++) {
		bullet[i].center = { 0,0 };
		bullet[i].isAppearB = false;
		bullet[i].speed = { 0,10 };
	}
}

void Player::Update()
{
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	if (isAppear) {
		if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
			for (int i = 0; i < 32; i++) {
				if (!bullet[i].isAppearB) {
					bullet[i].isAppearB = true;
					bullet[i].center = center_;
					break;
				}
			}
		}

		for (int i = 0; i < 32; i++) {
			if (bullet[i].isAppearB) {
				bullet[i].center.y -= bullet[i].speed.y;
			}

			if (bullet[i].center.y < -bullet[i].radius) {
				bullet[i].isAppearB = false;
			}
		}
	}
}

void Player::Draw()
{
	if (isAppear) {

		for (int i = 0; i < 32; i++) {
			if (bullet[i].isAppearB) {
				Novice::DrawEllipse(int(bullet[i].center.x), int(bullet[i].center.y), bullet[i].radius, bullet[i].radius, 0.0f, RED, kFillModeSolid);
			}
		}

		Novice::DrawEllipse(int(center_.x), int(center_.y), int(radius), int(radius), 0.0f, WHITE, kFillModeSolid);
	}
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

