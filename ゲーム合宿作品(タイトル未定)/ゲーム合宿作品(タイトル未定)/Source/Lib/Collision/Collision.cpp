#include "Collision.h"

#include "../../Lib/Window/Window.h"

/*----上壁、左壁の当たり判定----*/
bool Collision::IsHitTopOrLeftWall(float pos) {
	if (pos <= 0) {
		return true;
	}
	return false;
}
/*----上壁、左壁の当たり判定----*/

/*----下壁の当たり判定----*/
bool Collision::IsHitBottomWall(float pos) {
	if (pos >= Window::WINDOW_H) {
		return true;
	}
	return false;
}
/*----下壁の当たり判定----*/

/*----右壁の当たり判定----*/
bool Collision::IsHitRightWall(float pos) {
	if (pos >= Window::WINDOW_W) {
		return true;
	}
	return false;
}
/*----右壁の当たり判定----*/

/*----四角形同士の当たり判定----*/
bool Collision::IsHitSquares(
	D3DXVECTOR2 top_left_pos1, D3DXVECTOR2 bottom_right_pos1,
	D3DXVECTOR2 top_left_pos2, D3DXVECTOR2 bottom_right_pos2) {
	if (top_left_pos1.x <= bottom_right_pos2.x
		&& top_left_pos2.x <= bottom_right_pos1.x
		&& top_left_pos1.y <= bottom_right_pos2.y
		&& top_left_pos2.y <= bottom_right_pos1.y) {
		return true;
	}
	return false;
}
/*----四角形同士の当たり判定----*/

