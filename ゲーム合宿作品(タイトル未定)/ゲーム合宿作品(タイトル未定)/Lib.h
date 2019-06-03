#pragma once

#pragma comment (lib,"d3d9.lib")
#pragma comment (lib,"d3dx9.lib")

#include <d3d9.h>
#include <d3dx9.h>

namespace Lib {

	// ウィンドウハンドル
	HWND hWnd;

	const int WINDOW_W = 800;
	const int WINDOW_H = 600;

	/*----初期化----*/
	void Init() {

		MakeWindow();
	}
	/*----初期化----*/

	/*----ウィンドウ情報の登録----*/
	WNDCLASSEX window_class = {

		// WNDCLASSEX構造体のサイズ
		cbSize = sizeof(WNDCLASSEX),
		// ウィンドウスタイル
		style = CS_HREDRAW | CS_VREDRAW,
		// ウィンドウプロシージャのアドレス
		lpWndExtra = WindowProc,
		// 呼びメモリ
		cbClsExtra = 0,
		// インスタンスハンドル
		hInstance = instance,
		// アプリのショートカットなどで使用されるアイコン
		hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_APPLICATION)),
		// ウィンドウのクライアント上のマウスカーソル
		hCursor = LoadCursor(NULL,IDC_ARROW),
		// ウィンドウのクライアント領域の背景色
		hbrBackground = NULL,
		// メニュー名
		lpszMenuName = NULL,
		// Windowクラス名
		lpszClassName = TEXT("シューティング"),
		// タイトルバーで使用されるアイコン
		hIconSm = NULL
	};
	/*----ウィンドウ情報の登録----*/

	/*----ウィンドウ作成----*/
	void MakeWindow() {

		hWnd = CreateWindow(
			TEXT("シューティング"),
			TEXT("シューティング"),
			(WS_OVERLAPPEDWINDOW^WS_THICKFRAME) | WS_VISIBLE,
			CW_USEDEFAULT,
			0,
			WINDOW_W,
			WINDOW_H,
			NULL,
			NULL,
			window_class.hInstance,
			NULL);

		RECT window;
		RECT client;

		GetWindowRect(hWnd, &window);
		GetClientRect(hWnd, &client);

		int window_size_x = (window.right - window.left);
		int window_size_y = (window.bottom - window.top);
		int client_size_x = (client.right - client.left);
		int client_size_y = (client.bottom - client.top);
		int frame_size_x = window_size_x - client_size_x;
		int frame_size_y = window_size_y - client_size_y;

		SetWindowPos(
			hWnd,
			NULL,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			frame_size_x + WINDOW_W,
			frame_size_y + WINDOW_H,
			SWP_NOMOVE
		);

		ShowWindow(hWnd, SW_SHOW);

		UpdateWindow(hWnd);
	}
	/*----ウィンドウ作成----*/


	void ProcessMassage() {

		MSG msg;
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}