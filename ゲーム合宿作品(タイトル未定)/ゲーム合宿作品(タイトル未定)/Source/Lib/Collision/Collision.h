#pragma once

#include <d3dx9.h>

// 当たり判定クラス
class Collision {
public :
	// コンストラクタ
	Collision() {};
	// デストラクタ
	~Collision() {};
	// 上壁、左辺の当たり判定
	bool IsHitTopOrLeftWall(float pos);
	// 下壁の当たり判定
	bool IsHitBottomWall(float pos);
	// 右辺壁の当たり判定
	bool IsHitRightWall(float pos);
	/*
		// 四角形同士の当たり判定
		第一引数 : 一つ目の四角形の左上頂点
		第二引数 : 一つ目の四角形の右下頂点
		第三引数 : 二つ目の四角形の左上頂点
		第四引数 : 二つ目の四角形の右下頂点
	*/
	bool IsHitSquares(
		D3DXVECTOR2 top_left_pos1, D3DXVECTOR2 bottom_right_pos1, 
		D3DXVECTOR2 top_left_pos2, D3DXVECTOR2 bottom_right_pos2);
};

