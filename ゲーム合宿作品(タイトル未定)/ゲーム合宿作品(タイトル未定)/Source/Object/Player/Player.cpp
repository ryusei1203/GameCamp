#include "Player.h"
#include "../Bullet/Bullet.h"

#include "../../Lib/KeyInput/KeyInput.h"

/*----private----*/
/*----更新関数----*/
/*----更新----*/
void Player::Update() {
	// 移動
	Move();
	// 壁との当たり判定
	CollisionWall();
	// 弾発射
	if (KeyInput::GetKeyDown(SPACE_KEY) == true) {
		m_bullet_list.push_back(new Bullet(m_info.pos));
	}
	// 弾更新
	for (auto bullet : m_bullet_list) {
		if (bullet != nullptr) {
			bullet->Update();
		}
	}
	// 敵との当たり判定

}
/*----更新----*/

/*----移動----*/
void Player::Move() {
	// 右
	if (KeyInput::GetKey(RIGHT_KEY) == true) {
		m_info.pos.x += m_info.speed;
	}
	// 左
	if (KeyInput::GetKey(LEFT_KEY) == true) {
		m_info.pos.x -= m_info.speed;
	}
	// 上
	if (KeyInput::GetKey(UP_KEY) == true) {
		m_info.pos.y -= m_info.speed;
	}
	// 下
	if (KeyInput::GetKey(DOWN_KEY) == true) {
		m_info.pos.y += m_info.speed;
	}
}
/*----移動----*/

/*----壁との当たり判定----*/
void Player::CollisionWall() {
	// 右
	if (m_collision->IsHitBottomRight(m_info.pos.x, Window::WINDOW_W, m_info.half_texture_uv.x) == true) {
		m_info.pos.x -= m_info.speed;
	}
	// 左
	if (m_collision->IsHitTopLeft(m_info.pos.x, 0, m_info.half_texture_uv.x) == true) {
		m_info.pos.x += m_info.speed;
	}
	// 上
	if (m_collision->IsHitTopLeft(m_info.pos.y, 0, m_info.half_texture_uv.y) == true) {
		m_info.pos.y += m_info.speed;
	}
	// 下
	if (m_collision->IsHitBottomRight(m_info.pos.y, Window::WINDOW_H, m_info.half_texture_uv.y) == true) {
		m_info.pos.y -= m_info.speed;
	}
}
/*----壁との当たり判定----*/
/*----更新関数----*/

/*----描画----*/
void Player::Draw() {
	// 弾描画
	for (auto bullet : m_bullet_list) {
		if (bullet != nullptr) {
			bullet->Draw();
		}
	}
	// テスト描画
	Draw2D::CenterOriginBox(ResourceManager::TEST1_ID, m_info.pos);
}
/*----描画----*/
/*----private----*/

