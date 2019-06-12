#pragma once

#include "D3D.h"

#include <vector>

// 頂点情報フラグの設定
#define FVF_2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

namespace Texture {

	// 頂点情報
	struct CustomVetrex {

		// 頂点情報
		float x, y, z;

		// 除算数
		float rhw;

		DWORD dw_color;

		// テクスチャ座標
		float u, v;
	};

	// テクスチャデータ
	struct TextureData {

		// テクスチャ情報
		LPDIRECT3DTEXTURE9 texture;

		// テクスチャ幅
		float width, height;
	};

	// 外部で管理予定
	// テクスチャデータID
	enum TextureID {
		TEST
	};

	// テクスチャ読み込み
	void Load(TextureID texture_id);

	// 四角形描画
	void DrawBox2D(TextureID texture_id);
}

