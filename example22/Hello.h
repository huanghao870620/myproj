///////////////////////////////////////////////////////////
//  Hello.h
//  Implementation of the Class Hello
//  Created on:      15-Ê®ÔÂ-2016 11:20:10
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_0EDA6DC8_C8D6_4d42_9A0E_7B6FC9C8EB6C__INCLUDED_)
#define EA_0EDA6DC8_C8D6_4d42_9A0E_7B6FC9C8EB6C__INCLUDED_
#include<afxwin.h>
#include<iostream>

long WINAPI WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam);
BOOL InitWindowsClass(HINSTANCE hInstance);
BOOL InitWindows(HINSTANCE hInstance, int nCmdShow);

HWND hWndMain;

class Hello
{

public:
	Hello();
	virtual ~Hello();

};
#endif // !defined(EA_0EDA6DC8_C8D6_4d42_9A0E_7B6FC9C8EB6C__INCLUDED_)
