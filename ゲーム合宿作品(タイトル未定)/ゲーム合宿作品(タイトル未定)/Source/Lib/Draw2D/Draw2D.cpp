#include "Draw2D.h"

// 2D描画情報
namespace Draw2D {
	/*----四角形描画----*/
	/*----中心原点----*/
	void CenterOriginBox(ResourceManager::TextureID texture_id, D3DXVECTOR2 pos) {
		// TextureDataを取得
		Texture::TextureData texture_data = ResourceManager::GetInstance().GetTextureData(texture_id);
		// テクスチャ座標の半分
		D3DXVECTOR2 half_texture_uv{ (texture_data.uv.x / 2) ,(texture_data.uv.y / 2) };
		// 中心頂点
		D3DXVECTOR2 center_pos = pos;
		// 左上頂点
		D3DXVECTOR2 upper_left_pos{ center_pos.x - half_texture_uv.x , center_pos.y - half_texture_uv.y };
		// 右下頂点
		D3DXVECTOR2 lower_right_pos{ center_pos.x + half_texture_uv.x , center_pos.y + half_texture_uv.y };
		// 四角形の頂点
		CustomVetrex vertex[4] = {
			// 左上頂点
			{{upper_left_pos.x, upper_left_pos.y, 0.f, 1.f}, 0xffffff, {0.f, 0.f} },
			// 右上頂点
			{{lower_right_pos.x, upper_left_pos.y, 0.f, 1.f}, 0xffffff, {1.f, 0.f} },
			// 右下頂点
			{{lower_right_pos.x, lower_right_pos.y, 0.f, 1.f}, 0xffffff, {1.f, 1.f} },
			// 左下頂点
			{{upper_left_pos.x, lower_right_pos.y, 0.f, 1.f}, 0xffffff, {0.f, 1.f} },
		};
		// 頂点バッファがどの頂点情報を指しているか
		D3D::dev->SetFVF(FVF_2D);
		// テクスチャの設定
		D3D::dev->SetTexture(
			// テクスチャステージの番号
			0,
			// 指定したいテクスチャ
			texture_data.texture
		);
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
	/*----中心原点----*/

	/*----左上原点----*/
	void UpperLeftOriginBox(ResourceManager::TextureID texture_id, D3DXVECTOR2 pos) {
		// TextureDataを取得
		Texture::TextureData texture_data = ResourceManager::GetInstance().GetTextureData(texture_id);
		// 左上頂点
		D3DXVECTOR2 upper_left_pos = pos;
		// 右下頂点
		D3DXVECTOR2 lower_right_pos{ pos.x + texture_data.uv.x , pos.y + texture_data.uv.y };
		// 四角形の頂点
		CustomVetrex vertex[4] = {
			// 左上頂点
			{{upper_left_pos.x, upper_left_pos.y, 0.f, 1.f}, 0xffffff, {0.f, 0.f} },
			// 右上頂点
			{{lower_right_pos.x, upper_left_pos.y, 0.f, 1.f}, 0xffffff, {1.f, 0.f} },
			// 右下頂点
			{{lower_right_pos.x, lower_right_pos.y, 0.f, 1.f}, 0xffffff, {1.f, 1.f} },
			// 左下頂点
			{{upper_left_pos.x, lower_right_pos.y, 0.f, 1.f}, 0xffffff, {0.f, 1.f} },
		};
		// 頂点バッファがどの頂点情報を指しているか
		D3D::dev->SetFVF(FVF_2D);
		// テクスチャの設定
		D3D::dev->SetTexture(
			// テクスチャステージの番号
			0,
			// 指定したいテクスチャ
			texture_data.texture
		);
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
	/*----左上原点----*/
}

