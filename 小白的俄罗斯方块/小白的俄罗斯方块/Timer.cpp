#include "StdAfx.h"

#include "Timer.h"

void Timer::Init()
{
	//block->Init();
	//Random();
	//block.draw();
	//block.createBlock();
	block = NULL;
	srand((int)time(0));
	int n = rand() % 7; // 总共很多种方块类型
	switch(n)
	{
	case 0:
		block = new Z;
		break;
	case 1:
		block = new ZZ;
		break;
	case 2:
		block = new Shan;
		break;
	case 3:
		block = new L;
		break;
	case 4:
		block = new LZ;
		break;
	case 5:
		block = new Tian;
		break;
	case 6:
		block = new Rct;
		break;
	}
	block->createBlock(block);
}

void Timer::onPrint(HDC hdc)
{
	HDC Hdc = CreateCompatibleDC(hdc);
	HBITMAP hbitmapback = CreateCompatibleBitmap(hdc, 200, 400);
	SelectObject(Hdc, hbitmapback);

	// 画方块
	block->printblock(Hdc);
	block->printFix(Hdc);
	block->showScore(hdc);
	BitBlt(hdc, 0, 0, 200, 400, Hdc, 0, 0, SRCCOPY);

	DeleteObject(hbitmapback);
	DeleteDC(Hdc);
}

void Timer::onReturn(HWND hWnd,int speed)
{
	if(block->getmark()<50)
	{
		SetTimer(hWnd, DEF_TIME_ID, speed, NULL);
	}
	else if(block->getmark()>=50||block->getmark()<100)
	{
		SetTimer(hWnd, DEF_TIME_ID, speed-100, NULL);
	}
	else if(block->getmark()>=100||block->getmark()<200)
	{
		SetTimer(hWnd, DEF_TIME_ID, speed-200, NULL);
	}

	else{
		SetTimer(hWnd, DEF_TIME_ID, 50, NULL);
	}
}

void Timer::onTimer(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	if ((1 == block->isDown() && 1 == block->isDown_collide()))
	{
		block->fall();
		onPrint(hdc);
	}
	else
	{
		block->Fix();
		block->del();
		if (false == block->isGameOver(hWnd))
		{
			onClose(hWnd);
			//Init();
			return ;
		}
		else{
			if(block!=NULL)
			{
				delete block;
				block = NULL;
				Init();
				onPrint(hdc);
			}
		}
		//block->createBlock(block);
		//Init();

	}
	
	ReleaseDC(hWnd, hdc);

}

void Timer::onLeft(HWND hWnd)
{
	if (block->isLeft() &&block->isLeft_collide())
	{
		HDC hdc = GetDC(hWnd);
		block->MoveLeft();
		onPrint(hdc);
		ReleaseDC(hWnd, hdc);
	}
}

void Timer::onRight(HWND hWnd)
{
	if (block->isRight() && block->isRright_collide())
	{
		HDC hdc = GetDC(hWnd);
		block->MoveRight();
		onPrint(hdc);
		ReleaseDC(hWnd, hdc);
	}
}

void Timer::onDown(HWND hWnd)
{
	onTimer(hWnd);
}

void Timer::onUp(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	block->Zchange();
	onPrint(hdc);
	ReleaseDC(hWnd, hdc);

}

void Timer::onClose(HWND hWnd)
{
	KillTimer(hWnd, DEF_TIME_ID);
	block->releaseDB();
	if(block!=NULL)
	{
		delete block;
		block = NULL;
	}
}
void Timer::getMax()
{
	block->ReadDcu();
}

