#include "StageScene.h"
#include "TitleScene.h"
#include"Novice.h"
#include"math.h"


void StageScene::Init()
{
	inputHandler_ = new InputHandler();

	//キーにコマンドを割り当てる
	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	player_ = new Player();

	player_->Init();

}

void StageScene::Update()
{
	//get input
	iCommand_ = inputHandler_->HandleInput();

	if (this->iCommand_) {
		iCommand_->Exec(*player_);
}
	player_->Update();

}

void StageScene::Draw() {
	player_->Draw();
}




