﻿#include "Enemy.h"
#include "../Lib/Draw2D/Draw2D.h"
#include "../ResourceManager/ResourceManager.h"

// 更新
void Enemy::Update() {

}

// 描画
void Enemy::Draw() {
	
	// テスト描画
	Draw2D::Box(ResourceManager::TEST2_ID, info.pos);
}

