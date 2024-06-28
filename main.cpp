#include <Novice.h>
#include"IScene.h"
#include"GameManager.h"
#include "ClearScene.h"
#include "TitleScene.h"
#include "StageScene.h"

const char kWindowTitle[] = "GC2A_10_フジマ_ランマル_PG3";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	GameManager* gamemanager;
	gamemanager = new GameManager;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };



	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		gamemanager->Run();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
	
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete gamemanager;
	// ライブラリの終了
	Novice::Finalize();

	return 0;
}
