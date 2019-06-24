#include "Player.h"
#include "../../Manager/ResourceManager/ResourceManager.h"
#include "../Bullet/Bullet.h"

#include "../../Lib/Draw2D/Draw2D.h"
#include "../../Lib/KeyInput/KeyInput.h"

/*----private----*/
/*----更新----*/
void Player::Update() {
	// 右に移動
	if (KeyInput::GetKey(RIGHT_KEY) == true) {
		m_pos.x += m_speed;
	}
	// 弾発射
	if (KeyInput::GetKeyDown(SPACE_KEY) == true) {
		bullet_list.push_back(new Bullet(m_pos));
	}
	// 弾更新
	for (auto bullet : bullet_list) {
		if (bullet != nullptr) {
			bullet->Update();
		}
	}
}
/*----更新----*/

/*----描画----*/
void Player::Draw() {
	// 弾描画
	for (auto bullet : bullet_list) {
		if (bullet != nullptr) {
			bullet->Draw();
		}
	}
	// テスト描画
	Draw2D::Box(ResourceManager::TEST1_ID, m_pos);
}
/*----描画----*/
/*----private----*/

