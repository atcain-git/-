#pragma once
#include "Block.h"
class Rct :public Block
{
public:
	Rct();
	void printblock(HDC &Hdc);
	void Zchangesquare(const bg *ground);
};

