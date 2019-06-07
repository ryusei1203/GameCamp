#include "Lib.h"

namespace Lib {

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
		// ウィンドウ情報初期化
		InitWindow();

		// D3D9初期化
		InitD3D9();
	}
	/*----初期化----*/

	/*----ウィンドウ情報初期化----*/
	void InitWindow() {
		// インスタンスハンドル
		HINSTANCE instance = GetModuleHandle(nullptr);

		// ウィンドウクラス
		WNDCLASSEX window_class{};

		// ウィンドウ情報登録
		RegisterWindowClass(window_class, instance);

		// ウィンドウ生成
		MakeWindow(instance);
	}
	/*----ウィンドウ情報初期化----*/

	/*----ウィンドウ情報の登録----*/
	void RegisterWindowClass(WNDCLASSEX window_class, HINSTANCE instance) {
		// WNDCLASSEX構造体のサイズ
		window_class.cbSize = sizeof(WNDCLASSEX);
		// ウィンドウスタイル
		window_class.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
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
		window_class.hCursor = LoadCursor(NULL, IDI_APPLICATION);
		// ウィンドウのクライアント領域の背景色
		window_class.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
		// メニュー名
		window_class.lpszMenuName = MAKEINTRESOURCE(NULL);
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

	/*----D3D9初期化----*/
	void InitD3D9() {

		D3DPRESENT_PARAMETERS pp{};
		{
			// バックバッファの幅(横)
			pp.BackBufferWidth = 0;
			// バックバッファの幅(縦)
			pp.BackBufferHeight = 0;
			// バックバッファのフォーマット
			pp.BackBufferFormat = D3DFMT_A8R8G8B8;
			// バックバッファの数
			pp.BackBufferCount = 1;
			// マルチサンプル数
			pp.MultiSampleType = D3DMULTISAMPLE_4_SAMPLES;
			// マルチサンプル品質レベル
			pp.MultiSampleQuality = 0;
			// スワップエフェクトの種類
			pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
			// 画面を描画するウィンドウハンドル
			pp.hDeviceWindow = hwnd;
			// ウィンドウモード
			pp.Windowed = TRUE;
			// 深度ステンシルバッファのフォーマット
			pp.EnableAutoDepthStencil = TRUE;
			// ステンシルバッファのフォーマット
			pp.AutoDepthStencilFormat = D3DFMT_D24S8;
			// バックバッファからフロントバッファへの転送時のオプション
			pp.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
			// フルスクリーンでのリフレッシュレート
			pp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
			// スワップエフェクトの書き換えタイミング
			pp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
		}

		// LPDIRECT3D9初期化
		d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
		// nullチェック
		if (d3d9 == NULL) {
			return;
		}

		// IDirect3DDevice作成
		if (d3d9->CreateDevice(
			// ディスプレイアダプタの種類
			D3DADAPTER_DEFAULT,
			// デバイスの種類
			D3DDEVTYPE_HAL,
			// このデバイスのウィンドウハンドル
			hwnd,
			// デバイス制御の組み合わせ
			D3DCREATE_HARDWARE_VERTEXPROCESSING,
			// デバイスを設定するためのD3DPRESENT_PARAMETERS構造体
			&pp,
			// 作成されたIDirect3DDeviceの格納
			&dev
		) != D3D_OK) {
			return;
		}

		// ビューポート設定
		RegisterViewPort(dev, pp);
	}
	/*----D3D9初期化----*/

	/*----ViewPortの設定----*/
	void RegisterViewPort(LPDIRECT3DDEVICE9 dev,D3DPRESENT_PARAMETERS pp) {

		D3DVIEWPORT9 view_port;
		// 描画開始位置(X座標)
		view_port.X = 0;
		// 描画開始位置(Y座標)
		view_port.Y = 0;
		// 描画範囲(幅)
		view_port.Width = pp.BackBufferWidth;
		// 描画範囲(高さ)
		view_port.Height = pp.BackBufferHeight;
		// Z深度(最小)
		view_port.MinZ = 0.0f;
		// Z深度(最大)
		view_port.MaxZ = 1.0f;

		// ViewPort設定
		if (FAILED(dev->SetViewport(&view_port))) {
			return;
		}
	}
	/*----ViewPortの設定----*/

	/*----描画開始----*/
	void DrawStart() {
		// シーンクリア
		dev->Clear(
			// 第二引数の矩形の数
			0,
			// D3DRECTの配列
			// クリアする矩形の範囲を変更したい場合に仕様(NULLならビューポート全体をクリア)
			NULL,
			// クリアフラグ
			D3DCLEAR_TARGET,
			// クリアする色情報
			D3DCOLOR_XRGB(0, 0, 0),
			// 深度バッファで使用する値(未使用なら0.f)
			0.f,
			// ステンシルバッファで使用する値(未使用なら0)
			0
		);

		// シーン描画開始
		if (dev->BeginScene() != D3D_OK) {
			return;
		}
	}
	/*----描画開始----*/

	/*----描画終了----*/
	void DrawEnd() {
		// シーン描画終了
		dev->EndScene();

		// バッファ転送
		dev->Present(
			// 転送元矩形
			NULL,
			// 転送先矩形
			NULL,
			// ウィンドウハンドル
			NULL,
			// RGNDATA
			NULL
		);
	}
	/*----描画終了----*/

	/*----D3D9解放----*/
	void Release() {
		dev->Release();
		d3d9->Release();
	}
	/*----D3D9解放----*/
}