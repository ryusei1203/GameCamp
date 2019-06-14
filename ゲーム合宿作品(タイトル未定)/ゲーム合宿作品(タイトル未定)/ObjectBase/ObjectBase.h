#pragma once

#include "../Lib/D3D/D3D.h"

// オブジェクト基底
class ObjectBase {

public:
	// コンストラクタ
	ObjectBase(){
		m_info.pos = { 0.f,0.f };
	};
	
	// デストラクタ
	virtual ~ObjectBase() {};

	// 更新
	virtual void Update() = 0;

	// 描画
	virtual void Draw() = 0;

private:

	// 
	struct Info {

		D3DXVECTOR2 pos;
	};

protected:

	Info m_info;
};

