#include "stdafx.h"
#include "Block.h"
#include <cstring>
#include "Z.h"
bg *ground = new bg;
//�����������
int Block::createBlock(Block *p)
{

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ground->background[i][j + 3] = p->block[i][j];
		}
	}
	return 0;
}


void Block::printFix(HDC & Hdc)
{
	HGDIOBJ oldBrush;
	HGDIOBJ newBrush = CreateSolidBrush(RGB(0, 255, 127));
	oldBrush = SelectObject(Hdc, newBrush);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (2 == ground->background[i][j])
			{
				Rectangle(Hdc, j * 20, i * 20, j * 20 + 19, i * 20 + 19);
			}
		}
	}

	newBrush = SelectObject(Hdc, oldBrush);
	DeleteObject(newBrush);
}

void Block::Fix()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == ground->background[i][j])
			{
				ground->background[i][j] = 2;
				num = 0;
			}
		}
	}
}

bool Block::isDown()
{
	for (int i = 0; i < 10; i++)
	{
		if (1 == ground->background[19][i])
		{
			return false;
		}
	}
	return true;
}

bool Block::isDown_collide()
{
	for (int i = 19; i >= 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == ground->background[i][j])
			{
				if (2 == ground->background[i + 1][j])
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool Block::isLeft()
{
	for (int i = 0; i < 20; i++)
	{
		if (1 == ground->background[i][0])
		{
			return false;
		}
	}
	return true;
}

bool Block::isLeft_collide()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == ground->background[i][j])
			{
				if (2 == ground->background[i][j - 1])
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool Block::isRight()
{
	for (int i = 0; i < 20; i++)
	{
		if (1 == ground->background[i][9])
		{
			return false;
		}
	}
	return true;
}

bool Block::isRright_collide()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 9; j >= 0; j--)
		{
			if (1 == ground->background[i][j])
			{
				if (2 == ground->background[i][j + 1])
				{
					return false;
				}
			}
		}
	}
	return true;
}



void Block::fall()
{

	for(int i =0;i	<	sizeof(point)/sizeof(POINT); i++)
	{
		point[i].y +=	20;
	}
	for (int i = 19; i >= 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == ground->background[i][j])
			{
				ground->background[i + 1][j] = ground->background[i][j];
				ground->background[i][j] = 0;
			}
		}
	}

	squareline++;

}

void Block::MoveLeft()
{
	for(int i =0;i<sizeof(point)/sizeof(POINT);i++)
	{
		point[i].x-=20;
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == ground->background[i][j])
			{
				ground->background[i][j - 1] = ground->background[i][j];
				ground->background[i][j] = 0;
			}
		}
	}
	squarelist--;

}

void Block::MoveRight()
{
	for(int i =0;i<sizeof(point)/sizeof(POINT);i++)
	{
		point[i].x+=20;
	}



	for (int i = 0; i < 20; i++)
	{
		for (int j = 9; j >= 0; j--)
		{
			if (1 == ground->background[i][j])
			{
				ground->background[i][j + 1] = ground->background[i][j];
				ground->background[i][j] = 0;
			}
		}
	}
	squarelist++;

}


bool Block::isFull(int a)
{
	int n = 0;
	for(int j = 0;j<10;j++)
	{
		if(ground->background[a][j] == 2 )
		{
			n++;
		}
	}
	if(n == 10)
	{
		ground->addmark(10);
		return true;
	}

	return false;
}

void Block::del()//����
{
	for(int i = 0;i<20;i++)
	{
		if(isFull(i))
		{
			for(int n=i;n>=0;n--)
			{
				for(int j = 0;j<10;j++)
				{
					ground->background[n][j] = ground->background[n-1][j];
				}
			}
			for(int i2 = 0;i2<10;i2++)
			{
				ground->background[0][i2] = 0;
			}
		}
	}

	
}

bool Block::isGameOver(HWND hWnd)
{
	for (int i = 0; i < 10; i++)
	{
		if (2 == ground->background[1][i] || 1 == ground->background[1][i]|| 2 == ground->background[0][i]||1 == ground->background[0][i] )
		{
			TCHAR szBuffer[1024];
			LPCTSTR str = TEXT("��ϲ����: %d��");
			wsprintf(szBuffer, str,ground->getmark() );
			wirteDcu(hWnd,ground->getmark());
			MessageBox(NULL, szBuffer , TEXT("gameover"), MB_RETRYCANCEL);
			releaseDB();
			return false;
		}
	}
	return true;
}

