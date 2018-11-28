#ifndef DEF_BALLETMGR
#define DEF_BALLETMGR
#include <DxLib.h>
#include "Ballet.h"
#include "Chara.h"

#define BALLET_MAX 300

class BalletMgr : public Chara
{
public:
	BalletMgr();
	~BalletMgr();

	void Instance_Ballet(const VECTOR&, const eName&);
	Ballet **Get_balletchild();

	void Update();
	void Draw();

private:
	Ballet *ballet_child[BALLET_MAX];
};

#endif // !DEF_BALLETMGR
