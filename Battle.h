#ifndef DEF_BATTLE_H
#define DEF_BATTLE_H
#include "Chara.h"

void Battle_init();

void Battle_Update();

void Battle_Draw();

void Battle_End();

void Ballet_Inst(const VECTOR&, const eName&);

void Enemy_Inst_Update();

VECTOR Playerpos_return();

#endif // !DEF_BATTLE_H


