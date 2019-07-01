#include "KeyInput.h"

// キー入力情報
namespace KeyInput {
	// IDirectInput8のポインタ
	LPDIRECTINPUT8 input_interface;
	// IDirectInputDevice8のポインタ
	LPDIRECTINPUTDEVICE8 input_device;
	// キー情報構造体
	struct INPUTSTSATE {
		// 1フレーム前のキー情報
		DWORD now;
		// トリガー情報
		DWORD trg;
		// 逆トリガー情報
		DWORD ntrg;
	};
	// キー情報
	INPUTSTSATE input_state;
	// DirectInput初期化
	void Init() {
		// インスタンスハンドル
		HINSTANCE hinstance = GetModuleHandle(nullptr);
		// IDirectInput8インターフェイス作成
		HRESULT hresult = DirectInput8Create(
			// インスタンスハンドル
			hinstance,
			// 使用するDirectInputのバージョン
			DIRECTINPUT_VERSION,
			// 目的とするインターフェースの識別子
			IID_IDirectInput8,
			// IDirectInput8インターフェースポインタ受け取り用
			(void**)&input_interface,
			// LPUKNOWN
			NULL
		);
		if (FAILED(hresult)) {
			return;
		}
		// IDirectInputDevice8作成
		hresult = input_interface->CreateDevice(
			// 使用するデバイス
			GUID_SysKeyboard,
			// IDirectInputDevice8インターフェイス受け取り用
			&input_device,
			// LPUNKNOWN
			NULL
		);
		if (FAILED(hresult)) {
			return;
		}
		// デバイスフォーマット設定
		hresult = input_device->SetDataFormat(
			// 設定する入力デバイスフォーマット
			&c_dfDIKeyboard
		);
		if (FAILED(hresult)) {
			return;
		}
		// 協調モード設定
		hresult = input_device->SetCooperativeLevel(
			// ウィンドウハンドル
			Window::hwnd,
			// 協調レベルの設定フラグ
			DISCL_BACKGROUND | DISCL_NONEXCLUSIVE
		);
		if (FAILED(hresult)) {
			return;
		}
		// デバイス制御開始
		hresult = input_device->Acquire();
		if (FAILED(hresult)) {
			return;
		}
	}
	// キー情報更新
	void Update() {
		// キー情報取得格納用
		BYTE KeyState[256];
		// キーボードデバイスのゲッター
		HRESULT hresult = input_device->GetDeviceState(
			// LPVOIDで指定しているデータサイズ
			256,
			// デバイスの情報を受け取すためのデータアドレス
			KeyState
		);
		if (SUCCEEDED(hresult)) {
			// 1フレーム前のキー情報の確保
			DWORD old = input_state.now;
			// キー情報クリア
			input_state.now = CREAR_KEY;
			// キー情報
			{
				// 上キー
				if (KeyState[DIK_UP] & 0x80) {
					input_state.now |= UP_KEY;
				}
				// 下キー
				if (KeyState[DIK_DOWN] & 0x80) {
					input_state.now |= DOWN_KEY;
				}
				// 左キー
				if (KeyState[DIK_LEFT] & 0x80) {
					input_state.now |= LEFT_KEY;
				}
				// 右キー
				if (KeyState[DIK_RIGHT] & 0x80) {
					input_state.now |= RIGHT_KEY;
				}
				// リターンキー
				/*if (KeyState[DIK_RETURN] & 0x80) {
					input_state.now |= RETURN_KEY;
				}*/
				// スペースキー
				if (KeyState[DIK_SPACE] & 0x80) {
					input_state.now |= SPACE_KEY;
				}
			}
			// トリガー情報取得
			input_state.trg = (input_state.now & (~old));
			// 逆トリガー情報取得
			input_state.ntrg = (~input_state.now) & old;
		}
		// デバイスロスト時は再度制御開始を呼ぶ
		else if (hresult == DIERR_INPUTLOST) {
			input_device->Acquire();
		}
	}
	// キーを押している最中
	bool GetKey(DWORD key_code) {
		return input_state.now & key_code;
	}
	// キーを押した時
	bool GetKeyDown(DWORD key_code) {
		return input_state.trg & key_code;
	}
	// キーを話した時
	bool GetKeyUp(DWORD key_code) {
		return input_state.ntrg & key_code;
	}
	// 解放
	void Release() {
		// デバイスの使用停止
		input_device->Unacquire();
		// IDirectInputDevice8解放
		input_device->Release();
		// IDirectinput8解放
		input_interface->Release();
	}
}

