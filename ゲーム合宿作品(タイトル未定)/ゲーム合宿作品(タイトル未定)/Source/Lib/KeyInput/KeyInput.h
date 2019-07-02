#pragma once

#include "../Window/Window.h"

#include <Windows.h>
#include <dinput.h>

#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")

/*----キー情報 GetKeyシリーズで使用(16進数)----*/
// キークリア用
#define CREAR_KEY	(0x0000)
// 上キー
#define UP_KEY		(0x0001)
// 下キー
#define DOWN_KEY	(0x0002)
// 左キー
#define LEFT_KEY	(0x0004)
// 右キー
#define RIGHT_KEY	(0x0008)
// スペースキー
#define SPACE_KEY	(0x0010)
// エスケープキー
#define ESCAPE_KEY	(0x0020)
/*----キー情報 GetKeyシリーズで使用(16進数)----*/

// キー入力情報
namespace KeyInput {
	// DirectInput初期化
	void Init();
	// キーを押している最中
	bool GetKey(DWORD key_code);
	// キーを押した時
	bool GetKeyDown(DWORD key_code);
	// キーを話した時
	bool GetKeyUp(DWORD key_code);
	// キー情報更新
	void Update();
	// DirectInput解放
	void Release();
}

