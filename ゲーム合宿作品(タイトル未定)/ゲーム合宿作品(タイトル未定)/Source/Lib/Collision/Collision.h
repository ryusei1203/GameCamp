#pragma once

#include <d3dx9.h>

// 当たり判定クラス
class Collision {
public :
	// コンストラクタ
	Collision() {};
	// デストラクタ
	~Collision() {};
	// 右辺当たり判定
	/*
		第一引数 : オブジェクトの右上座標
		第二引数 : オブジェクトの右下座標
		第三引数 : 当たり判定を取りたいオブジェクトの左上座標
		第四引数 : 当たり判定を取りたいオブジェクトの左下座標
	*/
	bool IsHitRirghtSide(
		D3DXVECTOR2 top_right_pos1, 
		D3DXVECTOR2 bottom_right_pos1, 
		D3DXVECTOR2 top_left_pos2, 
		D3DXVECTOR2 bottom_left_pos2);
	// 左辺当たり判定
	/*
		第一引数 : オブジェクトの左上座標
		第二引数 : オブジェクトの左下座標
		第三引数 : 当たり判定を取りたいオブジェクトの右上座標
		第四引数 : 当たり判定を取りたいオブジェクトの右下座標
	*/
	bool IsHitLeftSide(
		D3DXVECTOR2 top_left_pos1, 
		D3DXVECTOR2 bottom_left_pos1, 
		D3DXVECTOR2 top_right_pos2, 
		D3DXVECTOR2 bottom_right_pos2);
	// 上辺当たり判定
	/*
		第一引数 : オブジェクトの左上座標
		第二引数 : オブジェクトの右上座標
		第三引数 : 当たり判定を取りたいオブジェクトの左下座標
		第四引数 : 当たり判定を取りたいオブジェクトの右下座標
	*/
	bool IsHitTopSide(
		D3DXVECTOR2 top_left_pos1, 
		D3DXVECTOR2 top_right_pos1,
		D3DXVECTOR2 bottom_left_pos2, 
		D3DXVECTOR2 bottom_right_pos2);
	// 下辺当たり判定
	/*
		第一引数 : オブジェクトの左下座標
		第二引数 : オブジェクトの右下座標
		第三引数 : 当たり判定を取りたいオブジェクトの左上座標
		第四引数 : 当たり判定を取りたいオブジェクトの右上座標
	*/
	bool IsHitBottomSide(
		D3DXVECTOR2 bottom_left_pos1, 
		D3DXVECTOR2 bottom_right_pos1,
		D3DXVECTOR2 top_left_pos2, 
		D3DXVECTOR2 top_right_pos2);
};

