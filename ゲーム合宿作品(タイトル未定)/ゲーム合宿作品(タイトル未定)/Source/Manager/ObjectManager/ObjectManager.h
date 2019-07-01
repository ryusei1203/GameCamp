#pragma once

#include "../../Base/ObjectBase/ObjectBase.h"

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
	ObjectBase *player;
	// エネミーインスタンス
	ObjectBase *enemy;
};

