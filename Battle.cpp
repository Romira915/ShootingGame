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
	image_bg_ba = LoadGraph("画像/背景.png");
	image_end = LoadGraph("画像/終了.png");
	image_clear = LoadGraph("画像/クリア.png");

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
	Enemy **enemyobj = enemyMgr->Get_enemychild();
	Ballet **balletobj = balletMgr->Get_balletchild();

	int p_width, p_height;
	int e_width, e_height;
	int b_width, b_height;

	GetGraphSize(*(player->Get_ptrimageHandle()), &p_width, &p_height);
	GetGraphSize(*(enemyMgr->Get_ptrimageHandle()), &e_width, &e_height);
	GetGraphSize(*(balletMgr->Get_ptrimageHandle()), &b_width, &b_height);

	for (int i = 0; i < BALLET_MAX; i++)
	{
		if (balletobj[i] != NULL)
		{
			switch (balletobj[i]->Get_isInsted())
			{
			case eEnemy: {
				if (((balletobj[i]->Get_pos(NULL).x < playerpos.x && playerpos.x < balletobj[i]->Get_pos(NULL).x + b_width)
					|| (playerpos.x < balletobj[i]->Get_pos(NULL).x && balletobj[i]->Get_pos(NULL).x < playerpos.x + p_width))
					&& (balletobj[i]->Get_pos(NULL).y < playerpos.y + 10 && playerpos.y + 10 < balletobj[i]->Get_pos(NULL).y + b_height)
					|| (playerpos.y + 10 < balletobj[i]->Get_pos(NULL).y && balletobj[i]->Get_pos(NULL).y < playerpos.y + p_height))
				{
					printfDx("弾の座標：(%f,%f)\nプレイヤーの座標：(%f,%f)\n", balletobj[i]->Get_pos(NULL).x, balletobj[i]->Get_pos(NULL).y, playerpos.x, playerpos.y);
					//WaitTimer(100000);
					player->Damage();
					//balletMgr->Damage_Mgr(i);
					balletobj[i]->Damage();
					printfDx("%d\n", balletobj[i]->m_hp);
				}
			}
						 break;
			case ePlayer: {
				for (int j = 0; j < ENEMY_MAX; j++)
				{
					if (enemyobj[j] != NULL) {
						if (((balletobj[i]->Get_pos(NULL).x < enemyobj[j]->Get_pos().x && enemyobj[j]->Get_pos().x < balletobj[i]->Get_pos(NULL).x + b_width)
							|| (enemyobj[j]->Get_pos().x < balletobj[i]->Get_pos(NULL).x && balletobj[i]->Get_pos(NULL).x < enemyobj[j]->Get_pos().x + e_width))
							&& ((balletobj[i]->Get_pos(NULL).y < enemyobj[j]->Get_pos().y && enemyobj[j]->Get_pos().y < balletobj[i]->Get_pos(NULL).y + b_height)
								|| (enemyobj[j]->Get_pos().y < balletobj[i]->Get_pos(NULL).y && balletobj[i]->Get_pos(NULL).y < enemyobj[j]->Get_pos().y + e_height - 10)))
						{
							enemyobj[j]->Damage();
							balletobj[i]->Damage();
						}
					}
				}
			}
						  break;
			default:
				break;
			}
		}
	}
}

bool Collision(Player *ptrplayerobj_pos, Ballet *ptr_balletobj)
{
	int width;
	int height;
	GetGraphSize(*ptr_balletobj->Get_ptrimageHandle(), &width, &height);
	return false;
}

bool Collision(Enemy *, Ballet *)
{
	return false;
}


