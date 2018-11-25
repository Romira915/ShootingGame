#include <DxLib.h>
#include "EnemyMgr.h"
#include "Other.h"
#include <climits>


EnemyMgr::EnemyMgr()
{
	image = new int;
	name = eEnemyMgr;
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy_child[i] = NULL;
	}
}

EnemyMgr::~EnemyMgr()
{
	delete image;
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

VECTOR * EnemyMgr::Enemy_Allpos()
{
	VECTOR ptr_enemypos[ENEMY_MAX];
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy_child[i] != NULL) {
			ptr_enemypos[i] = enemy_child[i]->Get_pos();
		}
		else
		{
			ptr_enemypos->x = -1;
			ptr_enemypos->y = -1;
		}
	}
	return ptr_enemypos;
}

void EnemyMgr::Damage_Mgr(int i)
{
	enemy_child[i]->Damage();
}

Enemy ** EnemyMgr::Get_enemychild()
{
	return enemy_child;
}

void EnemyMgr::init()
{
	*image = LoadGraph("‰æ‘œ/‚Ä‚«.png");
}

void EnemyMgr::Update()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy_child[i] != NULL)
		{
			enemy_child[i]->Update();
			//enemy_child[i]->Move_AI(GetRand(SET_SCREENSIZE_X), GetRand(SET_SCREENSIZE_Y / 2));
		}
	}

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy_child[i] != NULL)
		{
			if (enemy_child[i]->Get_pos().x < 0 || enemy_child[i]->Get_pos().x > SET_SCREENSIZE_X
				|| enemy_child[i]->Get_pos().y < 0 || enemy_child[i]->Get_pos().y > SET_SCREENSIZE_Y
				|| Death_is_true())
			{
				delete enemy_child[i];
				enemy_child[i] = NULL;
			}
		}
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

void EnemyMgr::End()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		delete enemy_child[i];
	}
}
