#include "BalletMgr.h"



BalletMgr::BalletMgr()
{
	name = eBalletMgr;
	for (int i = 0; i < BALLET_MAX; i++)
	{
		ballet_child[i] = NULL;
	}
}


BalletMgr::~BalletMgr()
{
}

void BalletMgr::Instance_Ballet(const VECTOR &, const eName &)
{
}

void BalletMgr::Update()
{
}
