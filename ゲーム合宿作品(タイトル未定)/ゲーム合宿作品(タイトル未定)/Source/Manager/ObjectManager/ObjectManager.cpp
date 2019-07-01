#include "../../Object/Player/Player.h"
#include "../../Object/Enemy/Enemy.h"
#include "ObjectManager.h"

#include "../../Lib/Draw2D/Draw2D.h"

/*----public----*/
/*----コンストラクタ----*/
ObjectManager::ObjectManager() : 
	back_ground_pos({0.f,-2400.f+600.f}) {
	// プレイヤー
	player = new Player();
	// エネミー
	enemy = new Enemy();
}
/*----コンストラクタ----*/

/*----更新----*/
void ObjectManager::Update() {
	// スクロール
	back_ground_pos.y += 1.f;
	// プレイヤー
	player->Update();
	// エネミー
	enemy->Update();
}
/*----更新----*/

/*----描画----*/
void ObjectManager::Draw() {
	// 背景描画
	Draw2D::UpperLeftOriginBox(ResourceManager::TEST4_ID, back_ground_pos);
	// プレイヤー
	player->Draw();
	// エネミー
	enemy->Draw();
}
/*----描画----*/

/*----デストラクタ----*/
ObjectManager::~ObjectManager() {
	// エネミー
	delete enemy;
	enemy = nullptr;
	// プレイヤー
	delete player;
	player = nullptr;
}
/*----デストラクタ----*/
/*----public----*/

