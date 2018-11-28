#include "SceneManager.h"
#include <DxLib.h>
#include "Other.h"
#include "Battle.h"

eScene SceneFlag = Title;

void SceneMgr_Update()
{
	switch (SceneFlag)
	{
	case Title: {
		Title_Update();
	}
				break;
	case Battle: {
		Battle_Update();
	}
		break;
	default:
		break;
	}
}

void SceneMgr_Draw()
{
	switch (SceneFlag)
	{
	case Title: {
		Title_Draw();
	}
				break;
	case Battle: {
		Battle_Draw();
	}
				 break;
	default:
		break;
	}
}

void SceneChange(eScene change) {
	switch (SceneFlag)
	{
	case Title: {
		Title_End();
	}
				break;
	case Battle: {
		Battle_End();
	}
		break;
	default:
		break;
	}

	SceneFlag = change;

	switch (SceneFlag)
	{
	case Title: {
		Title_init();
	}
				break;
	case Battle: {
		Battle_init();
	}
				 break;
	default:
		break;
	}
}


