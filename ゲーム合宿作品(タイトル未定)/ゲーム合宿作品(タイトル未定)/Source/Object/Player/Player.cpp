#include "Player.h"
#include "../../Lib/Draw2D/Draw2D.h"
#include "../../Lib/KeyInput/KeyInput.h"
#include "../../Manager/ResourceManager/ResourceManager.h"

/*----private----*/
/*----更新----*/
void Player::Update() {
	// 右に移動
	if (KeyInput::GetKey(RIGHT_KEY) == true) {
		m_pos.x += 10.f;
	}
	if (KeyInput::GetKey(SPACE_KEY) == true) {

	}
}
/*----更新----*/

/*----描画----*/
void Player::Draw() {
	// テスト描画
	Draw2D::Box(ResourceManager::TEST1_ID, m_pos);
}
/*----描画----*/
/*----private----*/
