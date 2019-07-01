#include "D3D.h"
#include "../Window/Window.h"

// D3D情報
namespace D3D {
	// IDirect3D9
	LPDIRECT3D9 d3d9 = nullptr;
	// IDirect3Dデバイス
	LPDIRECT3DDEVICE9 dev = nullptr;
	/*----D3D9初期化----*/
	void Init() {
		// PresentParameters設定
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
			pp.hDeviceWindow = Window::hwnd;
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
			Window::hwnd,
			// デバイス制御の組み合わせ
			D3DCREATE_HARDWARE_VERTEXPROCESSING,
			// デバイスを設定するためのD3DPRESENT_PARAMETERS構造体
			&pp,
			// 作成されたIDirect3DDeviceの格納
			&dev
		) != D3D_OK) {
			return;
		}
	}
	/*----D3D9初期化----*/
	
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

