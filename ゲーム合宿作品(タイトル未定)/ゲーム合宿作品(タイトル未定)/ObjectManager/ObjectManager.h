#pragma once

#include "../ObjectBase/ObjectBase.h"

// オブジェクト管理
class ObjectManager {
public :
	// コンストラクタ
	ObjectManager();

	// デストラクタ
	~ObjectManager();

	// 更新
	void Update();

	// 描画
	void Draw();

private:

	ObjectBase *player;
	ObjectBase *enemy;
};