#pragma once

#include "../ObjectBase/ObjectBase.h"
#include "../../Base/BulletBase/BulletBase.h"

#include "../../Lib/Window/Window.h"
#include "../../Lib/Draw2D/Draw2D.h"

// プレイヤー基底
class PlayerBase : public ObjectBase {
private:
public:
	// コンストラクタ
	PlayerBase();
	// デストラクタ
	~PlayerBase() {};
protected:
	// 配列
	// バレットインスタンス
	std::vector<BulletBase*> m_bullet_list;
};

