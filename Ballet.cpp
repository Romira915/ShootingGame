#include <DxLib.h>
#include "Ballet.h"
#include "Battle.h"
#include "Chara.h"

Ballet::Ballet()
{
	name = ballet;
	m_speed = SPEED * 2;
}


Ballet::~Ballet()
{
}

Ballet::Ballet(const VECTOR &pos_Inst, const eName &name_Inst)
{
	name = ballet;
	m_speed = SPEED * 2;
	pos = pos_Inst;
	is_Insted = name_Inst;
}

void Ballet::init()
{

}

void Ballet::Update()
{
	if (is_Insted == player) {
		pos.y -= m_speed;
	}
	if (is_Insted == enemy) {
		pos.y += m_speed;
	}
}

void Ballet::Draw()
{
	
}

void Ballet::End()
{
}

void Ballet::Instance_this(const VECTOR &pos_Inst,const eName &name_Inst)
{
	pos = pos_Inst;
	is_Insted = name_Inst;
}

void Ballet::Move_direction(const VECTOR &pos, const eName &name_Md)
{

}
