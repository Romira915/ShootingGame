#include "Enemy.h"
#include <cstdlib>
#include "Other.h"


Enemy::Enemy()
{
	srand(GetNowCount());
	pos.x = rand() % (SET_SCREENSIZE_X + 1);
	pos.y = 0;
}


Enemy::~Enemy()
{
}

Enemy::Enemy(int *pimage_Enemy)
{
	name = eEnemy;
	srand(GetNowCount());
	pos.x = rand() % (SET_SCREENSIZE_X + 1);
	pos.y = 0;

	image = pimage_Enemy;
}

void Enemy::init()
{
}

void Enemy::Update()
{
	Move_Down();
}

void Enemy::Draw()
{
	DrawGraph(pos.x, pos.y, *image, true);
}

void Enemy::End()
{
}

VECTOR Enemy::Get_pos()
{
	return pos;
}
