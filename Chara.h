#ifndef DEF_CHARA_H
#define DEF_CHARA_H
#include <DxLib.h>
#define SPEED 4.5

typedef enum { ePlayer, eEnemy, eEnemyMgr, eBallet, eBalletMgr, }eName;

class Chara
{
public:
	Chara();
	~Chara();

	eName name;

	virtual void init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	void Move_Up();
	void Move_Down();
	void Move_Right();
	void Move_Left();

	VECTOR Get_pos();

	bool Death_is_true();

protected:
	VECTOR pos;
	int *image;
	int m_hp;
	float m_speed;
};

#endif // !DEF_CHARA_H
