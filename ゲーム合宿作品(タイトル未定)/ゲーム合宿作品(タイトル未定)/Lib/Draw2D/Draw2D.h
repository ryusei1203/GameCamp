#pragma once

#include "../Texture/Texture.h"

namespace Draw2D {

	// 頂点情報
	struct CustomVetrex {

		// 頂点情報
		float x, y, z;

		// 除算数
		float rhw;

		// 色
		DWORD dw_color;

		// テクスチャ座標
		float u, v;
	};

	// 四角形描画
	void Box(Texture::TextureID texture_id);
}

