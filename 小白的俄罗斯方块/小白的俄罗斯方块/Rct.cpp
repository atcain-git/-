#include "StdAfx.h"
#include "Rct.h"

Rct::Rct()
{
	point[0].x = 60;point[0].y = 0;
	point[1].x = 79;point[1].y = 19;
	point[2].x = 80;point[2].y = 0;
	point[3].x = 99;point[3].y = 19;
	point[4].x = 100;point[4].y = 0;
	point[5].x = 119;point[5].y = 19;
	point[6].x = 120;point[6].y = 0;
	point[7].x = 139;point[7].y = 19;
	block[0][0] = 1,block[0][1] = 1,block[0][2] = 1,block[0][3] = 1;
	block[1][0] = 0,block[1][1] = 0,block[1][2] = 0,block[1][3] = 0;
	squareline = 0;
	squarelist = 4;
	squarenum = 6;

}
void Rct::printblock(HDC &Hdc)
{

	Rectangle(Hdc, 0, 0, 200, 400);
	HBRUSH oldBrush;
	HBRUSH newBrush = CreateSolidBrush(RGB(141, 238, 238));//将画笔改成红色
	oldBrush = (HBRUSH)SelectObject(Hdc, newBrush);//保存之前的画笔颜色
	for(int i = 0;i < sizeof(point)/sizeof(POINT);i = i + 2)
	{
		Rectangle(Hdc,point[i].x,point[i].y,point[i+1].x,point[i+1].y);
	}
	newBrush = (HBRUSH)SelectObject(Hdc, oldBrush);
	DeleteObject(newBrush);
}
void Rct::Zchangesquare(const bg *ground)
{

}