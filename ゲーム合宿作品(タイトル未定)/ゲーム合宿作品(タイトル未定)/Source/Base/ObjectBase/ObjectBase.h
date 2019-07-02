#pragma once

#include "../../Lib/D3D/D3D.h"
#include "../../Lib/Collision/Collision.h"

// オブジェクト基底
class ObjectBase {
protected:
	// enum
	// 4辺
	enum Side {
		TOP,
		RIGHT,
		BOTTOM,
		LEFT,

		MAX_SIDE_NUM
	};
protected:
	// 基礎情報
	struct Info {
		// 座標
		D3DXVECTOR2 pos;
		// 移動スピード
		float speed;
		// テクスチャサイズの半分
		D3DXVECTOR2 half_texture_uv;
		// 4辺の当たり判定
		bool is_hit[MAX_SIDE_NUM];
	};
public:
	// コンストラクタ
	ObjectBase() :
		m_texture_uv({ 0.f, 0.f }),
		m_side(TOP),
		m_collision(new Collision){
		/*----基礎情報----*/
		// 座標
		m_info.pos = { 0.f, 0.f };
		// 移動スピード
		m_info.speed = 0.f;
		// テクスチャサイズの半分
		m_info.half_texture_uv = { 0.f,0.f };
		// 4面の当たり判定
		for (int i = 0; i < MAX_SIDE_NUM; ++i) {
			m_info.is_hit[i] = false;
		}
		/*----基礎情報----*/
	};
	// 更新
	virtual void Update() = 0;
	// 描画
	virtual void Draw() = 0;
	// デストラクタ
	virtual ~ObjectBase() {
		delete m_collision;
		m_collision = nullptr;	
	};
	/*----ゲッター----*/
	// 辺の取得
	Side GetSide() {
		return m_side;
	}
	// 基礎情報の取得
	Info GetInfo() {
		return m_info;
	}
	/*----ゲッター----*/
protected:
	/*----変数----*/
	// テクスチャサイズ
	D3DXVECTOR2 m_texture_uv;
	/*----変数----*/
protected:
	// 四面当たり判定配列
	bool m_is_hit[MAX_SIDE_NUM];
protected:
	/*----インスタンス----*/
	// 4辺
	Side m_side;
	// 当たり判定
	Collision *m_collision;
	// 基礎情報
	Info m_info;
	/*----インスタンス----*/
};

