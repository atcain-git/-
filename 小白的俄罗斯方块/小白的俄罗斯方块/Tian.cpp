#include "StdAfx.h"
#include "Tian.h"


Tian::Tian()
{
	//   ����
	//   ����
	point[0].x = 60;point[0].y = 0;
	point[1].x = 79;point[1].y = 19;
	point[2].x = 80;point[2].y = 0;
	point[3].x = 99;point[3].y = 19;
	point[4].x = 60;point[4].y = 20;
	point[5].x = 79;point[5].y = 39;
	point[6].x = 80;point[6].y = 20;
	point[7].x = 99;point[7].y = 39;
	block[0][0] = 1,block[0][1] = 1,block[0][2] = 0,block[0][3] = 0;
	block[1][0] = 1,block[1][1] = 1,block[1][2] = 0,block[1][3] = 0;
	squareline = 0;
	squarelist = 0;
	squarenum = 5;//ɾ����Ӱ��

}
void Tian::printblock(HDC &Hdc)
{

	Rectangle(Hdc, 0, 0, 200, 400);
	HBRUSH oldBrush;
	HBRUSH newBrush = CreateSolidBrush(RGB(141, 238, 238));//�����ʸĳɺ�ɫ
	oldBrush = (HBRUSH)SelectObject(Hdc, newBrush);//����֮ǰ�Ļ�����ɫ

	for(int i = 0;i < sizeof(point)/sizeof(POINT);i = i + 2)
	{
		Rectangle(Hdc,point[i].x,point[i].y,point[i+1].x,point[i+1].y);
	}
	newBrush = (HBRUSH)SelectObject(Hdc, oldBrush);
	DeleteObject(newBrush);
}
void Tian::Zchangesquare(const bg *ground)
{
	return ;
}



