#include <DxLib.h>
#include "Other.h"
#include "Keyboard.h"
#include "Chara.h"
#include "SceneManager.h"

int image_title;
int image_bg;

int selection = START_Y;

int time = 0;
int diff_time = 0;

int font_Handle_Other;

void Title_init()
{
	image_title = LoadGraph("�摜/�^�C�g��.png");
	image_bg = LoadGraph("�摜/�w�i.png");
	font_Handle_Other = CreateFontToHandle(NULL, 64, 6, DX_FONTTYPE_ANTIALIASING);
}

void Title_Update()
{
	// ���{�^����������
	if (Get_key(KEY_INPUT_S) == 1 || Get_key(KEY_INPUT_DOWN) == 1) {
		switch (selection)
		{
		case START_Y: selection = EXIT_Y; break;
		case EXIT_Y: selection = START_Y; break;
		default:
			break;
		}
	}
	// ��{�^����������
	if (Get_key(KEY_INPUT_W) == 1 || Get_key(KEY_INPUT_UP) == 1) {
		switch (selection)
		{
		case EXIT_Y: selection = START_Y; break;
		case START_Y: selection = EXIT_Y; break;
		default:
			break;
		}
	}
	// �V�[���`�F���W
	if (selection == START_Y && Get_key(KEY_INPUT_RETURN)) {
		SceneChange(Battle);
	}
	// �I������
	if (selection == EXIT_Y && Get_key(KEY_INPUT_RETURN)) {
		DxLib_End();
		exit(0);
	}
}

void Title_Draw()
{
	DrawGraph(0, 0, image_bg, true);
	DrawGraph(0, 0, image_title, true);
	DrawStringToHandle(START_X - GetDrawStringWidthToHandle("��", 2, font_Handle_Other), selection, "��", GetColor(255, 255, 255), font_Handle_Other);
	DrawStringToHandle(START_X, START_Y, "Start", GetColor(0, 255, 0), font_Handle_Other);
	DrawStringToHandle(EXIT_X, EXIT_Y, "Exit", GetColor(0, 255, 0), font_Handle_Other);
}

void Title_End() {
	DeleteGraph(image_title);
	DeleteGraph(image_bg);
}

int Timecount_Update() {
	diff_time = GetNowCount() - time;
	time = GetNowCount();

	return diff_time;
}

int Timecount_return()
{
	return diff_time;
}