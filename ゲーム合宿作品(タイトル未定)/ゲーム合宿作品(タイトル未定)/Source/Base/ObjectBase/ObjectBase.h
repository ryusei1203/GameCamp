#pragma once

#include "../../Lib/D3D/D3D.h"
#include "../../Lib/Collision/Collision.h"

// オブジェクト基底
class ObjectBase {
public:
	// 四辺
	enum Side {
		RIGHT_SIDE,
		LEFT_SIDE,
		TOP_SIDE,
		BOTTOM_SIDE,

		MAX_SIDE_NUM
	};
	// 四頂点
	enum Vertex {
		TOP_RIGHT_VERTEX,
		TOP_LEFT_VERTEX,
		BOTTOM_RIGHT_VERTEX,
		BOTTOM_LEFT_VERTEX,

		MAX_VERTEX_NUM
	};
protected:
	/*----構造体----*/
	// 基礎情報
	struct Info {
		// 座標
		D3DXVECTOR2 pos;
		// 移動スピード
		float speed;
	};
	// 当たり判定用情報
	struct CollisionInfo {
		// 座標
		D3DXVECTOR2 pos[MAX_VERTEX_NUM];
		// 当たり判定
		bool is_hit_side[MAX_SIDE_NUM];
	};
	/*----構造体----*/
public:
	// コンストラクタ
	ObjectBase();
	// 更新
	virtual void Update() = 0;
	// 描画
	virtual void Draw() = 0;
	// デストラクタ
	virtual ~ObjectBase();
public:
	/*----ゲッター----*/
	// 基礎情報の取得
	Info GetInfo() {
		return m_info;
	}
	// 当たり判定用情報の取得
	CollisionInfo GetCollisionInfo() {
		return m_collision_info;
	}
	/*----ゲッター----*/
public:
	// 当たり判定のセッター
	void SetIsHit(bool is_hit,Side side) {
		m_collision_info.is_hit_side[side] = is_hit;
	}
protected:
	/*----変数----*/
	// テクスチャサイズ
	D3DXVECTOR2 m_texture_uv;
	// テクスチャサイズの半分
	D3DXVECTOR2 m_half_texture_uv;
	/*----変数----*/
protected:
	/*----インスタンス----*/
	// 当たり判定
	Collision *m_collision;
	// 基礎情報
	Info m_info;
	// 当たり判定用情報
	CollisionInfo m_collision_info;
	/*----インスタンス----*/
};

