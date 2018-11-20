#include <DxLib.h>
#include "BalletMgr.h"


BalletMgr::BalletMgr()
{
	name = eBalletMgr;
	for (int i = 0; i < BALLET_MAX; i++)
	{
		ballet_child[i] = NULL;
	}
}


BalletMgr::~BalletMgr()
{
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
	image = new int;
	*image = LoadGraph("‰æ‘œ/‚½‚Ü.png");
	name = eBalletMgr;
	for (int i = 0; i < BALLET_MAX; i++)
	{
		ballet_child[i] = NULL;
	}
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
}
