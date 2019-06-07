#include "Window.h"

namespace Window {

	/*----ウィンドウプロシージャ----*/
	LRESULT WINAPI WindowProc(
		HWND hWnd,
		UINT msg,
		WPARAM wParam,
		LPARAM lParam) {

		switch (msg) {
			// アプリケーション終了処理
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}

		return 0;
	}
	/*----ウィンドウプロシージャ----*/

	/*----初期化----*/
	void Init() {
		// インスタンスハンドル
		HINSTANCE instance = GetModuleHandle(nullptr);

		// ウィンドウクラス
		WNDCLASSEX window_class{};

		// ウィンドウ情報登録
		RegisterWindowClass(window_class, instance);

		// ウィンドウ生成
		MakeWindow(instance);
	}
	/*----初期化----*/

	/*----ウィンドウ情報の登録----*/
	void RegisterWindowClass(WNDCLASSEX window_class, HINSTANCE instance) {
		// WNDCLASSEX構造体のサイズ
		window_class.cbSize = sizeof(WNDCLASSEX);
		// ウィンドウスタイル
		window_class.style = CS_HREDRAW | CS_VREDRAW;
		// ウィンドウプロシージャのアドレス
		window_class.lpfnWndProc = WindowProc;
		// 予備メモリ
		window_class.cbWndExtra = 0;
		// ウィンドウオブジェクト生成時に確保されるメモリサイズ
		window_class.cbClsExtra = 0;
		// インスタンスハンドル
		window_class.hInstance = instance;
		// アプリのショートカットなどで使用されるアイコン
		window_class.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		// ウィンドウのクライアント上のマウスカーソル
		window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
		// ウィンドウのクライアント領域の背景色
		window_class.hbrBackground = NULL;
		// メニュー名
		window_class.lpszMenuName = NULL;
		// Windowクラス名
		window_class.lpszClassName = TEXT("ゲーム合宿");
		// タイトルバーで使用されるアイコン
		window_class.hIconSm = NULL;

		// ウィンドウ情報登録
		if (RegisterClassEx(&window_class) == NULL) {
			return;
		}
	}
	/*----ウィンドウ情報の登録----*/

	/*----ウィンドウリサイズ----*/
	void ResizeWindow(HWND hwnd) {

		RECT window;
		RECT client;

		// スクリーン座標取得
		GetWindowRect(hwnd, &window);
		// クライアント座標取得
		GetClientRect(hwnd, &client);

		int window_size_x = (window.right - window.left);
		int window_size_y = (window.bottom - window.top);
		int client_size_x = (client.right - client.left);
		int client_size_y = (client.bottom - client.top);
		int frame_size_x = window_size_x - client_size_x;
		int frame_size_y = window_size_y - client_size_y;

		// ウィンドウサイズ再設定
		SetWindowPos(
			// ウィンドウハンドル
			hwnd,
			// 先行するウィンドウハンドルの指定
			NULL,
			// ウィンドウ表示位置(X座標)
			CW_USEDEFAULT,
			// ウィンドウ表示位置(Y座標)
			CW_USEDEFAULT,
			// ウィンドウ幅(横)
			frame_size_x + WINDOW_W,
			// ウィンドウ幅(縦)
			frame_size_y + WINDOW_H,
			// ウィンドウサイズ、位置の変更に関するフラグ
			SWP_NOMOVE
		);
	}
	/*----ウィンドウリサイズ----*/

	/*----ウィンドウ生成----*/
	void MakeWindow(HINSTANCE instance) {
		// ウィンドウ生成
		hwnd = CreateWindow(
			// 登録されているウィンドウクラスの文字列
			TEXT("ゲーム合宿"),
			// ウィンドウ名
			TEXT("ゲーム合宿"),
			// ウィンドウスタイル
			WS_OVERLAPPEDWINDOW,
			// ウィンドウの表示位置(X軸)
			(GetSystemMetrics(SM_CXSCREEN) / 2) - (WINDOW_W / 2),
			// ウィンドウの表示位置(Y軸)
			(GetSystemMetrics(SM_CYSCREEN) / 2) - (WINDOW_H / 2),
			// ウィンドウの横幅
			WINDOW_W,
			// ウィンドウの縦幅
			WINDOW_H,
			// 親のウィンドウハンドル
			NULL,
			// メニューハンドル
			NULL,
			// インスタンスハンドル
			instance,
			// WM_CREATEメッセージのlpparamのCREATESTRUCT構造体のポインタ
			NULL
		);

		// ウィンドウリサイズ
		ResizeWindow(hwnd);

		// nullチェック
		if (hwnd == NULL) {
			return;
		}

		// ウィンドウ表示
		ShowWindow(hwnd, SW_SHOW);
	}
	/*----ウィンドウ生成----*/

	/*----メッセージ処理----*/
	bool ProcessMassage() {

		MSG msg;
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {

			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT) {
				return false;
			}
		}
		return true;
	}
	/*----メッセージ処理----*/

}

