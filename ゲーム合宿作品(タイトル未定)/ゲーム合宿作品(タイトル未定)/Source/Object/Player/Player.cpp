#include "Player.h"
#include "../Bullet/Bullet.h"

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
	// 壁との当たり判定
	// 右
	if (collision->IsHitBottomRight(m_pos.x, Window::WINDOW_W, m_half_texture_uv.x) == true) {
		m_pos.x -= m_speed;
	}
	// 左
	if (collision->IsHitTopLeft(m_pos.x, 0, m_half_texture_uv.x) == true) {
		m_pos.x += m_speed;
	}
	// 上
	if (collision->IsHitTopLeft(m_pos.y, 0, m_half_texture_uv.y) == true) {
		m_pos.y += m_speed;
	}
	// 下
	if (collision->IsHitBottomRight(m_pos.y, Window::WINDOW_H, m_half_texture_uv.y) == true) {
		m_pos.y -= m_speed;
	}
}
/*----更新----*/

/*----移動----*/
void Player::Move() {
	// 右
	if (KeyInput::GetKey(RIGHT_KEY) == true) {
		m_pos.x += m_speed;
	}
	// 左
	if (KeyInput::GetKey(LEFT_KEY) == true) {
		m_pos.x -= m_speed;
	}
	// 上
	if (KeyInput::GetKey(UP_KEY) == true) {
		m_pos.y -= m_speed;
	}
	// 下
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

