///////////////////////////////////////////////////////////
//  Hello.cpp
//  Implementation of the Class Hello
//  Created on:      15-十月-2016 11:20:10
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "Hello.h"


Hello::Hello(){

}



Hello::~Hello(){

}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow){
	AllocConsole();
	SetConsoleTitle("");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w+t", stdout);

	MSG Message;
	if (!InitWindowsClass(hInstance)){
		return FALSE;
	}

	if (!InitWindows(hInstance, nCmdShow)){
		return FALSE;
	}

	while (GetMessage(&Message,0,0,0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return(Message.wParam);
}

long WINAPI WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam){
	HDC hDC;
	HBRUSH hBrush;
	HPEN hPen;
	PAINTSTRUCT PtStr;

	POINT points[6] = {
		{100,212}, {70,227}, {70,250}, {130,250}, {130,227}, {100,212}
	};

	switch (iMessage)
	{
		case WM_PAINT:
			hDC = BeginPaint(hWnd, &PtStr);
			hPen =(HPEN) GetStockObject(NULL_PEN);
			std::cout << "hPen : " << hPen << std::endl;
			SelectObject(hDC, hPen);
			hBrush = (HBRUSH) GetStockObject(BLACK_BRUSH);
			SelectObject(hDC, hBrush);
			LineTo(hDC, 50, 50);
			DeleteObject(hPen);
			hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
			SelectObject(hDC, hPen);

			LineTo(hDC, 150, 50);
			LineTo(hDC, 100, 137);
			LineTo(hDC, 50, 50);
			Polyline(hDC, points, 6);
			Arc(hDC, 63, 137, 138, 212, 100, 137, 100, 137);
			Pie(hDC, 213, 137, 288, 212, 240, 137, 260, 137);
			Rectangle(hDC, 213, 212, 287, 250);
			RoundRect(hDC, 213, 100, 287, 137, 20, 20);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			EndPaint(hWnd, &PtStr);
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		default:
			return DefWindowProc(hWnd, iMessage, wParam, lParam);
	}
}

BOOL InitWindows(HINSTANCE hInstance, int nCmdShow){
	HWND hWnd;
	hWnd = CreateWindow("WinFill", "填充示例程序", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
	if (!hWnd){
		return FALSE;
	}
	hWndMain = hWnd;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

BOOL InitWindowsClass(HINSTANCE hInstance){
	WNDCLASS WndClass;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, "END");
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = "WinFill";
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	return RegisterClass(&WndClass);
}