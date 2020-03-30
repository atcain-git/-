#include "StdAfx.h"
#include "L.h"


L::L()
{
	//  ■ 
	//  ■■■
	point[0].x = 60;point[0].y = 0;
	point[1].x = 79;point[1].y = 19;
	point[2].x = 60;point[2].y = 20;
	point[3].x = 79;point[3].y = 39;
	point[6].x = 80;point[6].y = 20;
	point[7].x = 99;point[7].y = 39;
	point[4].x = 100;point[4].y = 20;
	point[5].x = 119;point[5].y = 39;
	block[0][0] = 1,block[0][1] = 0,block[0][2] = 0,block[0][3] = 0;
	block[1][0] = 1,block[1][1] = 1,block[1][2] = 1,block[1][3] = 0;
	squareline = 0;
	squarelist = 3;
	squarenum = 3;

}
void L::printblock(HDC &Hdc)
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
void L::Zchangesquare(const bg *ground)
{

	if(1 == ground->background[squareline][squarelist])//0
	{
		change_background();
		point[0].x = 20*(squarelist+2);point[0].y = 20*(squareline);
		point[1].x = 20*(squarelist+2+1)-1;point[1].y = 20*(squareline+1)-1;
		point[2].x = 20*(squarelist+1);point[2].y = 20*(squareline);
		point[3].x = 20*(squarelist+1+1)-1;point[3].y = 20*(squareline+1)-1;
		point[4].x = 20*(squarelist+1);point[4].y = 20*(squareline+1);
		point[5].x = 20*(squarelist+1+1)-1;point[5].y = 20*(squareline+1+1)-1;
		point[6].x = 20*(squarelist+1);point[6].y = 20*(squareline+2);
		point[7].x = 20*(squarelist+1+1)-1;point[7].y = 20*(squareline+2+1)-1;

	}
	else if(1 == ground->background[squareline][squarelist+2])//1
	{
		change_background();
		point[0].x = 20*(squarelist+2);point[0].y = 20*(squareline+2);
		point[1].x = 20*(squarelist+2+1)-1;point[1].y = 20*(squareline+2+1)-1;
		point[2].x = 20*(squarelist+2);point[2].y = 20*(squareline+1);
		point[3].x = 20*(squarelist+2+1)-1;point[3].y = 20*(squareline+1+1)-1;
		point[4].x = 20*(squarelist+1);point[4].y = 20*(squareline+1);
		point[5].x = 20*(squarelist+1+1)-1;point[5].y = 20*(squareline+1+1)-1;
		point[6].x = 20*(squarelist);point[6].y = 20*(squareline+1);
		point[7].x = 20*(squarelist+1)-1;point[7].y = 20*(squareline+1+1)-1;

	}
	else if(1 == ground->background[squareline+2][squarelist+2])//2
	{
		change_background();
		point[0].x = 20*(squarelist);point[0].y = 20*(squareline+2);
		point[1].x = 20*(squarelist+1)-1;point[1].y = 20*(squareline+2+1)-1;
		point[2].x = 20*(squarelist+1);point[2].y = 20*(squareline+2);
		point[3].x = 20*(squarelist+1+1)-1;point[3].y = 20*(squareline+2+1)-1;
		point[4].x = 20*(squarelist+1);point[4].y = 20*(squareline+1);
		point[5].x = 20*(squarelist+1+1)-1;point[5].y = 20*(squareline+1+1)-1;
		point[6].x = 20*(squarelist+1);point[6].y = 20*(squareline);
		point[7].x = 20*(squarelist+1+1)-1;point[7].y = 20*(squareline+1)-1;
	}
	else if(1 == ground->background[squareline+2][squarelist])//3
	{
		change_background();
		point[0].x = 20*(squarelist);point[0].y = 20*(squareline);
		point[1].x = 20*(squarelist+1)-1;point[1].y = 20*(squareline+1)-1;
		point[2].x = 20*(squarelist);point[2].y = 20*(squareline+1);
		point[3].x = 20*(squarelist+1)-1;point[3].y = 20*(squareline+1+1)-1;
		point[4].x = 20*(squarelist+1);point[4].y = 20*(squareline+1);
		point[5].x = 20*(squarelist+1+1)-1;point[5].y = 20*(squareline+1+1)-1;
		point[6].x = 20*(squarelist+2);point[6].y = 20*(squareline+1);
		point[7].x = 20*(squarelist+2+1)-1;point[7].y = 20*(squareline+1+1)-1;

	}
}

