#include "Player.h"
#include "../Lib/Draw2D/Draw2D.h"
#include "../ResourceManager/ResourceManager.h"
#include "../Lib/KeyInput/KeyInput.h"
/*----更新----*/
void Player::Update() {
	if (KeyInput::GetKey(RIGHT_KEY) == true) {
		m_pos.x += 10.f;
	}
}
/*----更新----*/

/*----描画----*/
void Player::Draw() {
	// テスト描画
	Draw2D::Box(ResourceManager::TEST1_ID, m_pos);
}
/*----描画----*/
