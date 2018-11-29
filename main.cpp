#include <DxLib.h>
#include "Keyboard.h"
#include "Other.h"
#include "SceneManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(TRUE);
	SetGraphMode(SET_SCREENSIZE_X, SET_SCREENSIZE_Y, 32);
	SetMainWindowText("ÇÊÇ¡Ç©Ç◊Å[ÇæÅ[â¸ïœ");
	SetWindowSizeChangeEnableFlag(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	Title_init();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		Timecount_Update();
		Keyboard_Update();

		SceneMgr_Update();

		SceneMgr_Draw();
	}

	DxLib_End();
	return 0;
}