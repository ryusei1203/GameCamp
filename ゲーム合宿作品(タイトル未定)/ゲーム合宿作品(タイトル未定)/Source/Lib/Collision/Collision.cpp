#include "Collision.h"

#include "../../Lib/Window/Window.h"

/*----物体同士の当たり判定(中心原点)----*/
/*----右、下の当たり判定----*/
bool Collision::IsHitBottomRight(float pos1, float pos2, float half_texture_uv1, float half_texture_uv2) {
	if (pos1 + half_texture_uv1 > pos2 + half_texture_uv2) {
		return true;
	}
	return false;
}
/*----右、下の当たり判定----*/

/*----左、上方向の当たり判定----*/
bool Collision::IsHitTopLeft(float pos1, float pos2, float half_texture_uv1, float half_texture_uv2) {
	if (pos1 - half_texture_uv1 < pos2 - half_texture_uv2) {
		return true;
	}
	return false;
}
/*----左、上方向の当たり判定----*/
/*----物体同士の当たり判定(中心原点)----*/

