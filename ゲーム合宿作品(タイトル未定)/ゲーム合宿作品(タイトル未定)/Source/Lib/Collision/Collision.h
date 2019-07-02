#pragma once

#include <d3dx9.h>

// 当たり判定クラス
class Collision {
public :
	// コンストラクタ
	Collision() {};
	// デストラクタ
	~Collision() {};
	/*----物体同士の当たり判定(中心原点)----*/

	// いい名前ありますかね

	// 右、下方向の当たり判定
	bool IsHitBottomRight(float pos1, float pos2, float half_texture_uv1 = 0, float half_texture_uv2 = 0);
	// 左、上方向の当たり判定
	bool IsHitTopLeft(float pos1, float pos2, float half_texture_uv1 = 0, float half_texture_uv2 = 0);
	/*----物体同士の当たり判定(中心原点)----*/
};

