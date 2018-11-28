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

	*image = LoadGraph("‰æ‘œ/‚½‚Ü.png");
}


BalletMgr::~BalletMgr()
{
	DeleteGraph(*image);
	delete image;
	for (int i = 0; i < BALLET_MAX; i++)
	{
		delete ballet_child[i];
	}
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

Ballet ** BalletMgr::Get_balletchild()
{
	return ballet_child;
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
				|| ballet_child[i]->Death_is_true())
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
