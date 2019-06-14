#pragma once

#pragma comment (lib,"d3d9.lib")
#pragma comment (lib,"d3dx9.lib")

#include <d3d9.h>
#include <d3dx9.h>

/*
	structかclassに変更
*/

// D3D情報
namespace D3D {

	// IDirect3D9
	extern LPDIRECT3D9 d3d9;

	// IDirect3Dデバイス
	extern LPDIRECT3DDEVICE9 dev;

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
}

