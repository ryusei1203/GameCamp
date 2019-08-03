#pragma once

#include "../../Base/PlayerBase/PlayerBase.h"
#include "../../Base/EnemyBase/EnemyBase.h"
#include "../../Base/BulletBase/BulletBase.h"

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
private:
	// エネミーインスタンス配列
	std::vector<EnemyBase*> enemy;
	EnemyBase *m_enemy;
private:
	/*----インスタンス----*/
	// プレイヤー
	PlayerBase *m_player;
	// 当たり判定
	Collision *m_collision;
	/*----インスタンス----*/
};

