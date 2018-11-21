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
	SetMainWindowText("よっかべーだー改変");
	SetWindowSizeChangeEnableFlag(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	Title_init();

	Player player;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		// 全体の処理に絶対的に必要な処理群
		Timecount_Update();
		Keyboard_Update();

		SceneMgr_Update();

		SceneMgr_Draw();
	}

	DxLib_End();
	return 0;
}