#include "Enemy.h"
#include <cstdlib>
#include "Other.h"
#include "Battle.h"
#include <math.h>


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

Enemy::Enemy(int *pimage_Enemy)
{
	name = eEnemy;
	pos.x = GetRand(SET_SCREENSIZE_X + 1);
	pos.y = 0;
	m_speed = SPEED / 2;

	shotCount = 0;

	image = pimage_Enemy;

	nowMovingX = false;
	nowMovingY = false;
}

void Enemy::Move_AI()
{
	Destination(GetRand(SET_SCREENSIZE_X), GetRand(SET_SCREENSIZE_Y / 2));
}

void Enemy::Destination(const int &destination_x, const int &destination_y)
{
	if (!nowMovingX) {
		nowMovingX = true;
		moveX = destination_x;
		if (pos.x < moveX)
		{
			x_flag = 1;
		}
		if (pos.x > moveX) {
			x_flag = -1;
		}
		if (pos.x == moveX) {
			x_flag = 0;
		}
	}
	if (!nowMovingY) {
		nowMovingY = true;
		moveY = destination_y;
		if (pos.y < moveY)
		{
			y_flag = 1;
		}
		if (pos.y > moveY) {
			y_flag = -1;
		}
		if (pos.y == moveY) {
			y_flag = 0;
		}
	}

	if (nowMovingX) {
		switch (x_flag)
		{
		case 1: {
			if (pos.x < moveX) {
				Move_Right();
			}
			else
			{
				nowMovingX = false;
			}
			break;
		}
		case -1: {
			if (pos.x > moveX) {
				Move_Left();
			}
			else
			{
				nowMovingX = false;
			}
			break;
		}
		case 0: nowMovingX = false; break;
		default:
			break;
		}
	}
	if (nowMovingY) {
		switch (y_flag)
		{
		case 1: {
			if (pos.y < moveY) {
				Move_Down();
			}
			else
			{
				nowMovingY = false;
			}
			break;
		}
		case -1: {
			if (pos.y > moveY) {
				Move_Up();
			}
			else
			{
				nowMovingY = false;
			}
			break;
		}
		case 0: nowMovingY = false; break;
		default:
			break;
		}
	}
}

void Enemy::Update()
{
	if (shotCount >= INT_MAX - 10000) {
		shotCount = 0;
	}

	shotCount += Timecount_return();

	Move_AI();

	if (fabs(Playerpos_return().x - pos.x) < GetRand(100) && shotCount >= SHOT_PACE_ENEMY && GetRand(2) == 0) {
		Ballet_Inst(pos, name);
		shotCount = 0;
	}
}

void Enemy::Draw()
{
	DrawGraph(pos.x, pos.y, *image, true);
}


