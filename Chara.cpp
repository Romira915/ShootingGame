#include "Chara.h"
#include <DxLib.h>

Chara::Chara()
{
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	m_speed = SPEED;
	m_hp = 1;
}

Chara::~Chara()
{
}

void Chara::Move_Up()
{
	pos.y -= m_speed;
}

void Chara::Move_Down()
{
	pos.y += m_speed;
}

void Chara::Move_Right()
{
	pos.x += m_speed;
}

void Chara::Move_Left()
{
	pos.x -= m_speed;
}

VECTOR Chara::Get_pos()
{
	return pos;
}

bool Chara::Death_is_true()
{
	if (m_hp <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
