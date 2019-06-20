#pragma once

#include <windows.h>

// ウィンドウ情報
namespace Window {
	// ウィンドウハンドル
	extern HWND hwnd;
	// Windowサイズ
	#define WINDOW_W (800)
	#define WINDOW_H (600)
	// ウィンドウ情報初期化
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
	void Resize(HWND hwnd);
	// ウィンドウ生成
	void Create(HINSTANCE instance);
	// メッセージ処理
	bool ProcessMassage();
}

