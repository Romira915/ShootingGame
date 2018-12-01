#ifndef DEF_PLAYER_H
#define DEF_PLAYER_H
#include "Chara.h"

#define SHOT_PACE_PLAYER 150 // [ms]

class Player : public Chara
{
public:
	Player();
	~Player();

	void Update();
	void Draw();

private:
	int m_timecount;
	int image_width;
	int image_height;
};

#endif // !DEF_PLAYER_H
