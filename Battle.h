#ifndef DEF_BATTLE_H
#define DEF_BATTLE_H
#include "Chara.h"
#include "Player.h"
#include "Enemy.h"
#include "Ballet.h"

#define TIMELIMIT 1 * 60 * 1000 // ï™ ÅE ï™Å®ïb ÅE ïbÅ®É~Éäïb

void Battle_init();

void Battle_Update();

void Battle_Draw();

void Battle_End();

void Ballet_Inst(const VECTOR&, const eName&);

void Enemy_Inst_Update();

VECTOR Playerpos_return();

void Collision();

bool Collision_child(const VECTOR, const VECTOR&, const int&, const int&, const int&, const int&);

#endif // !DEF_BATTLE_H


