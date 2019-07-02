#pragma once
#include "../../Base/EnemyBase/EnemyBase.h"
#include "Enemy.h"

#include "../../Lib/Window/Window.h"

// エネミー
class Enemy : public EnemyBase {
public :
	// コンストラクタ
	Enemy() {
		// 座標(初期化)
		m_pos = { Window::WINDOW_W / 2,16.f };
	};
private:
	// デストラクタ
	~Enemy() {};
	// 更新
	void Update()override;
	// 描画
	void Draw()override;
};

