#include <DxLib.h>
#include "BalletMgr.h"
#include "Other.h"

BalletMgr::BalletMgr()
{
	image = new int;
	name = eBalletMgr;
	for (int i = 0; i < BALLET_MAX; i++)
	{
		ballet_child[i] = NULL;
	}
}


BalletMgr::~BalletMgr()
{
	delete image;
}

void BalletMgr::Instance_Ballet(const VECTOR &pos_BMgrInst, const eName &name_BMgrInst)
{
	for (int i = 0; i < BALLET_MAX; i++)
	{
		if (ballet_child[i] == NULL)
		{
			ballet_child[i] = new Ballet(pos_BMgrInst, name_BMgrInst, image);
			return;
		}
	}
}

VECTOR * BalletMgr::Ballet_Allpos(eName *is_Insted)
{
	VECTOR ptr_balletpos[BALLET_MAX];
	for (int i = 0; i < BALLET_MAX; i++)
	{
		if (ballet_child[i] != NULL) {
			ptr_balletpos[i] = ballet_child[i]->Get_pos(&is_Insted[i]);
		}
		else
		{
			ptr_balletpos->x = -1;
			ptr_balletpos->y = -1;
		}
	}
	return ptr_balletpos;
}

void BalletMgr::Damage_Mgr(int i)
{
	ballet_child[i]->Damage();
}

void BalletMgr::init()
{
	*image = LoadGraph("‰æ‘œ/‚½‚Ü.png");
}

void BalletMgr::Update()
{
	for (int i = 0; i < BALLET_MAX; i++)
	{
		if (ballet_child[i] != NULL)
		{
			ballet_child[i]->Update();
		}
	}

	for (int i = 0; i < BALLET_MAX; i++)
	{
		if (ballet_child[i] != NULL)
		{
			if (ballet_child[i]->Get_pos(NULL).x < 0 || ballet_child[i]->Get_pos(NULL).x > SET_SCREENSIZE_X
				|| ballet_child[i]->Get_pos(NULL).y < 0 || ballet_child[i]->Get_pos(NULL).y > SET_SCREENSIZE_Y
				|| Death_is_true())
			{
				delete ballet_child[i];
				ballet_child[i] = NULL;
			}
		}
	}
}

void BalletMgr::Draw()
{
	for (int i = 0; i < BALLET_MAX; i++)
	{
		if (ballet_child[i] != NULL)
		{
			ballet_child[i]->Draw();
		}
	}
}

void BalletMgr::End()
{
	for (int i = 0; i < BALLET_MAX; i++)
	{
		delete ballet_child[i];
	}
}
