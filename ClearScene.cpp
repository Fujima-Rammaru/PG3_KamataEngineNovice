#include "ClearScene.h"
#include "Novice.h"

void ClearScene::Init()
{
}

void ClearScene::Update()
{
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
	if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
		sceneNo_ = TITLE;
	}
}

void ClearScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f,GREEN, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "sceneNo=CLEAR");
}
