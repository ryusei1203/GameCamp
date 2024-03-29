﻿#pragma once

#include "../Texture/Texture.h"
#include "../../../Source/Manager/ResourceManager/ResourceManager.h"

// 2D描画情報
namespace Draw2D {
	// 頂点情報
	struct CustomVetrex {
		// 頂点情報+除算数
		D3DXVECTOR4 pos;
		// 色
		DWORD dw_color;
		// テクスチャ座標
		D3DXVECTOR2 uv;
	};
	// 四角形描画(中心原点)
	/*
	第一引数 : テクスチャID(ResourceManagerに記載)
	第二引数 : 座標(D3DXVECTOR2)(中心座標)
	*/
	void CenterOriginBox(ResourceManager::TextureID texture_id, D3DXVECTOR2 pos);
	// 四角形描画(左上原点)
	/*
	第一引数 : テクスチャID(ResourceManagerに記載)
	第二引数 : 座標(D3DXVECTOR2)(中心座標)
	*/
	void UpperLeftOriginBox(ResourceManager::TextureID texture_id, D3DXVECTOR2 pos);
}

