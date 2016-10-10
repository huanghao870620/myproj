///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      10-Ê®ÔÂ-2016 19:09:58
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "MyApp.h"

MyApp app;
MyApp::MyApp(){

}



MyApp::~MyApp(){

}


HANDLE hEvent = NULL;
char g_cArray[10];


UINT ThreadProc12(LPVOID pParam){
	WaitForSingleObject(hEvent, INFINITE);
	for (int i = 0; i < 10; i++){
		g_cArray[i] = 'a';
		Sleep(1);
	}
	SetEvent(hEvent);
	return 0;
}

UINT ThreadProc13(LPVOID pParam){
	WaitForSingleObject(hEvent, INFINITE);
	for (int i = 0; i < 10; i++){
		g_cArray[10 - i - 1] = 'b';
		Sleep(1);
	}
	SetEvent(hEvent);
	return 0;
}

BOOL MyApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w+t", stdout);

	hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	SetEvent(hEvent);
	AfxBeginThread(ThreadProc12, NULL);
	AfxBeginThread(ThreadProc13, NULL);
	Sleep(300);

	CString sResult = CString(g_cArray);
	AfxMessageBox(sResult);
	return TRUE;
}