﻿#include "../../Lib/Draw2D/Draw2D.h"

#include "Bullet.h"

/*----public----*/
/*----コンストラクタ----*/
Bullet::Bullet(D3DXVECTOR2 object_pos) {
	m_info.pos = object_pos;
}
/*----コンストラクタ----*/
/*----public----*/

/*----private----*/
/*-----更新----*/
void Bullet::Update() {
	// 弾発射
	m_info.pos.y -= m_info.speed;
}
/*-----更新----*/

/*----描画----*/
void Bullet::Draw() {
	// テスト描画
	Draw2D::CenterOriginBox(ResourceManager::TEST3_ID, m_info.pos);
}
/*----描画----*/
/*----private----*/