#include <DxLib.h>
#include "Keyboard.h"
#include "Player.h"
#include "Battle.h"
#include "BalletMgr.h"
#include "Chara.h"
#include "EnemyMgr.h"
#include "SceneManager.h"
#include <cstdlib>
#include "Other.h"

int image_bg_ba;
int image_end;
int image_clear;

int player_imageSize;
int ballet_imageSize;
int enemy_imageSize;

Player *player;
BalletMgr *balletMgr;
EnemyMgr *enemyMgr;

eName is_Insted[BALLET_MAX];

Enemy **enemyobj;
Ballet **balletobj;

int p_width, p_height;
int e_width, e_height;
int b_width, b_height;

int fontHandle_Battle;
double limit;

void Battle_init()
{
	image_bg_ba = LoadGraph("‰æ‘œ/”wŒi.png");
	image_end = LoadGraph("‰æ‘œ/I—¹.png");
	image_clear = LoadGraph("‰æ‘œ/ƒNƒŠƒA.png");

	player = new Player;
	balletMgr = new BalletMgr;
	enemyMgr = new EnemyMgr;

	enemyobj = enemyMgr->Get_enemychild();
	balletobj = balletMgr->Get_balletchild();

	GetGraphSize(*(player->Get_ptrimageHandle()), &p_width, &p_height);
	GetGraphSize(*(enemyMgr->Get_ptrimageHandle()), &e_width, &e_height);
	GetGraphSize(*(balletMgr->Get_ptrimageHandle()), &b_width, &b_height);

	fontHandle_Battle = CreateFontToHandle(NULL, 64, 7, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	limit = TIMELIMIT;
}

void Battle_Update() {
	limit -= Timecount_return();

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
	if (Get_key(KEY_INPUT_RETURN) == 2 && limit < 0)
	{
		SceneChange(Title);
	}
}

void Battle_Draw()
{
	DrawGraph(0, 0, image_bg_ba, true);
	if (limit >= 0) {
		balletMgr->Draw();
		enemyMgr->Draw();
		DrawFormatStringFToHandle(0, 0, GetColor(255, 255, 255), fontHandle_Battle, "%.2f", limit / 1000);
	}
	else
	{
		DrawGraph(0, 0, image_clear, true);
	}
	if (!player->Death_is_true())
	{
		player->Draw();
	}
	else
	{
		DrawGraph(0, 0, image_end, true);
	}

}

void Battle_End()
{
	DeleteGraph(image_bg_ba);
	DeleteGraph(image_end);
	DeleteGraph(image_clear);

	delete balletMgr;
	delete enemyMgr;
	delete player;

	DeleteFontToHandle(fontHandle_Battle);
}

void Ballet_Inst(const VECTOR &pos_battlefunc, const eName &name_battlefunc)
{
	balletMgr->Instance_Ballet(pos_battlefunc, name_battlefunc);
}

VECTOR Playerpos_return()
{
	return player->Get_pos();
}

void Collision()
{
	for (int i = 0; i < BALLET_MAX; i++)
	{
		if (balletobj[i] != NULL)
		{
			switch (balletobj[i]->Get_isInsted())
			{
			case eEnemy: {
				if (Collision_child(player->Get_pos(), balletobj[i]->Get_pos(NULL), p_width, b_width, p_height, b_height))
				{
					player->Damage();
					balletobj[i]->Damage();
				}
			}
						 break;
			case ePlayer: {
				for (int j = 0; j < ENEMY_MAX; j++)
				{
					if (enemyobj[j] != NULL) {
						if (Collision_child(enemyobj[j]->Get_pos(), balletobj[i]->Get_pos(NULL), e_width, b_width, e_height, b_height))
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

bool Collision_child(const VECTOR pos1, const VECTOR &pos2, const int &pos1_width, const int &pos2_width, const int &pos1_height, const int &pos2_height)
{
	if (((pos2.x < pos1.x && pos1.x < pos2.x + pos2_width)
		|| (pos1.x < pos2.x && pos2.x < pos1.x + pos1_width))
		&& ((pos2.y < pos1.y && pos1.y < pos2.y + pos2_height)
			|| (pos1.y < pos2.y && pos2.y < pos1.y + pos1_height)))
	{
		return true;
	}
	else
	{
		return false;
	}
}




