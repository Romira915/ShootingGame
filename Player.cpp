#include <DxLib.h>
#include "Player.h"
#include "Keyboard.h"
#include "Other.h"
#include "Chara.h"
#include "BalletMgr.h"
#include "Battle.h"
#include <climits>


Player::Player()
{
	m_timecount = 0;
	image = new int;
	name = ePlayer;

	pos.x = SET_SCREENSIZE_X / 2;
	pos.y = SET_SCREENSIZE_Y / 2;

	*image = LoadGraph("‰æ‘œ/Ž©‹@.png");
}

Player::~Player()
{
	DeleteGraph(*image);
	delete image;
}

void Player::Update()
{
	// intŒ^‚ÌÅ‘å’l‚ð’´‚¦‚³‚¹‚È‚¢ˆ—
	if (m_timecount >= INT_MAX - 10000) {
		m_timecount = 0;
	}

	m_timecount += Timecount_return();

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

	if (pos.x < 0)
	{
		pos.x = 0;
	}
	if (pos.x > SET_SCREENSIZE_X)
	{
		pos.x = SET_SCREENSIZE_X;
	}
	if (pos.y < SET_SCREENSIZE_Y / 2)
	{
		pos.y = SET_SCREENSIZE_Y / 2;
	}
	if (pos.y > SET_SCREENSIZE_Y)
	{
		pos.y = SET_SCREENSIZE_Y;
	}

	if (Get_key(KEY_INPUT_SPACE) >= 1 && m_timecount >= SHOT_PACE_PLAYER) {
		Ballet_Inst(pos, name);
		m_timecount = 0;
	}
}

void Player::Draw()
{
	DrawGraph(pos.x, pos.y, *image, true);
}