#pragma once

#include "../../Base/PlayerBase/PlayerBase.h"
#include "../../Base/EnemyBase/EnemyBase.h"

#include "../../Lib/Collision/Collision.h"

// オブジェクト管理
class ObjectManager {
public :
	// コンストラクタ
	ObjectManager();
	// 更新
	void Update();
	// 描画
	void Draw();
	// デストラクタ
	~ObjectManager();
private:
	// 背景座標
	D3DXVECTOR2 back_ground_pos;
	// プレイヤーインスタンス
	PlayerBase *player;
	// エネミーインスタンス
	EnemyBase *enemy;
	// 当たり判定インスタンス
	Collision *collision;
};

