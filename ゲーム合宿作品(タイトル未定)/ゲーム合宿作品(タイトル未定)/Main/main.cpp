#include "../Lib/Window/Window.h"
#include "../Lib/D3D/D3D.h"
#include "../Lib/Texture/Texture.h"
#include "../Lib/Draw2D/Draw2D.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {

	// ウィンドウ初期化
	Window::Init();

	// D3D初期化
	D3D::Init();

	// 画像読み込み
	Texture::Load(Texture::TEST);

	// メインループ
	while (Window::ProcessMassage()) {

		// 描画開始
		D3D::DrawStart();

		// 描画
		Draw2D::Box(Texture::TEST);

		// 描画終了
		D3D::DrawEnd();
	}
	
	// D3D解放
	D3D::Release();

	return 0;
}

