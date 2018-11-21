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

void EnemyMgr::init()
{
	*image = LoadGraph("‰æ‘œ/‚Ä‚«.png");
}

void EnemyMgr::Update()
{
	static int enecountX[ENEMY_MAX];
	static int enecountY[ENEMY_MAX];
	static int count_jj;
	count_jj++;
	if (count_jj > ENEMY_MAX)
	{
		count_jj = 0;
	}
	SRand(GetNowCount());
	enecountX[count_jj] = GetRand(SET_SCREENSIZE_X);
	enecountY[count_jj] = GetRand(SET_SCREENSIZE_Y / 2);

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy_child[i] != NULL)
		{
			enemy_child[i]->Update();
			enemy_child[i]->Move_AI(enecountX[i], enecountY[i]);
		}
	}

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy_child[i] != NULL)
		{
			if (enemy_child[i]->Get_pos().x < 0 || enemy_child[i]->Get_pos().x > SET_SCREENSIZE_X
				|| enemy_child[i]->Get_pos().y < 0 || enemy_child[i]->Get_pos().y > SET_SCREENSIZE_Y)
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
