#include <DxLib.h>
#include "Keyboard.h"
#include "Chara.h"
#include "Player.h"
#include "Other.h"
#include "SceneManager.h"

#define TITLE 1

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(TRUE);
	SetGraphMode(SET_SCREENSIZE_X, SET_SCREENSIZE_Y, 32);
	SetMainWindowText("������ׁ[���[����");
	SetWindowSizeChangeEnableFlag(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	Title_init();

	Player player;

	int player_image = LoadGraph("�摜/���@.png");
	int ballet_image = LoadGraph("�摜/����.png");
	VECTOR playerpos;
	VECTOR balletpos;

	playerpos.x = 640;
	playerpos.y = 500;
	balletpos.x = 400;
	balletpos.y = 300;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		// �S�̂̏����ɐ�ΓI�ɕK�v�ȏ����Q
		Timecount_Update();
		Keyboard_Update();

		SceneMgr_Update();

		SceneMgr_Draw();

		/*if (((balletpos. < player->Get_pos().x && playerpos.x < balletobj[i]->Get_pos(NULL).x + b_width)
			|| (playerpos.x < balletobj[i]->Get_pos(NULL).x && balletobj[i]->Get_pos(NULL).x < playerpos.x + p_width))
			&& ((balletobj[i]->Get_pos(NULL).y < player->Get_pos().y + 10 && player->Get_pos().y + 10 < balletobj[i]->Get_pos(NULL).y + b_height)
				|| (player->Get_pos().y + 10 < balletobj[i]->Get_pos(NULL).y && balletobj[i]->Get_pos(NULL).y < player->Get_pos().y + p_height))) {

		}
*/
	}

	DxLib_End();
	return 0;
}