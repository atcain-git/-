// 小白的俄罗斯方块.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include "小白的俄罗斯方块.h"
#include "conio.h"
#include "time.h"
#include "Timer.h"
#include <locale> 
#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,//打开文件的路径
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY));

	// 主消息循环:
	//6、消息循环==》windows 消息机制
	while (GetMessage(&msg, NULL, 0, 0))
	{

		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			//将虚拟键消息转换为字符消息
			TranslateMessage(&msg);
			//将消息分发给窗口处理函数 
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
//  注释:
//
//    仅当希望
//    此代码与添加到 Windows 95 中的“RegisterClassEx”
//    函数之前的 Win32 系统兼容时，才需要此函数及其用法。调用此函数十分重要，
//    这样应用程序就可以获得关联的
//    “格式正确的”小图标。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	//1、设计窗口类
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;//窗口类的风格
	wcex.lpfnWndProc	= WndProc;//窗口处理函数
	wcex.cbClsExtra		= 0;//窗口类的额外空间大小
	wcex.cbWndExtra		= 0;//窗口扩展空间大小
	wcex.hInstance		= hInstance;//当前应用程序实例句柄
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);//光标位置
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);//加载背景
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MY);//菜单名
	wcex.lpszClassName	= szWindowClass;//窗口类型名
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	//2、注册窗口类
	return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // 将实例句柄存储在全局变量中
	//3、创建窗口
	/************************************************************************/
	/* CreateWindow(szWindowClass 窗口类型名, szTitle/*窗口标题*/ //, WS_OVERLAPPEDWINDOW//窗口风格,
	//   300, 200 左上角坐标, 490, 640//窗口宽高, 
	//NULL父窗口句柄, NULL//菜单句柄, hInstance应用程序实例化句柄
	//, NULL参数);                                                                     */
	/************************************************************************/
	//    hWnd = CreateWindow(szWindowClass, szTitle/*窗口名字*/, WS_OVERLAPPEDWINDOW,
	//       CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
	hWnd =  CreateWindow(szWindowClass /*窗口类型名*/, szTitle/*窗口标题*/ , WS_OVERLAPPEDWINDOW/*窗口风格*/,
		0, 0 /*左上角坐标*/, 365, 458/*窗口宽高*/, 
		NULL/*父窗口句柄*/, NULL/*菜单句柄*/, hInstance/*应用程序实例化句柄*/
		, NULL/*参数*/);                                            
	if (!hWnd)
	{
		return FALSE;
	}
	//4、显示窗口
	ShowWindow(hWnd, nCmdShow);
	//5、更新窗口
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
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

// “关于”框的消息处理程序。
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




