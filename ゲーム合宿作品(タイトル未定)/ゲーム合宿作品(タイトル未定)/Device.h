#pragma once

#pragma comment (lib,"d3d9.lib")
#pragma comment (lib,"d3dx9.lib")

#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>

namespace Device {

	static HWND hwnd = nullptr;
	static LPDIRECT3D9 d3d9 = nullptr;
	static LPDIRECT3DDEVICE9 dev = nullptr;

	// Windowサイズ
	#define WINDOW_W (800)
	#define WINDOW_H (600)

	// 初期化
	void Init();

	// ウィンドウ情報初期化
	void InitWindow();

	// D3D9初期化
	void InitD3D9();

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

	// D3D9初期化
	void Init();

	// ViewPortの設定
	void RegisterViewPort(LPDIRECT3DDEVICE9 dev, D3DPRESENT_PARAMETERS pp);

	// 描画開始
	void DrawStart();

	// 描画終了
	void DrawEnd();

	// D3D9解放
	void Release();
};

