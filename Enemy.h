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
	void Move_AI(const int&, const int&);
	void Destination(const int&, const int&);

private:
	int stop_y;
	bool nowMovingX;
	bool nowMovingY;
	int moveX;
	int moveY;
	int x_flag;
	int y_flag;
};

#endif // !DEF_ENEMY_H
