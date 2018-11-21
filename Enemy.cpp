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
	stop_y = (int)(rand() % (int)(SET_SCREENSIZE_Y * 0.5 / 3) * 3);

	image = pimage_Enemy;
}

void Enemy::init()
{
}

void Enemy::Update()
{
	//Move_AI();
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

void Enemy::Move_AI(const int &destX, const int &destY)
{
	static int moveCount = 0;
	moveCount += Timecount_return();

	if (moveCount >= GetRand(10000) + 10000) {
		Destination(destX, destY);
	}
}

void Enemy::Destination(const int &destination_x, const int &destination_y)
{
	static bool nowUsing = false; // Žg—p’†‚È‚çtrue
	static bool nowMovingX = false;
	static bool nowMovingY = false;
	static int moveX;
	static int moveY;
	static int x_flag;
	static int y_flag;

	/*if (!nowUsing)
	{
		nowUsing = true;
		nowMovingX = true;
		nowMovingY = true;
		moveX = destination_x;
		moveY = destination_y;
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
	}*/

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


	/*if (!nowMovingX && !nowMovingY) {
		nowUsing = false;
	}*/
}


