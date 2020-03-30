#include "StdAfx.h"
#include "bg.h"


bg::bg()
{
	for(int i =0;i<20;i++)
	{
		for(int j = 0;j<10;j++)
		{
			background[i][j] = 0;
		}
	}
	mark = 0;
}
int bg::addmark(int num)
{
	return this->mark = this->mark + num;
}
int bg::getmark()
{
	return this->mark;
}


