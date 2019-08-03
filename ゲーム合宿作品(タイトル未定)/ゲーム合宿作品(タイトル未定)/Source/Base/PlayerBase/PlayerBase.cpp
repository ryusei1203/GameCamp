#include "PlayerBase.h"

// コンストラクタ
PlayerBase::PlayerBase() {
	// 座標(初期化)
	m_info.pos = { Window::WINDOW_W / 2,Window::WINDOW_H / 2 };
	// 速さ(初期化)
	m_info.speed = 5.f;
	// テクスチャサイズ
	m_info.texture_uv = ResourceManager::GetInstance().GetTextureData(ResourceManager::TEST1_ID).uv;
	// テクスチャサイズの半分
	m_collision_info.half_texture_uv = { m_info.texture_uv.x / 2,m_info.texture_uv.y / 2 };
};

