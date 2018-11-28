#ifndef DEF_BALLET_H
#define DEF_BALLET_H
#include "Chara.h"
#include <DxLib.h>


class Ballet :public Chara
{
public:
	Ballet();
	~Ballet();
	Ballet(const VECTOR&, const eName&, int*);

	VECTOR Get_pos(eName *shot_name);
	eName Get_isInsted();

	void Update();
	void Draw();

private:
	eName is_Insted;
};

#endif // !DEF_BALLET_H
