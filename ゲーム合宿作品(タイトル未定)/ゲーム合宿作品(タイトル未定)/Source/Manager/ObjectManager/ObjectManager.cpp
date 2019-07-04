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
	//if(m_collision->IsHitRirghtSide(m_player->))
}
/*----コンストラクタ----*/

/*----更新----*/
void ObjectManager::Update() {
	// スクロール
	back_ground_pos.y += 1.f;
	// プレイヤー
	m_player->Update();
	// エネミー
	m_enemy->Update();
}
/*----更新----*/

/*----描画----*/
void ObjectManager::Draw() {
	// 背景描画
	Draw2D::UpperLeftOriginBox(ResourceManager::TEST4_ID, back_ground_pos);
	// プレイヤー
	m_player->Draw();
	// エネミー
	m_enemy->Draw();
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

