#include <DxLib.h>
#include "Ballet.h"
#include "Battle.h"
#include "Chara.h"

Ballet::Ballet()
{
}


Ballet::~Ballet()
{
}

Ballet::Ballet(const VECTOR &pos_Inst, const eName &name_Inst, int *pimage_ballet)
{
	name = eBallet;
	m_speed = SPEED * 2;
	pos = pos_Inst;
	pos.x += 20; // プレイヤーの先端から弾が発射されるように調整

	is_Insted = name_Inst;
	image = pimage_ballet;
}

void Ballet::init()
{

}

void Ballet::Update()
{
	if (is_Insted == ePlayer) {
		Move_Up();
	}
	if (is_Insted == eEnemy) {
		Move_Down();
	}
}

void Ballet::Draw()
{
	DrawGraph(pos.x, pos.y, *image, true);
}

void Ballet::End()
{
}

VECTOR Ballet::Get_pos()
{
	return pos;
}
