#include "Texture.h"

#include <vector>

// テクスチャ情報
namespace Texture {
	TextureData texture;
	/*----テクスチャ読み込み----*/
	TextureData Load(char *file_name) {
		// テクスチャファイル読み込み
		if (D3DXCreateTextureFromFileA(
			// 読み込みで使用するデバイス
			D3D::dev,
			// ファイル名
			file_name,
			// 読み込まれたテクスチャの保存先
			&texture.texture
		) != D3D_OK) {


			// ここ何とかしたい


		}
		// テクスチャサイズ取得用
		D3DXIMAGE_INFO texture_info;
		// テクスチャサイズ取得
		if (D3DXGetImageInfoFromFileA(file_name, &texture_info) == D3D_OK) {
			// テクスチャサイズ代入
			texture.uv.x = (float)texture_info.Width;
			texture.uv.y = (float)texture_info.Height;
		}
		return texture;
	};
	/*----テクスチャ読み込み----*/

	/*----テクスチャ開放----*/
	void Release() {
		texture.texture->Release();
	}
	/*----テクスチャ開放----*/
}

