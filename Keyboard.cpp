#include "Keyboard.h"
#include <DxLib.h>

int key[256];

int Keyboard_Update()
{
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			if (key[i] == 127) {
				key[i] = 0;
			}
			key[i]++;     // 加算
		}
		else {              // 押されていなければ
			key[i] = 0;   // 0にする
		}
	}

	return 0;
}

int Get_key(int key_input)
{
	return key[key_input];
}