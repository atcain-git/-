// С�׵Ķ���˹����.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>
#include "С�׵Ķ���˹����.h"
#include "conio.h"
#include "time.h"
#include "Timer.h"
#include <locale> 
#define MAX_LOADSTRING 100

// ȫ�ֱ���:
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

// �˴���ģ���а����ĺ�����ǰ������:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,//���ļ���·��
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY));

	// ����Ϣѭ��:
	//6����Ϣѭ��==��windows ��Ϣ����
	while (GetMessage(&msg, NULL, 0, 0))
	{

		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			//���������Ϣת��Ϊ�ַ���Ϣ
			TranslateMessage(&msg);
			//����Ϣ�ַ������ڴ����� 
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
//  ע��:
//
//    ����ϣ��
//    �˴�������ӵ� Windows 95 �еġ�RegisterClassEx��
//    ����֮ǰ�� Win32 ϵͳ����ʱ������Ҫ�˺��������÷������ô˺���ʮ����Ҫ��
//    ����Ӧ�ó���Ϳ��Ի�ù�����
//    ����ʽ��ȷ�ġ�Сͼ�ꡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	//1����ƴ�����
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;//������ķ��
	wcex.lpfnWndProc	= WndProc;//���ڴ�����
	wcex.cbClsExtra		= 0;//������Ķ���ռ��С
	wcex.cbWndExtra		= 0;//������չ�ռ��С
	wcex.hInstance		= hInstance;//��ǰӦ�ó���ʵ�����
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);//���λ��
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);//���ر���
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MY);//�˵���
	wcex.lpszClassName	= szWindowClass;//����������
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	//2��ע�ᴰ����
	return RegisterClassEx(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��:
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����
	//3����������
	/************************************************************************/
	/* CreateWindow(szWindowClass ����������, szTitle/*���ڱ���*/ //, WS_OVERLAPPEDWINDOW//���ڷ��,
	//   300, 200 ���Ͻ�����, 490, 640//���ڿ��, 
	//NULL�����ھ��, NULL//�˵����, hInstanceӦ�ó���ʵ�������
	//, NULL����);                                                                     */
	/************************************************************************/
	//    hWnd = CreateWindow(szWindowClass, szTitle/*��������*/, WS_OVERLAPPEDWINDOW,
	//       CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
	hWnd =  CreateWindow(szWindowClass /*����������*/, szTitle/*���ڱ���*/ , WS_OVERLAPPEDWINDOW/*���ڷ��*/,
		0, 0 /*���Ͻ�����*/, 365, 458/*���ڿ��*/, 
		NULL/*�����ھ��*/, NULL/*�˵����*/, hInstance/*Ӧ�ó���ʵ�������*/
		, NULL/*����*/);                                            
	if (!hWnd)
	{
		return FALSE;
	}
	//4����ʾ����
	ShowWindow(hWnd, nCmdShow);
	//5�����´���
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��: ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static Timer timer;
	switch (message)
	{
	case WM_CREATE:
		timer.Init();
		timer.onReturn(hWnd,500);
		break;

	case WM_TIMER:
		timer.onTimer(hWnd);
		break;

	case WM_PAINT:
		{
			PAINTSTRUCT pt;
			HDC hdc = BeginPaint(hWnd, &pt);
			timer.onPrint(hdc);					
			EndPaint(hWnd, &pt);
			break;
		}

	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_SPACE:
		case VK_RETURN:         
			timer.onReturn(hWnd,500);
			break;
		case VK_LEFT:           
			timer.onLeft(hWnd);
			break;
		case VK_RIGHT:          
			timer.onRight (hWnd);
			break;
		case VK_DOWN:   
			//timer.onReturn(hWnd);
			timer.onDown(hWnd);
			break;
		case VK_UP:             
			timer.onUp(hWnd);
			break;
		}
	case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
			case IDC_easy:
				timer.onReturn(hWnd,500);
				break;
			case IDR_common:
				timer.onReturn(hWnd,300);
				break;
			case IDC_diff:
				timer.onReturn(hWnd,200);
				break;
			case IDC_VIP:
				timer.getMax();
				break;
			}

		}
		break;

	case WM_CLOSE:
	case WM_DESTROY:

		timer.onClose(hWnd);
		PostQuitMessage(0);
		break;


	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}




