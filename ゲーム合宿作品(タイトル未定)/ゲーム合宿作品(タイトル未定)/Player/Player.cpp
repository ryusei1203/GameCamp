#include "Player.h"
#include "../Lib/Draw2D/Draw2D.h"
#include "../ResourceManager/ResourceManager.h"

// 更新
void Player::Update() {

}

// 描画
void Player::Draw() {

	// テスト描画
	Draw2D::Box(ResourceManager::TEST1_ID, info.pos);
}
