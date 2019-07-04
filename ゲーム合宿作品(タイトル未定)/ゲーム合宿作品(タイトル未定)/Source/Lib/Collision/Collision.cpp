#include "Collision.h"

#include "../../Lib/Window/Window.h"

/*----右辺当たり判定----*/
bool Collision::IsHitRirghtSide(
	D3DXVECTOR2 top_right_pos1, 
	D3DXVECTOR2 bottom_right_pos1, 
	D3DXVECTOR2 top_left_pos2, 
	D3DXVECTOR2 bottom_left_pos2) {
	if (top_right_pos1.x >= top_left_pos2.x
		&& bottom_right_pos1.x >= bottom_left_pos2.x
		&& top_right_pos1.y >= top_left_pos2.y
		&& bottom_right_pos1.y <= bottom_left_pos2.y) {
		return true;
	}
	return false;
}
/*----右辺当たり判定----*/

/*----左辺当たり判定----*/
bool Collision::IsHitLeftSide(
	D3DXVECTOR2 top_left_pos1, 
	D3DXVECTOR2 bottom_left_pos1, 
	D3DXVECTOR2 top_right_pos2, 
	D3DXVECTOR2 bottom_right_pos2) {
	if (top_left_pos1.x <= top_right_pos2.x 
		&& bottom_left_pos1.x <= bottom_right_pos2.x
		&& top_left_pos1.y >= top_right_pos2.y 
		&& bottom_left_pos1.y <= bottom_right_pos2.y) {
		return true;
	}
	return false;
}
/*----左辺当たり判定----*/

/*----上辺当たり判定----*/
bool Collision::IsHitTopSide(
	D3DXVECTOR2 top_left_pos1, 
	D3DXVECTOR2 top_right_pos1,
	D3DXVECTOR2 bottom_left_pos2, 
	D3DXVECTOR2 bottom_right_pos2) {
	if (top_left_pos1.x >= bottom_left_pos2.x
		&& top_right_pos1.x <= bottom_right_pos2.x
		&& top_left_pos1.y <= bottom_left_pos2.y
		&& top_right_pos1.y <= bottom_right_pos2.y) {
		return true;
	}
	return false;
}

/*----上辺当たり判定----*/

/*----下辺当たり判定----*/
bool Collision::IsHitBottomSide(
	D3DXVECTOR2 bottom_left_pos1, 
	D3DXVECTOR2 bottom_right_pos1,
	D3DXVECTOR2 top_left_pos2,
	D3DXVECTOR2 top_right_pos2) {
	if (bottom_left_pos1.x >= top_left_pos2.x
		&& bottom_right_pos1.x <= top_right_pos2.x
		&& bottom_left_pos1.y >= top_left_pos2.y
		&& bottom_right_pos1.y >= top_right_pos2.y) {
		return true;
	}
	return false;
}
/*----下辺当たり判定----*/

