#include "ObjectBase.h"

// コンストラクタ
ObjectBase::ObjectBase() :
	m_texture_uv({ 0.f, 0.f }),
	m_half_texture_uv({ 0.f, 0.f }),
	m_collision(new Collision) {
	/*----基礎情報----*/
	// 座標
	m_info.pos = { 0.f, 0.f };
	// 移動スピード
	m_info.speed = 0.f;
	/*----基礎情報----*/
	/*----当たり判定用情報----*/
	// 座標
	for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
		m_collision_info.pos[i] = { 0.f,0.f };
	}
	// 当たり判定
	for (int i = 0; i < MAX_SIDE_NUM; ++i) {
		m_collision_info.is_hit_side[i] = false;
	}
	/*----当たり判定用情報----*/
}

// デストラクタ
ObjectBase::~ObjectBase() {
	delete m_collision;
	m_collision = nullptr;
};

