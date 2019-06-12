#pragma once

#include "../D3D/D3D.h"

#include <vector>

// 頂点情報フラグの設定
#define FVF_2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

namespace Texture {

	// テクスチャデータ
	struct TextureData {

		// テクスチャ情報
		LPDIRECT3DTEXTURE9 texture;

		// テクスチャ幅
		float width, height;
	};

	// データリスト
	extern std::vector<TextureData> texture_list;

	// 外部で管理予定
	// テクスチャデータID
	enum TextureID {
		TEST
	};

	// テクスチャ読み込み
	void Load(TextureID texture_id);
}

