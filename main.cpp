#include <Novice.h>
#include "StageScene.h"

const char kWindowTitle[] = "GC2A_10_フジマ_ランマル_PG3";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	//画面の横幅
	const int WIN_WIDTH = 720;

	//画面の縦幅
	const int WIN_HEIGHT = 720;

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle,WIN_WIDTH,WIN_HEIGHT);
	StageScene* stageScene;
	stageScene = new StageScene();
	stageScene->Init();
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
		stageScene->Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		stageScene->Draw();	
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete stageScene;
	// ライブラリの終了
	Novice::Finalize();

	return 0;
}
