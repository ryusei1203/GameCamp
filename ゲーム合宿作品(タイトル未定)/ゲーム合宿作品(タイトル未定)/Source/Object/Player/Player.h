#pragma once

#include "../../Base/PlayerBase/PlayerBase.h"

#include <vector>

// プレイヤー
class Player : public PlayerBase {
public:
	// コンストラクタ
	Player() {};
private:
	/*----関数----*/
	// 更新
	void Update()override;
	// 移動
	void Move();
	// 描画
	void Draw()override;
	// デストラクタ
	~Player() {};
	/*----関数----*/
private:
	/*----配列----*/
	// バレット実体化
	std::vector<ObjectBase*> bullet_list;
	/*----配列----*/
};

