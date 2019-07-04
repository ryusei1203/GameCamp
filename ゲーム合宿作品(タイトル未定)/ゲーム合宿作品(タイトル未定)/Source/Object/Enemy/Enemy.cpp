#include "Enemy.h"

#include "../../Lib/Draw2D/Draw2D.h"

/*----private----*/
/*----更新----*/
void Enemy::Update() {
	// 当たり判定用座標の更新
	m_collision_info.pos[TOP_RIGHT_VERTEX] = { m_info.pos.x + m_half_texture_uv.x, m_info.pos.y - m_half_texture_uv.y };
	m_collision_info.pos[TOP_LEFT_VERTEX] = { m_info.pos.x - m_half_texture_uv.x, m_info.pos.y - m_half_texture_uv.y };
	m_collision_info.pos[BOTTOM_RIGHT_VERTEX] = { m_info.pos.x + m_half_texture_uv.x, m_info.pos.y + m_half_texture_uv.y };
	m_collision_info.pos[BOTTOM_LEFT_VERTEX] = { m_info.pos.x - m_half_texture_uv.x, m_info.pos.y + m_half_texture_uv.y };
}
/*----更新----*/

/*----描画----*/
void Enemy::Draw() {
	// テスト描画
	Draw2D::CenterOriginBox(ResourceManager::TEST2_ID, m_info.pos);
}
/*----描画----*/
/*----private----*/

