#pragma once
#include <windows.h>

namespace Window {

	static HWND hwnd = nullptr;

	// Windowサイズ
	#define WINDOW_W (800)
	#define WINDOW_H (600)

	// 初期化
	void Init();

	// ウィンドウプロシージャ
	LRESULT WINAPI WindowProc(
		HWND hWnd,
		UINT msg,
		WPARAM wParam,
		LPARAM lParam);

	// ウィンドウ情報の登録
	void RegisterWindowClass(WNDCLASSEX window_class, HINSTANCE instance);

	// ウィンドウリサイズ
	void ResizeWindow(HWND hwnd);

	// ウィンドウ生成
	void MakeWindow(HINSTANCE instance);

	// メッセージ処理
	bool ProcessMassage();
};

