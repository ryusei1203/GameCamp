#pragma once

#include "../../Lib/Window/Window.h"

#include "../ObjectBase/ObjectBase.h"

// プレイヤー基底
class PlayerBase : public ObjectBase {
public:
	// コンストラクタ
	PlayerBase() {
		// 座標(初期化)
		m_pos = { Window::WINDOW_W / 2,Window::WINDOW_H / 2 };
		// 速さ(初期化)
		m_speed = 5.f;
	};
	// デストラクタ
	~PlayerBase() {};
private:
};

