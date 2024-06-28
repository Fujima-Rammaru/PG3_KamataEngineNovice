#include "StageScene.h"
#include "TitleScene.h"
#include"Novice.h"
#include"math.h"


void StageScene::Init()
{
	player = new Player();

	player->Init();

	enemy.isAlive = true;
	enemy.center = { 640,30 };
}

void StageScene::Update()
{
	if (!enemy.isAlive) {
		sceneNo_ = CLEAR;
	}
	player->Update();

	//敵と自キャラの弾の当たり判定
	for (int i = 0; i < 32; i++) {
		if (enemy.isAlive && player->bullet[i].isAppear) {
			float bulletAndEnemyPosX = enemy.center.x - player->bullet[i].center.x;
			float bulletAndEnemyPosY = enemy.center.y - player->bullet[i].center.y;
			distance = sqrtf((bulletAndEnemyPosX * bulletAndEnemyPosX) + (bulletAndEnemyPosY * bulletAndEnemyPosY));
		}
		//円の当たり判定
		if (enemy.radius + player->bullet[i].radius >= distance) {
			enemy.isAlive = false;
			player->bullet[i].isAppear = false;
		}
	}

	if (enemy.isAlive) {
		enemy.center.x += enemy.speed.x;

		if (enemy.center.x > 1280 - enemy.radius) {
			enemy.speed.x *= -1;
		}
		else if (enemy.center.x < enemy.radius) {
			enemy.speed.x *= -1;
		}
	}
}

void StageScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
	player->Draw();
	if (enemy.isAlive) {
		Novice::DrawEllipse(int(enemy.center.x), int(enemy.center.y), enemy.radius, enemy.radius, 0.0f, BLUE, kFillModeSolid);
	}
	Novice::ScreenPrintf(0, 0, "sceneNo=STAGE");
}




