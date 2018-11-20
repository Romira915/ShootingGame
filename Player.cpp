#include <DxLib.h>
#include "Player.h"
#include "Keyboard.h"
#include "Other.h"
#include "Chara.h"
#include "BalletMgr.h"
#include "Battle.h"


Player::Player()
{
	m_timecount = 0;
	name = ePlayer;
}

Player::~Player()
{
}

void Player::init()
{
	image = new int;
	*image = LoadGraph("‰æ‘œ/Ž©‹@.png");
	name = ePlayer;
}

void Player::Update()
{
	if (Get_key(KEY_INPUT_A) >= 1) {
		Move_Left();
	}
	if (Get_key(KEY_INPUT_D) >= 1) {
		Move_Right();
	}
	if (Get_key(KEY_INPUT_W) >= 1) {
		Move_Up();
	}
	if (Get_key(KEY_INPUT_S) >= 1) {
		Move_Down();
	}
	if (Get_key(KEY_INPUT_SPACE) >= 1) {
		BalletMgr_Inst(pos, name);
	}
}

void Player::Draw()
{
	DrawGraph(pos.x, pos.y, *image, true);
}

void Player::End()
{
	DeleteGraph(*image);
	delete image;
}
