#include "TitleScene.h"
#include"Novice.h"

void TitleScene::Init()
{
}

void TitleScene::Update()
{
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNo_ = STAGE;
	}

}

void TitleScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "sceneNo=TITLE");
}
