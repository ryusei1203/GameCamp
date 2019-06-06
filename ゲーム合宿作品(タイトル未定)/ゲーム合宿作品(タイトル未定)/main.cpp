#include "Window.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {

	// ウィンドウ情報初期化
	Window::Init();
	
	// メインループ
	while (Window::ProcessMassage()) {

	}
	
	return 0;
}

