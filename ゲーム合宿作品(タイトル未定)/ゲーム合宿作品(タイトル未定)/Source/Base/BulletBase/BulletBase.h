#pragma once

#include "../ObjectBase/ObjectBase.h"

// バレット基底
class BulletBase : public ObjectBase {
public:
	// コンストラクタ
	BulletBase() {
		// 速さ(初期化)
		m_info.speed = 10.f;
	};
	// デストラクタ
	~BulletBase() {};
private:

};

