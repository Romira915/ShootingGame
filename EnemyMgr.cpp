#include "EnemyMgr.h"
#include <DxLib.h>
#include "Other.h"


EnemyMgr::EnemyMgr()
{
	image = new int;
	name = eEnemyMgr;
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy_child[i] = NULL;
	}

	*image = LoadGraph("‰æ‘œ/‚Ä‚«.png");
}

EnemyMgr::~EnemyMgr()
{
	DeleteGraph(*image);
	delete image;
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		delete enemy_child[i];
	}
}

void EnemyMgr::Instance_Enemy()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy_child[i] == NULL) {
			enemy_child[i] = new Enemy(image);
			return;
		}
	}
}

void EnemyMgr::Damage_Mgr(int i)
{
	enemy_child[i]->Damage();
}

Enemy ** EnemyMgr::Get_enemychild()
{
	return enemy_child;
}

void EnemyMgr::Update()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy_child[i] != NULL)
		{
			enemy_child[i]->Update();
		}
	}

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy_child[i] != NULL)
		{
			if (enemy_child[i]->Get_pos().x < 0 || enemy_child[i]->Get_pos().x > SET_SCREENSIZE_X
				|| enemy_child[i]->Get_pos().y < 0 || enemy_child[i]->Get_pos().y > SET_SCREENSIZE_Y
				|| enemy_child[i]->Death_is_true())
			{
				delete enemy_child[i];
				enemy_child[i] = NULL;
			}
		}
	}

	if (GetRand(15) == 0)
	{
		Instance_Enemy();
	}
}

void EnemyMgr::Draw()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy_child[i] != NULL)
		{
			enemy_child[i]->Draw();
		}
	}
}
