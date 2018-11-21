#ifndef DEF_ENEMY_H
#define DEF_ENEMY_H
#include "Chara.h"

class Enemy : public Chara
{
public:
	Enemy();
	~Enemy();
	Enemy(int*);

	void init();
	void Update();
	void Draw();
	void End();

	VECTOR Get_pos();

private:
};

#endif // !DEF_ENEMY_H
