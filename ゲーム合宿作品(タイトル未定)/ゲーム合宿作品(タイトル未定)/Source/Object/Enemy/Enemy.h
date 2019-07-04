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
		// 座標(初期化)
		m_info.pos = { Window::WINDOW_W / 2,16.f };
		m_texture_uv = ResourceManager::GetInstance().GetTextureData(ResourceManager::TEST2_ID).uv;
		m_half_texture_uv = { m_texture_uv.x, m_texture_uv.y };
	};
private:
	// デストラクタ
	~Enemy() {};
	// 更新
	void Update()override;
	// 描画
	void Draw()override;
};

