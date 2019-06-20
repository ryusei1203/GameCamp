#include "../../Object/Player/Player.h"
#include "../../Object/Enemy/Enemy.h"
#include "ObjectManager.h"

/*----public----*/
/*----コンストラクタ----*/
ObjectManager::ObjectManager() {

	// プレイヤー
	player = new Player();
	// エネミー
	enemy = new Enemy();
}
/*----コンストラクタ----*/

/*----更新----*/
void ObjectManager::Update() {
	// プレイヤー
	player->Update();
	// エネミー
	enemy->Update();
}
/*----更新----*/

/*----描画----*/
void ObjectManager::Draw() {
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

