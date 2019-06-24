#pragma once

#include "../../Lib/D3D/D3D.h"

// オブジェクト基底
class ObjectBase {
public:
	// コンストラクタ
	ObjectBase() :
		m_pos({0.f,0.f}),
		m_speed(0.f)
	{};
	// 更新
	virtual void Update() = 0;
	// 描画
	virtual void Draw() = 0;
	// デストラクタ
	virtual ~ObjectBase() {};
protected:
	// 座標
	D3DXVECTOR2 m_pos;
	// 速さ
	float m_speed;
	//// 基本情報
	//struct Info {
	//	// 座標
	//	D3DXVECTOR2 pos;
	//};
	//Info m_info;
};

