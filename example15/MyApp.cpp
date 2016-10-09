///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      09-Ê®ÔÂ-2016 20:38:42
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "MyApp.h"

CRITICAL_SECTION g_cs;
char g_cArray[10];
MyApp app;

UINT ThreadProc10(LPVOID pParam){
	EnterCriticalSection(&g_cs);
	for (int i = 0; i < 10; i++){
		g_cArray[i] = 'a';
		Sleep(1);
	}
	LeaveCriticalSection(&g_cs);
	return 0;
}

UINT ThreadProc11(LPVOID pParam){
	EnterCriticalSection(&g_cs);
	for (int i = 0; i < 100; i++){
		g_cArray[10 - i - 1] = 'b';
		Sleep(1);
	}
	LeaveCriticalSection(&g_cs);
	return 0;
}

MyApp::MyApp(){

}



MyApp::~MyApp(){

}


BOOL MyApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w+t", stdout);

	InitializeCriticalSection(&g_cs);
	AfxBeginThread(ThreadProc10, NULL);
	AfxBeginThread(ThreadProc11, NULL);

	Sleep(300);
	CString sResult = CString(g_cArray);
	std::cout << sResult << std::endl;
	Sleep(1000*3600);
	return TRUE;
}