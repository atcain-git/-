#pragma once
#include "Block.h"
class LZ:public Block
{
public:
	LZ();
	void printblock(HDC &Hdc);
	void Zchangesquare(const bg *ground);
};

