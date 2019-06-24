﻿#include "Draw2D.h"

// 2D描画情報
namespace Draw2D {
	/*----四角形描画----*/
	/*
		第一引数 テクスチャID(ResourceManagerに記載)
		第二引数 座標(D3DXVECTOR2)(中心座標)
	*/
	void Box(ResourceManager::TextureID texture_id, D3DXVECTOR2 pos) {
		// TextureDataを取得
		Texture::TextureData texture = ResourceManager::GetInstance().GetTextureData(texture_id);
		// テクスチャの設定
		D3D::dev->SetTexture(
			// テクスチャステージの番号
			0,
			// 指定したいテクスチャ
			texture.texture
		);
		// 頂点バッファがどの頂点情報を指しているか
		D3D::dev->SetFVF(FVF_2D);
		// テクスチャ座標の半分
		D3DXVECTOR2 half_texture_uv{ (texture.uv.x / 2) ,(texture.uv.y / 2) };
		// 中心頂点
		D3DXVECTOR2 center_pos = pos;
		// 左上頂点
		D3DXVECTOR2 upper_left_pos{ center_pos.x - half_texture_uv.x , center_pos.y - half_texture_uv.y };
		// 右下頂点
		D3DXVECTOR2 lower_right_pos{ center_pos.x + half_texture_uv.x , center_pos.y + half_texture_uv.y };
		// 四角形の頂点
		CustomVetrex vertex[4] = {
			// 左上頂点 
			{{upper_left_pos.x, upper_left_pos.y, 0.f}, 1.f, 0xffffff, {0.f, 0.f} },
			// 右上頂点
			{{lower_right_pos.x, upper_left_pos.y, 0.f}, 1.f, 0xffffff, {0.f, 1.f} },
			// 右下頂点
			{{lower_right_pos.x, lower_right_pos.y, 0.f}, 1.f, 0xffffff, {1.f, 0.f} },
			// 左下頂点
			{{upper_left_pos.x, lower_right_pos.y, 0.f}, 1.f, 0xffffff, {1.f, 1.f} },
		};
		// 頂点の結び方とポリゴンの描画枚数の指定
		D3D::dev->DrawPrimitiveUP(
			// 頂点をどう結んでポリゴンにするか
			D3DPT_TRIANGLEFAN,
			// 描画するポリゴンの数
			2,
			// 描画するVertex配列の先頭ポインタ
			vertex,
			// Vertexの構造体サイズ
			sizeof(CustomVetrex)
		);
	}
	/*----四角形描画----*/
}

