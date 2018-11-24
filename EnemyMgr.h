#ifndef DEF_ENEMYMGR_H
#define DEF_ENEMYMGR_H
#include <DxLib.h>
#include "Enemy.h"
#include "Chara.h"

#define ENEMY_MAX 7

class EnemyMgr : public Chara
{
public:
	EnemyMgr();
	~EnemyMgr();

	void Instance_Enemy();
	VECTOR *Enemy_Allpos();
	void Damage_Mgr(int);

	void init();
	void Update();
	void Draw();
	void End();

private:
	Enemy *enemy_child[ENEMY_MAX];
};

#endif // !DEF_ENEMYMGR_H
