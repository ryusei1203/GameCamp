#pragma once

#include "PlayerBase.h"

// プレイヤー
class Player : public PlayerBase {
public:
	// コンストラクタ
	Player() {};

private:
	// デストラクタ
	~Player() {};

	// 更新
	void Update()override;

	// 描画
	void Draw()override;
};