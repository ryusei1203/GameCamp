#include "ResourceManager.h"

/*----テクスチャ読み込み----*/
void ResourceManager::LoadTexture() {
	// 全テクスチャを登録
	for (int i = 0; i < MAX_TEXTURE_ID_NUM; i++) {
		// テクスチャリソース設定
		SetTexture(texture_id);
		// enum加算
		texture_id = static_cast<TextureID>(texture_id + 1);
	}
}
/*----テクスチャ読み込み----*/

/*----テクスチャリソース設定----*/
void ResourceManager::SetTexture(TextureID texture_id) {
	// テクスチャIDによってリソース変更
	switch (texture_id) {
	// テスト、プレイヤー
	case TEST1_ID:
		m_texture_file_list.push_back((char*)"Resource/test1.png");
		break;
	// テスト、エネミー
	case TEST2_ID:
		m_texture_file_list.push_back((char*)"Resource/test2.png");
		break;
	// それ以外
	default:
		break;
	}
	// TextureData追加
	m_texture_list.push_back(Texture::Load(m_texture_file_list[texture_id]));
}
/*----テクスチャリソース設定----*/

