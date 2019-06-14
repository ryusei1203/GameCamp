#pragma once
#include "EnemyBase.h"

#include "Enemy.h"

// エネミー
class Enemy : public EnemyBase {

public :
	// コンストラクタ
	Enemy() {
		m_info.pos = { 64.f,64.f };
	};

private:
	// デストラクタ
	~Enemy() {};

	// 更新
	void Update()override;

	// 描画
	void Draw()override;
};