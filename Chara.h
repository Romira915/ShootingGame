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

	virtual void Update() = 0;
	virtual void Draw() = 0;

	VECTOR Get_pos();
	int *Get_ptrimageHandle();

	bool Death_is_true();
	void Damage();

protected:
	void Move_Up();
	void Move_Down();
	void Move_Right();
	void Move_Left();

	VECTOR pos;
	int m_hp;
	int *image;
	float m_speed;
};

#endif // !DEF_CHARA_H
