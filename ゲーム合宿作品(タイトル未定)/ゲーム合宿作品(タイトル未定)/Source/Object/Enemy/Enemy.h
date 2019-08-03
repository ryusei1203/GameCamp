#pragma once
#include "Enemy.h"
#include "../../Base/EnemyBase/EnemyBase.h"
#include "../../Manager/ResourceManager/ResourceManager.h"

#include "../../Lib/Window/Window.h"

// エネミー
class Enemy : public EnemyBase {
public :
	// コンストラクタ
	Enemy() {
		// 座標
		m_info.pos = { Window::WINDOW_W / 2,16.f };
		// テクスチャサイズ
		m_info.texture_uv = ResourceManager::GetInstance().GetTextureData(ResourceManager::TEST2_ID).uv;
		// テクスチャサイズの半分
		m_collision_info.half_texture_uv = { m_info.texture_uv.x, m_info.texture_uv.y };
	};
private:
	// デストラクタ
	~Enemy() {};
	// 更新
	void Update()override;
	// 描画
	void Draw()override;
};

