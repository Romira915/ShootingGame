#ifndef DEF_ENEMY_H
#define DEF_ENEMY_H
#include "Chara.h"

#define SHOT_PACE_ENEMY 300

class Enemy : public Chara
{
public:
	Enemy();
	~Enemy();
	Enemy(int*);

	void Move_AI();
	void Destination(const int&, const int&);

	void Update();
	void Draw();

private:
	int stop_y;
	bool nowMovingX;
	bool nowMovingY;
	int moveX;
	int moveY;
	int x_flag;
	int y_flag;

	int shotCount;
};

#endif // !DEF_ENEMY_H
