#include "ResourceManager.h"

/*----public----*/
/*----テクスチャ読み込み----*/
void ResourceManager::LoadTexture() {
	// 全テクスチャを登録
	for (int i = 0; i < MAX_TEXTURE_ID_NUM; i++) {
		// テクスチャリソース設定
		RegisterTexture(m_texture_id);
		// TextureData追加
		m_texture_data_list.push_back(Texture::Load(m_texture_file_list[m_texture_id]));
		// enum加算
		m_texture_id = static_cast<TextureID>(m_texture_id + 1);
	}
}
/*----テクスチャ読み込み----*/
/*----public----*/

/*----private----*/
/*----テクスチャリソース登録----*/
void ResourceManager::RegisterTexture(TextureID texture_id) {
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
	// テスト、バレット
	case TEST3_ID:
		m_texture_file_list.push_back((char*)"Resource/test3.png");
		break;
	// テスト、バックスクリーン
	case TEST4_ID:
		m_texture_file_list.push_back((char*)"Resource/test4.png");
		break;
	// それ以外
	default:
		break;
	}
}
/*----テクスチャリソース登録----*/
/*----private----*/

