#include <DxLib.h>
#include "Player.h"
#include "Keyboard.h"
#include "Other.h"
#include "Chara.h"


Player::Player()
{
	m_timecount = 0;
	name = player;
}

Player::~Player()
{
}

void Player::init()
{
	*image = LoadGraph("‰æ‘œ/Ž©‹@.png");
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
}

void Player::Draw()
{
	DrawGraph(pos.x, pos.y, *image, true);
}

void Player::End()
{
	DeleteGraph(*image);
}
