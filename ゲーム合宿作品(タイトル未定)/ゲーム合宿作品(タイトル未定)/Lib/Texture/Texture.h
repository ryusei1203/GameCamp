#pragma once

#include "../D3D/D3D.h"

// 頂点情報フラグの設定
#define FVF_2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

// テクスチャ情報
namespace Texture {

	// テクスチャデータ
	struct TextureData {

		// テクスチャ情報
		LPDIRECT3DTEXTURE9 texture;

		// テクスチャ幅
		D3DXVECTOR2 uv;
	};

	// テクスチャ読み込み
	TextureData Load(char *file_name);

	// テクスチャ開放
	void Release();
}

