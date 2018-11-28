#include "Keyboard.h"
#include <DxLib.h>

int key[256];

int Keyboard_Update()
{
	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			if (key[i] == 127) {
				key[i] = 0;
			}
			key[i]++;     // ���Z
		}
		else {              // ������Ă��Ȃ����
			key[i] = 0;   // 0�ɂ���
		}
	}

	return 0;
}

int Get_key(int key_input)
{
	return key[key_input];
}