#include <DxLib.h>
#include "Keyboard.h"
#include "Player.h"
#include "Battle.h"

int image_bg_ba;
int image_end;
int image_clear;

Player player;

void Battle_init()
{
	image_bg_ba = LoadGraph("‰æ‘œ/”wŒi.png");
	image_end = LoadGraph("‰æ‘œ/I—¹.png");
	image_clear = LoadGraph("‰æ‘œ/ƒNƒŠƒA.png");

	player.init();
}

void Battle_Update() {
	player.Update();
}

void Battle_Draw()
{
	DrawGraph(0, 0, image_bg_ba, true);
	player.Draw();
}

void Battle_End()
{
	DeleteGraph(image_bg_ba);
	DeleteGraph(image_end);
	DeleteGraph(image_clear);

	player.End();
}
