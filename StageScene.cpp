#include "StageScene.h"
#include"Novice.h"



void StageScene::Init()
{
	inputHandler_ = new InputHandler();

	//キーにコマンドを割り当てる
	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	player_ = new Player();
}

void StageScene::Update()
{
	//get input
	iCommand_ = inputHandler_->HandleInput();

	//コマンドがある場合は対象コマンドを実行する
	if (this->iCommand_) {
		iCommand_->Exec(*player_);
	}
	player_->Update();

}

void StageScene::Draw() {
	player_->Draw();
}




