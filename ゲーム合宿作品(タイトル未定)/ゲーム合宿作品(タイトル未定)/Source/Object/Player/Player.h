#pragma once

#include "../../Base/PlayerBase/PlayerBase.h"

#include <vector>

// プレイヤー
class Player : public PlayerBase {
public:
	// コンストラクタ
	Player() {};
private:
	/*----更新関数----*/
	// 更新
	void Update()override;
	// 移動
	void Move();
	// 壁との当たり判定
	void CollisionWall();
	/*----更新関数----*/
private:
	// 描画
	void Draw()override;
private:
	// デストラクタ
	~Player() {};
};

