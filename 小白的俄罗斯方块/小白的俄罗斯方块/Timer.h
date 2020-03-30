#pragma once
#include "Block.h"
#include "Z.h"
#include "Shan.h"
#include "Tian.h"
#include "Rct.h"
#include "L.h"
#include "LZ.h"
#include "ZZ.h"

class Timer
{
public:	
	void Init();
	void onPrint(HDC hdc);
	void onReturn(HWND hWnd,int speed);
	void onTimer(HWND hWnd);
	void onLeft(HWND hWnd);
	void onRight(HWND hWnd);
	void onDown(HWND hWnd);
	void onUp(HWND hWnd);
	void onClose(HWND hWnd);
	void getMax();
	//void Random();
private:
	Block *block;// 数据
	static const int DEF_TIME_ID = 1;	// 定时器ID
};