void Block::Zchange()
{

	switch(squarenum)
	{
	case 0:
		if(1==Zchangesquarecan())
		{
			Zchangesquare(ground);
		}
		else
		{
			return ;
		}
		break;
	case 1:
		if(1==Zchangesquarecan())
		{
			Zchangesquare(ground);
		}
		else
		{
			return ;
		}
		break;
	case 2:
		if(1==Zchangesquarecan())
		{
			Zchangesquare(ground);
		}
		else
		{
			return ;
		}
		break;
	case 3:
		if(1==Zchangesquarecan())
		{
			Zchangesquare(ground);
		}
		else
		{
			return ;
		}
		break;
	case 4:
		if(1==Zchangesquarecan())
		{
			Zchangesquare(ground);
		}
		else
		{
			return ;
		}
		break;
	case 5:
		return;
	case 6:
		if(1==Zchangesquare6can())
		{
			Zchangesquare6();
		}
		else
		{
			return;
		}
		break;
	}
}
void Block::change_background()
{
	int x = 0;
	int y = 0;
	int twoline = 2;
	int Zremblock[3][3]={0};
	for(x = 0 ;x < 3;x++)
	{
		for(y = 0;y <3 ;y++)
		{
			Zremblock[x][y] = ground->background[squareline+x][squarelist+y];
		}
	}
	for( x = 0;x < 3;x++)
	{
		for(y = 0;y < 3;y++)
		{
			ground->background[squareline+x][squarelist+y] = Zremblock[twoline][x];
			twoline--;
		}
		twoline=2;
	}
}

int Block::Zchangesquarecan()
{
	int x = 0;
	int y = 0;
	for(x=0;x<3;x++)
	{
		for(y=0;y<3;y++)
		{
			if(2==ground->background[squareline+x][squarelist+y])
			{
				return 0;
			}
		}
	}
	if( squareline >= 17)
	{
		return 0;
	}
	if( squarelist<=-1 ||squarelist>=8)
	{
		return 0;
	}
	return 1;

}
void Block::Zchangesquare6()
{
	if(1 == ground->background[squareline][squarelist-1])
	{
		if(2 == ground->background[squareline+1][squarelist]||2==ground->background[squareline+2][squarelist])
		{
			return;
		}
		else
		{	

			ground->background[squareline][squarelist-1]=0;
			ground->background[squareline][squarelist+1]=0;
			ground->background[squareline][squarelist+2]=0;
			ground->background[squareline-1][squarelist]=1;
			ground->background[squareline+1][squarelist]=1;
			ground->background[squareline+2][squarelist]=1;
			point[0].y = 20*(squareline-1);point[0].x = 20*(squarelist);
			point[1].y = 20*(squareline-1)+20-1;point[1].x = 20*(squarelist)+20-1;
			point[4].y = 20*(squareline+1);point[4].x = 20*(squarelist);
			point[5].y = 20*(squareline+1)+20-1;point[5].x = 20*(squarelist)+20-1;
			point[6].y = 20*(squareline+2);point[6].x = 20*(squarelist);
			point[7].y = 20*(squareline+2)+20-1;point[7].x = 20*squarelist+20-1;
		}
	}
	else
	{
		if(2 == ground->background[squareline][squarelist+1] || 2 == ground->background[squareline][squarelist+2] || 2 == ground->background[squareline][squarelist-1])
		{
			return;
		}
		else
		{
			point[0].y = 20*squareline;			point[0].x = 20*(squarelist-1);
			point[1].y = (20*squareline)+20-1;	point[1].x = 20*(squarelist-1)+20-1;
			point[4].y = 20*squareline;			point[4].x = 20*(squarelist+1);
			point[5].y = (20*squareline)+20-1;	point[5].x = 20*(squarelist+1)+20-1;
			point[6].y = 20*squareline;			point[6].x = 20*(squarelist+2);
			point[7].y = (20*squareline)+20-1;	point[7].x = 20*(squarelist+2)+20-1;
			ground->background[squareline][squarelist-1]=1;
			ground->background[squareline][squarelist+1]=1;
			ground->background[squareline][squarelist+2]=1;

			ground->background[squareline-1][squarelist]=0;
			ground->background[squareline+1][squarelist]=0;
			ground->background[squareline+2][squarelist]=0;
		}
	}
}
int Block::Zchangesquare6can()
{
	if(squareline<18 && squareline>0 && squarelist>0 && squarelist<8)//�߽粻�ɱ�
	{
		return 1;
	}
	return 0;
}

