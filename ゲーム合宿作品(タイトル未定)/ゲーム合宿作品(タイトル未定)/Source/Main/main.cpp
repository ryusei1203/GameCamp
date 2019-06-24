#include "../Lib/Window/Window.h"
#include "../Lib/D3D/D3D.h"
#include "../Lib/KeyInput/KeyInput.h"

#include "../../Source/Manager/ResourceManager/ResourceManager.h"
#include "../../Source/Manager/ObjectManager/ObjectManager.h"

// メイン関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {
	// ウィンドウ初期化
	Window::Init();
	// D3D初期化
	D3D::Init();
	// DirectInput初期化
	KeyInput::Init();
	// 画像読み込み
	ResourceManager::GetInstance().LoadTexture();
	// オブジェクト描画
	ObjectManager object;
	// メインループ
	while (Window::ProcessMassage()) {
		// キー情報更新
		KeyInput::Update();
		// オブジェクト更新
		object.Update();
		// 描画開始
		D3D::DrawStart();
		// オブジェクト描画
		object.Draw();
		// 描画終了
		D3D::DrawEnd();
	}
	// テクスチャ解放
	Texture::Release();
	// D3D解放
	D3D::Release();
	// DirectInput解放
	KeyInput::Release();
	return 0;
}

