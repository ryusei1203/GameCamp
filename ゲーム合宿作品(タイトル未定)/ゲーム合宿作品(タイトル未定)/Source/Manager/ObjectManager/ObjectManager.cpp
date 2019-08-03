#include "ObjectManager.h"

#include "../../Object/Player/Player.h"
#include "../../Object/Enemy/Enemy.h"

#include "../../Lib/Draw2D/Draw2D.h"

/*----public----*/
/*----コンストラクタ----*/
ObjectManager::ObjectManager() :
	back_ground_pos({ 0.f,-2400.f + 600.f }) {
	// プレイヤー
	m_player = new Player();
	// エネミー
	m_enemy = new Enemy();
}
/*----コンストラクタ----*/

/*----更新----*/
void ObjectManager::Update() {
	// スクロール
	back_ground_pos.y += 1.f;
	// プレイヤー
	if (m_player != nullptr) {
		m_player->Update();
	}
	// エネミー
	if (m_enemy != nullptr) {
		m_enemy->Update();
	}
	// プレイヤーとエネミーの当たり判定
	if (m_player != nullptr && m_enemy != nullptr) {
		if (m_collision->IsHitSquares(
			m_player->GetCollisionInfo().pos[ObjectBase::TOP_LEFT_VERTEX], m_player->GetCollisionInfo().pos[ObjectBase::BOTTOM_RIGHT_VERTEX],
			m_enemy->GetCollisionInfo().pos[ObjectBase::TOP_LEFT_VERTEX], m_enemy->GetCollisionInfo().pos[ObjectBase::BOTTOM_RIGHT_VERTEX])
			== true) {
			// 接触したらエネミーが消える
			delete m_enemy;
			m_enemy = nullptr;
		}
	}

}
/*----更新----*/

/*----描画----*/
void ObjectManager::Draw() {
	// 背景描画
	Draw2D::UpperLeftOriginBox(ResourceManager::TEST4_ID, back_ground_pos);
	// プレイヤー
	if (m_player != nullptr) {
		m_player->Draw();
	}
	// エネミー
	if (m_enemy != nullptr) {
		m_enemy->Draw();
	}
}
/*----描画----*/

/*----デストラクタ----*/
ObjectManager::~ObjectManager() {
	// エネミー
	delete m_enemy;
	m_enemy = nullptr;
	// プレイヤー
	delete m_player;
	m_player = nullptr;
}
/*----デストラクタ----*/
/*----public----*/

