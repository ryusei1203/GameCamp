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
	UpdateCollisionPos();
	// 壁との当たり判定
	CollisionWall();
	// バレット発射(生成)
	if (KeyInput::GetKeyDown(SPACE_KEY) == true) {
		m_bullet_list.push_back(new Bullet(m_info.pos));
	}
	// バレット更新
	for (auto bullet : m_bullet_list) {
		if (bullet != nullptr) {
			bullet->Update();
			// バレットが画面外に出たら削除
			/*if (m_collision->IsHitTopOrLeftWall(bullet->GetCollisionInfo().pos[TOP_LEFT_VERTEX].y)) {
				delete bullet;
				bullet = nullptr;
			}*/
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
	// 上辺との当たり判定
	if(m_collision->IsHitTopOrLeftWall(m_collision_info.pos[TOP_LEFT_VERTEX].y) == true) {
		m_info.pos.y += m_info.speed;
	}
	// 下辺との当たり判定
	if (m_collision->IsHitBottomWall(m_collision_info.pos[BOTTOM_RIGHT_VERTEX].y) == true) {
		m_info.pos.y -= m_info.speed;
	}
	// 右辺との当たり判定
	if (m_collision->IsHitRightWall(m_collision_info.pos[BOTTOM_RIGHT_VERTEX].x) == true) {
		m_info.pos.x -= m_info.speed;
	}
	// 左辺との当たり判定
	if (m_collision->IsHitTopOrLeftWall(m_collision_info.pos[TOP_LEFT_VERTEX].x) == true) {
		m_info.pos.x += m_info.speed;
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

