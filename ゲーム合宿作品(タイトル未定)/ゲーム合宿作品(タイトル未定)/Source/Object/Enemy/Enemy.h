#pragma once
#include "../../Base/EnemyBase/EnemyBase.h"

#include "Enemy.h"

// エネミー
class Enemy : public EnemyBase {
public :
	// コンストラクタ
	Enemy() {
		m_pos = { 32.f,32.f };
	};
private:
	// デストラクタ
	~Enemy() {};
	// 更新
	void Update()override;
	// 描画
	void Draw()override;
};

