#ifndef DEF_PLAYER_H
#define DEF_PLAYER_H
#include "Chara.h"

#define SHOT_PACE 150 // [ms]

class Player : public Chara
{
public:
	Player();
	~Player();
	void init();
	void Update();
	void Draw();
	void End();

private:
	int m_timecount;
};

#endif // !DEF_PLAYER_H
