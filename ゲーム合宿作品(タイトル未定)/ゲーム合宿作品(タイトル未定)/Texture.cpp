#include "Texture.h"

namespace Texture {

	// データリスト
	std::vector<TextureData> texture_list;

	// テクスチャデータID
	TextureID texture_id;


	/*----テクスチャ読み込み----*/
	void Load(TextureID texture_id) {

		const char *file_name;

		texture_list.push_back(TextureData());

		switch (texture_id) {
		case TEST:
			file_name = "Resource/test.png";
			break;

		default:
			file_name = "hoge";
		}

		D3DXCreateTextureFromFileA(
			D3D::dev,
			file_name,
			&texture_list[texture_id].texture);

		// テクスチャサイズ取得
		D3DSURFACE_DESC desc;

		texture_list[texture_id].texture->GetLevelDesc(0, &desc);

		texture_list[texture_id].width = (float)desc.Width;
		texture_list[texture_id].height = (float)desc.Height;

		//D3DXCreateTextureFromFileExA(
		//	// 読み込みで使用するDevice
		//	D3D::dev,
		//	// ファイル名
		//	file_name,
		//	// ファイルの横幅
		//	100,
		//	// ファイルの縦幅
		//	100,
		//	// ミニマップのレベル
		//	0,
		//	// テクスチャの使い方
		//	0,
		//	// テクスチャのカラーフォーマット設定
		//	D3DFMT_A8R8G8B8,
		//	// テクスチャメモリの管理方法
		//	D3DPOOL_MANAGED,
		//	// フィルタリング方法
		//	D3DX_FILTER_LINEAR,
		//	// ミニマップのフィルタリング方法
		//	D3DX_FILTER_LINEAR,
		//	// 抜き色の指定
		//	NULL,
		//	// 元の画像の情報が欲しい場合に使用
		//	NULL,
		//	// 256色のカラーの場合のみカラーパレットが格納
		//	NULL,
		//	// 読み込まれたテクスチャの格納先
		//	&texture_list[texture_id].texture
		//	);
	};
	/*----テクスチャ読み込み----*/

	/*----四角形描画----*/
	void DrawBox2D(TextureID texture_id) {

		// テクスチャの設定
		D3D::dev->SetTexture(
			// テクスチャステージの番号
			0,
			// 指定したいテクスチャ
			texture_list[texture_id].texture
		);

		// 頂点バッファがどの頂点情報を指しているか
		D3D::dev->SetFVF(FVF_2D);

		CustomVetrex custom_vertex[4] = {
			// 左上頂点 
			{0.f,0.f,0.f,1.f,0xffffff,0.f,0.f },
			// 右上頂点
			{texture_list[texture_id].width,0.f,0.f,1.f,0xffffff,0.f,1.f },
			// 右下頂点
			{texture_list[texture_id].width,texture_list[texture_id].height,0.f,1.f,0xffffff,1.f,0.f },
			// 左下頂点
			{0.f,texture_list[texture_id].height,0.f,1.f,0xffffff,1.f,1.f },
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

