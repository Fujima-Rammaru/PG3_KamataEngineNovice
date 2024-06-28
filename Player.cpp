#include "Player.h"

void Player::Init()
{
	isAppear = true;
	center.x = float(WIN_WIDTH / 2);
	center.y = float(PLAYER_START_POSY);
	speed.x = 4.0f;
	speed.y = 4.0f;

	for (int i = 0; i < 32; i++) {
		bullet[i].center = { 0,0 };
		bullet[i].isAppear = false;
		bullet[i].speed = { 0,10 };
	}
}

void Player::Update()
{
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
	if (isAppear) {
		if (keys[DIK_W]) {
			center.y -= speed.y;
		}
		if (keys[DIK_A]) {
			center.x -= speed.x;
		}
		if (keys[DIK_S]) {
			center.y += speed.y;
		}
		if (keys[DIK_D]) {
			center.x += speed.x;
		}

		if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
			for (int i = 0; i < 32; i++) {
				if (!bullet[i].isAppear) {
					bullet[i].isAppear = true;
					bullet[i].center = center;
					break;
				}
			}
		}

		for (int i = 0; i < 32; i++) {
			if (bullet[i].isAppear) {
				bullet[i].center.y -= bullet[i].speed.y;
			}

			if (bullet[i].center.y < -bullet[i].radius) {
				bullet[i].isAppear = false;
			}
		}
	}


}

void Player::Draw()
{
	if (isAppear) {
		
		for (int i = 0; i < 32; i++) {
			if (bullet[i].isAppear) {
				Novice::DrawEllipse(int(bullet[i].center.x), int(bullet[i].center.y), bullet[i].radius, bullet[i].radius, 0.0f, RED, kFillModeSolid);
			}
		}
		Novice::DrawEllipse(int(center.x), int(center.y), radius, radius, 0.0f, WHITE, kFillModeSolid);

	}
}

