#include "Draw2D.h"
#include "D3D.h"

namespace Draw2D {

	/*----四角形描画----*/
	void Box(Texture::TextureID texture_id) {

		// テクスチャの設定
		D3D::dev->SetTexture(
			// テクスチャステージの番号
			0,
			// 指定したいテクスチャ
			Texture::texture_list[texture_id].texture
		);

		// 頂点バッファがどの頂点情報を指しているか
		D3D::dev->SetFVF(FVF_2D);

		CustomVetrex custom_vertex[4] = {
			// 左上頂点 
			{0.f,0.f,0.f,1.f,0xffffff,0.f,0.f },
			// 右上頂点
			{Texture::texture_list[texture_id].width,0.f,0.f,1.f,0xffffff,0.f,1.f },
			// 右下頂点
			{Texture::texture_list[texture_id].width,Texture::texture_list[texture_id].height,0.f,1.f,0xffffff,1.f,0.f },
			// 左下頂点
			{0.f,Texture::texture_list[texture_id].height,0.f,1.f,0xffffff,1.f,1.f },
		};

		// 頂点の結び方とポリゴンの描画枚数の指定
		D3D::dev->DrawPrimitiveUP(
			// 頂点をどう結んでポリゴンにするか
			D3DPT_TRIANGLEFAN,
			// 描画するポリゴンの数
			2,
			// 描画するVertex配列の先頭ポインタ
			custom_vertex,
			// Vertexの構造体サイズ
			sizeof(CustomVetrex)
		);
	}
	/*----四角形描画----*/
}