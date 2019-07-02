#include "Enemy.h"

#include "../../Lib/Draw2D/Draw2D.h"

/*----private----*/
/*----更新----*/
void Enemy::Update() {

}
/*----更新----*/

/*----描画----*/
void Enemy::Draw() {
	// テスト描画
	Draw2D::CenterOriginBox(ResourceManager::TEST2_ID, m_info.pos);
}
/*----描画----*/
/*----private----*/

