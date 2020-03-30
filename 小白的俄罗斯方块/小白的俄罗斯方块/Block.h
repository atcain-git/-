#pragma once
#include <windows.h>
#include "bg.h"
class Block
{
public:
	void Init();
	int createBlock(Block *p);
	void Fix();
	virtual void printblock(HDC &Hdc)=0 ;
	void printFix(HDC &Hdc);
	void fall();
	void MoveLeft();
	void MoveRight();
	void del();
	void Zchange();
	void change_background();
	virtual void Zchangesquare(const bg *ground) = 0;
	void Zchangesquare1();
	void Zchangesquare2();
	void Zchangesquare3();
	void Zchangesquare4();
	int  Zchangesquarecan();
	void Zchangesquare6();
	int  Zchangesquare6can();
	bool isDown();
	bool isDown_collide();
	bool isGameOver(HWND hWnd);
	bool isLeft();
	bool isRight();
	bool isLeft_collide();	
	bool isRright_collide();	
	bool isFull(int a);
	int getSquarenum();
	int getmark();
	void showScore(HDC & Hdc);
	void wirteDcu(HWND hwnd,int mark);
	int ReadDcu();
	void releaseDB();
protected:
	int squarenum;
	int squareline;
	int squarelist;
protected:
	POINT point[8];//记录方块坐标  用于画图
	int block[2][4]; //记录方块状态
	int num ;
};

