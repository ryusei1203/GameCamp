#pragma once

#include "../ObjectBase/ObjectBase.h"

#include "../../Lib/Window/Window.h"
#include "../../Lib/Draw2D/Draw2D.h"

// プレイヤー基底
class PlayerBase : public ObjectBase {
public:
	// コンストラクタ
	PlayerBase() : 
		m_texture_uv(ResourceManager::GetInstance().GetTextureData(ResourceManager::TEST1_ID).uv),
		m_half_texture_uv({ m_texture_uv.x / 2,m_texture_uv.y / 2 }){
		// 座標(初期化)
		m_pos = { Window::WINDOW_W / 2,Window::WINDOW_H / 2 };
		// 速さ(初期化)
		m_speed = 5.f;
	};
	// デストラクタ
	~PlayerBase() {};
protected:
	// テクスチャサイズ
	D3DXVECTOR2 m_texture_uv;
	// テクスチャサイズの半分
	D3DXVECTOR2 m_half_texture_uv;
};

