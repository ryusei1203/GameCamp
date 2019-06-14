#pragma once

#include "../Texture/Texture.h"
#include "../../ResourceManager/ResourceManager.h"

// 2D描画情報
namespace Draw2D {

	// 頂点情報
	struct CustomVetrex {

		// 頂点情報
		D3DXVECTOR3 pos;

		// 除算数
		float rhw;

		// 色
		DWORD dw_color;

		// テクスチャ座標
		D3DXVECTOR2 uv;
	};

	// 四角形描画
	void Box(ResourceManager::TextureID texture_id, D3DXVECTOR2 pos);
}

