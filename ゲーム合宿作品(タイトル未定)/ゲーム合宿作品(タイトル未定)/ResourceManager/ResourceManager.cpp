#include "ResourceManager.h"

// テクスチャ読み込み
void ResourceManager::LoadTexture() {

	// 全テクスチャを登録
	for (int i = 0; i < MAX_TEXTURE_ID_NUM; i++) {

		// テクスチャリソース設定
		SetTexture(texture_id);

		texture_id = static_cast<TextureID>(texture_id + 1);
	}
}

// テクスチャリソース設定
void ResourceManager::SetTexture(TextureID texture_id) {

	// テクスチャIDによってリソース変更
	switch (texture_id) {
		// テスト
	case TEST1_ID:
		m_texture_file_list.push_back((char*)"Resource/test1.png");
		break;
	case TEST2_ID:
		m_texture_file_list.push_back((char*)"Resource/test2.png");
		break;
	default:
		break;
	}

	// 
	m_texture_list.push_back(Texture::Load(m_texture_file_list[texture_id]));
}

