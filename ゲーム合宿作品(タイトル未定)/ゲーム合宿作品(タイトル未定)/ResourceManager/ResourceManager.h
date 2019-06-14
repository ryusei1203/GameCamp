#pragma once

#include "../Lib/Texture/Texture.h"

#include <vector>

// シングルトン
// リソースID
class ResourceManager {

public:
	// テクスチャデータID
	enum TextureID {
		TEST1_ID,
		TEST2_ID,

		MAX_TEXTURE_ID_NUM
	};

public :
	// インスタンス取得
	static ResourceManager &GetInstance() {
		static ResourceManager resource_id;
		return resource_id;
	}

	// ゲッター
	// 
	Texture::TextureData GetTextureData(TextureID texture_id) {
		return m_texture_list[texture_id];
	}

	// テクスチャ読み込み
	void LoadTexture();

private:
	// コンストラクタ
	ResourceManager() : 
		texture_id(TEST1_ID)
	{};

	// リソース設定
	void SetTexture(TextureID texture_id);
	
	// 
	TextureID texture_id;

	// 
	std::vector<char*> m_texture_file_list;

	// 
	std::vector<Texture::TextureData> m_texture_list;
};

