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
			if (ballet_child[i]->Get_pos().x < -200 || ballet_child[i]->Get_pos().x > SET_SCREENSIZE_X + 200
				|| ballet_child[i]->Get_pos().y < -200 || ballet_child[i]->Get_pos().y > SET_SCREENSIZE_Y + 200)
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
