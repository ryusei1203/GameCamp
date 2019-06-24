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
	// プレイヤーインスタンス
	ObjectBase *player;
	// エネミーインスタンス
	ObjectBase *enemy;
};

