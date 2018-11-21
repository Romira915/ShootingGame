#ifndef DEF_ENEMYMGR_H
#define DEF_ENEMYMGR_H
#include <DxLib.h>
#include "Enemy.h"
#include "Chara.h"

#define ENEMY_MAX 15

class EnemyMgr : public Chara
{
public:
	EnemyMgr();
	~EnemyMgr();

	void Instance_Enemy();

	void init();
	void Update();
	void Draw();
	void End();

private:
	Enemy *enemy_child[ENEMY_MAX];
};

#endif // !DEF_ENEMYMGR_H