int Block::getSquarenum()
{
	return this->squarenum;
}
int Block::getmark()
{
	return ground->getmark();
}
void Block::showScore(HDC & Hdc)
{
	Rectangle(Hdc, 200, 0, 350, 400);
	char strScore[10];
	memset(strScore,0,sizeof(strScore));
	_itoa(ground->getmark(),(char*)strScore, 10);
	TextOut(Hdc, 250, 80, TEXT("����"), strlen("����"));
	TextOut(Hdc, 270, 100, strScore, strlen(strScore));
	TextOut(Hdc,210, 195, TEXT("����˹������Ϸ����"), strlen(TEXT("����˹������Ϸ����")));
	TextOut(Hdc,235, 240, TEXT("���ϱ���"), strlen("���ϱ���"));
	TextOut(Hdc, 235, 260, TEXT("���¼���"), strlen("���¼���"));
	TextOut(Hdc, 235, 280, TEXT("����������"), strlen("����������"));
	TextOut(Hdc, 235, 300, TEXT("����������"), strlen("����������"));
}
void Block::wirteDcu(HWND hwnd,int mark)
{
	TCHAR writeFile[] = _T("d://a.txt");
	HANDLE wFile = CreateFile(writeFile, //�����ļ������ơ�
		GENERIC_WRITE,        // GENERIC_WRITE | GENERIC_READ, д�Ͷ��ļ��� 
		0,     // ������
		NULL,             // ȱʡ��ȫ����
		OPEN_ALWAYS,    // CREATE_ALWAYS  �����ļ����������򴴽���    OPEN_EXISTING ���ļ����������򱨴�
		FILE_ATTRIBUTE_NORMAL,  // һ����ļ���
		NULL);    // ģ���ļ�Ϊ�ա�
	GetLastError();
	DWORD dwreturnsize;
	wchar_t p[5];
	memset(p,0,sizeof(p));
	_itoa(mark,(char*) p, 10);
	p[4]='\0';
	WriteFile(wFile, p, sizeof(p), &dwreturnsize, NULL);
	//WriteFile(wFile, &s, 1, &dwreturnsize, NULL);
	CloseHandle(wFile);//�ر��ļ�
}
int Block::ReadDcu()
{
	TCHAR szFile[] = _T("d://a.txt");
	HANDLE hFile = CreateFile(szFile, //�����ļ������ơ�
		GENERIC_READ,        // GENERIC_WRITE | GENERIC_READ, д�Ͷ��ļ��� 
		FILE_SHARE_READ,     // �������
		NULL,             // ȱʡ��ȫ����
		OPEN_EXISTING,    // CREATE_ALWAYS  �����ļ����������򴴽���    OPEN_EXISTING ���ļ����������򱨴�
		FILE_ATTRIBUTE_NORMAL,  // һ����ļ���
		NULL);    // ģ���ļ�Ϊ�ա�
	if (hFile == INVALID_HANDLE_VALUE)  //��Чֵ
	{
		OutputDebugString(TEXT("CreateFile fail!\r\n"));
		return 0;
	}

	DWORD dwSize = GetFileSize(hFile, NULL); //��ȡ�ļ���С
	//cout << "dwSize=" << dwSize << endl;
	char cBuf[5];          //�ڶ��Ͽ��ٻ��������ȴ������ļ�����
	memset(cBuf,0,sizeof(cBuf));
	//SetFilePointer(hFile, 10, NULL, FILE_BEGIN);
	DWORD haveReadByte;
	ReadFile(hFile, cBuf, 4, &haveReadByte, 0);

	int num = MultiByteToWideChar(0,0,cBuf,-1,NULL,0);
	MessageBox(NULL,cBuf, TEXT("��Ѽ�¼"), MB_OK);
	CloseHandle(hFile);
	return 0;
}
void Block::releaseDB()
{
	if(ground != NULL)
	{
		delete ground;
		ground = NULL;
	}
}