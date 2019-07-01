#pragma once
#include "../../Base/EnemyBase/EnemyBase.h"

#include "Enemy.h"

// エネミー
class Enemy : public EnemyBase {
public :
	// コンストラクタ
	Enemy() {
		// 座標(初期化)
		m_pos = { 16.f,16.f };
	};
private:
	// デストラクタ
	~Enemy() {};
	// 更新
	void Update()override;
	// 描画
	void Draw()override;
};

