#include "Device.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {

	// 初期化
	Device::Init();

	// メインループ
	while (Device::ProcessMassage()) {

		// 描画開始
		Device::DrawStart();

		// 描画終了
		Device::DrawEnd();
	}
	
	// D3D解放
	Device::Release();

	return 0;
}

