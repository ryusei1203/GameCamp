#include "../Lib/Window/Window.h"
#include "../Lib/D3D/D3D.h"
#include "../ResourceManager/ResourceManager.h"
#include "../ObjectBase/ObjectBase.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {

	// ウィンドウ初期化
	Window::Init();

	// D3D初期化
	D3D::Init();

	// 画像読み込み
	ResourceManager::GetInstance().LoadTexture();

	ObjectBase *player = new Player();
	ObjectBase *enemy = new Enemy();

	// メインループ
	while (Window::ProcessMassage()) {

		// 描画開始
		D3D::DrawStart();

		player->Draw();
		enemy->Draw();

		// 描画終了
		D3D::DrawEnd();
	}
	
	delete enemy;
	enemy = nullptr;
	delete player;
	player = nullptr;

	// テクスチャ開放
	Texture::Release();

	// D3D解放
	D3D::Release();

	return 0;
}

