#include <DxLib.h>
#include "Other.h"
#include "Keyboard.h"
#include "Chara.h"
#include "SceneManager.h"



int image_title;
int image_bg;

int selection = START_Y;

int old_time = 0;
int new_time = 0;
int diff_time = 0;

void Title_init()
{
	image_title = LoadGraph("画像/タイトル.png");
	image_bg = LoadGraph("画像/背景.png");
	SetFontSize(64);  // 文字列のサイズをセット
}

void Title_Update()
{
	// 下ボタン押下処理
	if (Get_key(KEY_INPUT_S) == 1 || Get_key(KEY_INPUT_DOWN) == 1) {
		switch (selection)
		{
		case START_Y: selection = EXIT_Y; break;
		case EXIT_Y: selection = START_Y; break;
		default:
			break;
		}
	}
	// 上ボタン押下処理
	if (Get_key(KEY_INPUT_W) == 1 || Get_key(KEY_INPUT_UP) == 1) {
		switch (selection)
		{
		case EXIT_Y: selection = START_Y; break;
		case START_Y: selection = EXIT_Y; break;
		default:
			break;
		}
	}
	// シーンチェンジ
	if (selection == START_Y && Get_key(KEY_INPUT_RETURN)) {
		SceneChange(Battle);
	}
	// 終了処理
	if (selection == EXIT_Y && Get_key(KEY_INPUT_RETURN)) {
		DxLib_End();
		exit(0);
	}
}

void Title_Draw()
{
	DrawGraph(0, 0, image_bg, true);
	DrawGraph(0, 0, image_title, true);
	DrawFormatString(0, selection, GetColor(255, 255, 255), "→");
	DrawFormatString(START_X, START_Y, GetColor(0, 255, 0), "Start");
	DrawFormatString(EXIT_X, EXIT_Y, GetColor(0, 255, 0), "Exit");
}

void Title_End() {
	DeleteGraph(image_title);
	DeleteGraph(image_bg);
}

int Timecount_Update() {
	old_time = new_time;
	new_time = GetNowCount();
	diff_time = new_time - old_time;

	return diff_time;
}

int Timecount_return()
{
	return diff_time;
}