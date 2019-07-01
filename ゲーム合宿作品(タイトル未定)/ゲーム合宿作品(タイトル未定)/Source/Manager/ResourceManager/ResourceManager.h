#pragma once

#include "../../Lib/Texture/Texture.h"

#include <vector>

// シングルトン
// リソースID
class ResourceManager {
public:
	/*----enum----*/
	// テクスチャデータID
	enum TextureID {
		// プレイヤー
		TEST1_ID,
		// エネミー
		TEST2_ID,
		// バレット
		TEST3_ID,
		// バックスクリーン
		TEST4_ID,

		MAX_TEXTURE_ID_NUM
	};
	/*----enum----*/
public:
	/*----初期化----*/
	// テクスチャ読み込み
	void LoadTexture();
	/*----初期化----*/
public :
	/*----ゲッター----*/
	// インスタンス取得
	static ResourceManager &GetInstance() {
		static ResourceManager resource_id;
		return resource_id;
	}
	// 指定したテクスチャIDのTextureDataを取得
	Texture::TextureData GetTextureData(TextureID texture_id) {
		return m_texture_data_list[texture_id];
	}
	/*----ゲッター----*/
private:
	/*----変数----*/
	// テクスチャID
	TextureID m_texture_id;
	/*----変数----*/
private:
	/*----配列----*/
	// テクスチャファイル保管
	std::vector<char*> m_texture_file_list;
	// テクスチャデータ保管
	std::vector<Texture::TextureData> m_texture_data_list;
	/*----配列----*/
private:
	/*----初期化----*/
	// コンストラクタ
	ResourceManager() : 
		m_texture_id(TEST1_ID)
	{};
	// リソース登録
	void RegisterTexture(TextureID texture_id);
	/*----初期化----*/
};

