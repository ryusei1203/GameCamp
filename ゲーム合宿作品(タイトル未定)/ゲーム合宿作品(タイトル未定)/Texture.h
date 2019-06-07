#pragma once

#include <d3d9.h>
#include <d3dx9.h>

struct CUSTOM_VERTEX {

	// 頂点情報
	D3DXVECTOR2 pos;

	// 除算数
	float rhw;

	// テクスチャ座標
	D3DXVECTOR2 uv;
};

#define FVF_2D (D3DFVF_XYZRHW | D3DFVF_TEX1)



