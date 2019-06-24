#pragma once

#include "../../Base/BulletBase/BulletBase.h"

// バレット
class Bullet : public BulletBase {
public:
	// コンストラクタ
	Bullet(D3DXVECTOR2 object_pos);
private:
	// デストラクタ
	~Bullet() {};
	// 更新
	void Update()override;
	// 描画
	void Draw()override;
};