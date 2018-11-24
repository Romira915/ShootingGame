#include <DxLib.h>
#include "Keyboard.h"
#include "Player.h"
#include "Battle.h"
#include "BalletMgr.h"
#include "Chara.h"
#include "EnemyMgr.h"
#include "SceneManager.h"
#include <cstdlib>

int image_bg_ba;
int image_end;
int image_clear;

int player_imageSize;
int ballet_imageSize;
int enemy_imageSize;

Player *player;
BalletMgr *balletMgr;
EnemyMgr *enemyMgr;


void Battle_init()
{
	image_bg_ba = LoadGraph("‰æ‘œ/”wŒi.png");
	image_end = LoadGraph("‰æ‘œ/I—¹.png");
	image_clear = LoadGraph("‰æ‘œ/ƒNƒŠƒA.png");

	player = new Player;
	balletMgr = new BalletMgr;
	enemyMgr = new EnemyMgr;

	player->init();
	balletMgr->init();
	enemyMgr->init();
}

void Battle_Update() {
	Enemy_Inst_Update();
	balletMgr->Update();
	enemyMgr->Update();
	if (!player->Death_is_true())
	{
		player->Update();
	}

	Collision();


	if (Get_key(KEY_INPUT_ESCAPE) == 1) {
		SceneChange(Title);
	}
}

void Battle_Draw()
{
	DrawGraph(0, 0, image_bg_ba, true);
	balletMgr->Draw();
	enemyMgr->Draw();
	if (!player->Death_is_true())
	{
		player->Draw();
	}
}

void Battle_End()
{
	DeleteGraph(image_bg_ba);
	DeleteGraph(image_end);
	DeleteGraph(image_clear);

	balletMgr->End();
	enemyMgr->End();
	player->End();

	delete balletMgr;
	delete enemyMgr;
	delete player;
}

void Ballet_Inst(const VECTOR &pos_battlefunc, const eName &name_battlefunc)
{
	balletMgr->Instance_Ballet(pos_battlefunc, name_battlefunc);
}

void Enemy_Inst_Update()
{
	if (GetRand(10) == 0) {
		enemyMgr->Instance_Enemy();
	}
}

VECTOR Playerpos_return()
{
	return player->Get_pos();
}

void Collision()
{
	eName is_Insted[BALLET_MAX];

	VECTOR playerpos = player->Get_pos();
	VECTOR *enemypos = enemyMgr->Enemy_Allpos();
	VECTOR *balletpos = balletMgr->Ballet_Allpos(is_Insted);

	for (int i = 0; i < BALLET_MAX; i++)
	{
		switch (is_Insted[i])
		{
		case eEnemy: {
			if (playerpos.x <= balletpos[i].x && balletpos[i].x <= playerpos.x + 50 && playerpos.y <= balletpos[i].y && balletpos[i].y <= playerpos.y + 50)
			{
				delete player;
			}
		}
		case ePlayer: {
			for (int j = 0; j < ENEMY_MAX; j++)
			{
				if (enemypos[j].x <= balletpos[i].x && balletpos[i].x <= enemypos[j].x + 50 && enemypos[j].y <= balletpos[i].y && balletpos[i].y <= enemypos[j].y + 50)
				{
					enemyMgr->Damage_Mgr(j);
				}
			}
		}
		default:
			break;
		}

	}
}


