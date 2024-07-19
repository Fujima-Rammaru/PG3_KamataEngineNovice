#include "StageScene.h"
#include"Novice.h"
#include"math.h"
#include "TitleScene.h"

void StageScene::Init()
{
	inputHandler_ = new InputHandler();

	//キーにコマンドを割り当てる
	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveUPCommand2PressKeyW();
	inputHandler_->AssignMoveDownCommand2PressKeyS();
	player_ = new Player();
	player_->Init();
	enemy.isAlive = true;
	enemy.center = { 640,30 };
}

void StageScene::Update()
{
	if (!enemy.isAlive) {
		sceneNo_ = CLEAR;
	}

	//get input
	iCommand_ = inputHandler_->HandleInput();

	//コマンドがある場合は対象コマンドを実行する
	if (this->iCommand_) {
		iCommand_->Exec(*player_);
	}
	player_->Update();

	for (int i = 0; i < 32; i++) {
		if (enemy.isAlive && player_->bullet[i].isAppearB) {
			float bulletAndEnemyPosX = enemy.center.x - player_->bullet[i].center.x;
			float bulletAndEnemyPosY = enemy.center.y - player_->bullet[i].center.y;
			distance = sqrtf((bulletAndEnemyPosX * bulletAndEnemyPosX) + (bulletAndEnemyPosY * bulletAndEnemyPosY));
			//円の当たり判定
			if (enemy.radius + player_->bullet[i].radius >= distance) {
				enemy.isAlive = false;
				player_->bullet[i].isAppearB = false;
			}
		}
	}

	if (enemy.isAlive) {
		enemy.center.x += enemy.speed.x;

		if (enemy.center.x > WIN_WIDTH - enemy.radius) {
			enemy.speed.x *= -1;
		}
		else if (enemy.center.x < enemy.radius) {
			enemy.speed.x *= -1;
		}
	}
}

void StageScene::Draw() {
	Novice::DrawBox(0, 0, WIN_WIDTH, WIN_HEIGHT, 0.0f, BLACK, kFillModeSolid);

	player_->Draw();

	if (enemy.isAlive) {
		Novice::DrawEllipse(int(enemy.center.x), int(enemy.center.y), enemy.radius, enemy.radius, 0.0f, BLUE, kFillModeSolid);
	}
	Novice::ScreenPrintf(0, 0, "sceneNo=STAGE");
}




