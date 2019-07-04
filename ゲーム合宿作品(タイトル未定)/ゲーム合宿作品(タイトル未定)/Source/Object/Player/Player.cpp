#include "Player.h"
#include "../Bullet/Bullet.h"

#include "../../Lib/KeyInput/KeyInput.h"

/*----private----*/
/*----更新関数----*/
/*----更新----*/
void Player::Update() {
	// 移動
	Move();
	// 当たり判定用座標の更新
	m_collision_info.pos[TOP_RIGHT_VERTEX] = { m_info.pos.x + m_half_texture_uv.x, m_info.pos.y - m_half_texture_uv.y };
	m_collision_info.pos[TOP_LEFT_VERTEX] = { m_info.pos.x - m_half_texture_uv.x, m_info.pos.y - m_half_texture_uv.y };
	m_collision_info.pos[BOTTOM_RIGHT_VERTEX] = { m_info.pos.x + m_half_texture_uv.x, m_info.pos.y + m_half_texture_uv.y };
	m_collision_info.pos[BOTTOM_LEFT_VERTEX] = { m_info.pos.x - m_half_texture_uv.x, m_info.pos.y + m_half_texture_uv.y };
	// 壁との当たり判定
	CollisionWall();
	// 弾発射
	if (KeyInput::GetKeyDown(SPACE_KEY) == true) {
		m_bullet_list.push_back(new Bullet(m_info.pos));
	}
	// 弾更新
	for (auto bullet : m_bullet_list) {
		// NULLではないときに生成
		if (bullet != nullptr) {
			bullet->Update();
		}
	}
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
	// 右辺
	if (m_collision->IsHitRirghtSide(
		m_collision_info.pos[TOP_RIGHT_VERTEX], 
		m_collision_info.pos[BOTTOM_RIGHT_VERTEX],
		{ Window::WINDOW_W, 0 }, 
		{ Window::WINDOW_W, Window::WINDOW_H }) == true) {
		m_collision_info.is_hit_side[RIGHT_SIDE] = true;
		m_info.pos.x -= m_info.speed;
		m_collision_info.is_hit_side[RIGHT_SIDE] = false;
	}
	// 左辺
	if (m_collision->IsHitLeftSide(
		m_collision_info.pos[TOP_LEFT_VERTEX],
		m_collision_info.pos[BOTTOM_LEFT_VERTEX],
		{ 0, -1 }, 
		{ 0, Window::WINDOW_H })) {
		m_collision_info.is_hit_side[LEFT_SIDE] = true;
		m_info.pos.x += m_info.speed;
		m_collision_info.is_hit_side[LEFT_SIDE] = false;
	}
	// 上辺
	if (m_collision->IsHitTopSide(
		m_collision_info.pos[TOP_LEFT_VERTEX],
		m_collision_info.pos[TOP_RIGHT_VERTEX],
		{ -1, 0 }, 
		{ Window::WINDOW_W, 0 })) {
		m_collision_info.is_hit_side[TOP_SIDE] = true;
		m_info.pos.y += m_info.speed;
		m_collision_info.is_hit_side[TOP_SIDE] = false;
	}
	// 下辺
	if (m_collision->IsHitBottomSide(
		m_collision_info.pos[BOTTOM_LEFT_VERTEX],
		m_collision_info.pos[BOTTOM_RIGHT_VERTEX],
		{ 0, Window::WINDOW_H },
		{ Window::WINDOW_W, Window::WINDOW_H })) {
		m_collision_info.is_hit_side[BOTTOM_SIDE] = true;
		m_info.pos.y -= m_info.speed;
		m_collision_info.is_hit_side[BOTTOM_SIDE] = false;
	}
}
/*----壁との当たり判定----*/
/*----更新関数----*/

/*----描画----*/
void Player::Draw() {
	// 弾描画
	for (auto bullet : m_bullet_list) {
		// NULLではないときに描画
		if (bullet != nullptr) {
			bullet->Draw();
		}
	}
	// テスト描画
	Draw2D::CenterOriginBox(ResourceManager::TEST1_ID, m_info.pos);
}
/*----描画----*/
/*----private----*/

