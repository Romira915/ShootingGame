#ifndef DEF_BATTLE_H
#define DEF_BATTLE_H
#include "Chara.h"
#include "Player.h"
#include "Enemy.h"
#include "Ballet.h"

void Battle_init();

void Battle_Update();

void Battle_Draw();

void Battle_End();

void Ballet_Inst(const VECTOR&, const eName&);

void Enemy_Inst_Update();

VECTOR Playerpos_return();

void Collision();

bool Collision(Player*, Ballet*);

bool Collision(Enemy*, Ballet*);

#endif // !DEF_BATTLE_H


