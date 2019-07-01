#include "Texture.h"

#include <vector>

// テクスチャ情報
namespace Texture {
	TextureData texture_data;
	/*----テクスチャ読み込み----*/
	TextureData Load(char *file_name) {
		// テクスチャファイル読み込み
		if (D3DXCreateTextureFromFile(
			// 読み込みで使用するデバイス
			D3D::dev,
			// ファイル名
			file_name,
			// 読み込まれたテクスチャの保存先
			&texture_data.texture
		) == D3D_OK) {
			// テクスチャサイズ取得
			D3DXIMAGE_INFO texture_info;
			if (D3DXGetImageInfoFromFile(
				// ファイル名
				file_name,
				// テクスチャサイズ保存先
				&texture_info
			) == D3D_OK) {
				// テクスチャサイズ代入
				texture_data.uv.x = (float)texture_info.Width;
				texture_data.uv.y = (float)texture_info.Height;
			}
			//// テクスチャサイズ取得
			//D3DSURFACE_DESC desc;
			//if (texture_data.texture->GetLevelDesc(0, &desc) == D3D_OK) {
			//	// テクスチャサイズ代入
			//	texture_data.uv.x = (float)desc.Width;
			//	texture_data.uv.y = (float)desc.Height;
			//}
			// テクスチャデータを返す
			return texture_data;
		}
	};
	/*----テクスチャ読み込み----*/

	/*----テクスチャ開放----*/
	void Release() {
		texture_data.texture->Release();
	}
	/*----テクスチャ開放----*/
}

