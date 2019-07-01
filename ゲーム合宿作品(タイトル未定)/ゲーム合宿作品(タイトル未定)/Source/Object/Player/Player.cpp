﻿#include "Player.h"
#include "../Bullet/Bullet.h"

#include "../../Lib/Draw2D/Draw2D.h"
#include "../../Lib/KeyInput/KeyInput.h"

/*----private----*/
/*----更新----*/
void Player::Update() {
	// 移動
	Move();
	// 弾発射
	if (KeyInput::GetKeyDown(SPACE_KEY) == true) {
		bullet_list.push_back(new Bullet(m_pos));
	}
	// 弾更新
	for (auto bullet : bullet_list) {
		if (bullet != nullptr) {
			bullet->Update();
		}
	}
}
/*----更新----*/

/*----移動----*/
void Player::Move() {
	// 右に移動
	if (KeyInput::GetKey(RIGHT_KEY) == true) {
		m_pos.x += m_speed;
	}
	// 左に移動
	if (KeyInput::GetKey(LEFT_KEY) == true) {
		m_pos.x -= m_speed;
	}
	// 上に移動
	if (KeyInput::GetKey(UP_KEY) == true) {
		m_pos.y -= m_speed;
	}
	// 下に移動
	if (KeyInput::GetKey(DOWN_KEY) == true) {
		m_pos.y += m_speed;
	}
}
/*----移動----*/

/*----描画----*/
void Player::Draw() {
	// 弾描画
	for (auto bullet : bullet_list) {
		if (bullet != nullptr) {
			bullet->Draw();
		}
	}
	// テスト描画
	Draw2D::CenterOriginBox(ResourceManager::TEST1_ID, m_pos);
}
/*----描画----*/
/*----private----*/

