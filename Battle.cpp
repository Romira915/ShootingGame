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
	image_bg_ba = LoadGraph("�摜/�w�i.png");
	image_end = LoadGraph("�摜/�I��.png");
	image_clear = LoadGraph("�摜/�N���A.png");

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
