#pragma once

#include<memory>
#include"IScene.h"
#include"StageScene.h"
#include"TitleScene.h"
#include"ClearScene.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	int Run();//ゲームループ呼び出し

private:

	//シーンを保持するメンバ変数
	std::unique_ptr<IScene>sceneArr_[3];

	//どのステージを呼び出すかを管理する変数
	int currentSceneNo_;//現在のシーン
	int prevSceneNo_;//前のシーン
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};
