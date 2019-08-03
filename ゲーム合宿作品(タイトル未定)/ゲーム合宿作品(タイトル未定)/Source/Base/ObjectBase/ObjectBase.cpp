#include "ObjectBase.h"

// コンストラクタ
ObjectBase::ObjectBase() :
	m_collision(new Collision) {
	/*----基礎情報----*/
	// 座標
	m_info.pos = { 0.f, 0.f };
	// 移動スピード
	m_info.speed = 0.f;
	// テクスチャサイズ
	m_info.texture_uv = { 0.f,0.f };
	// 生存フラグ
	m_info.dead = false;
	/*----基礎情報----*/
	/*----当たり判定用情報----*/
	// 座標
	for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
		m_collision_info.pos[i] = { 0.f,0.f };
	}
	// 当たり判定
	m_collision_info.is_hit = false;
	// テクスチャサイズの半分
	m_collision_info.half_texture_uv = { 0.f,0.f };
	/*----当たり判定用情報----*/
}

// デストラクタ
ObjectBase::~ObjectBase() {
	delete m_collision;
	m_collision = nullptr;
};

// 当たり判定用座標更新
void ObjectBase::UpdateCollisionPos() {
	m_collision_info.pos[TOP_LEFT_VERTEX] = { m_info.pos.x - m_collision_info.half_texture_uv.x, m_info.pos.y - m_collision_info.half_texture_uv.y };
	m_collision_info.pos[BOTTOM_RIGHT_VERTEX] = { m_info.pos.x + m_collision_info.half_texture_uv.x, m_info.pos.y + m_collision_info.half_texture_uv.y };
}

