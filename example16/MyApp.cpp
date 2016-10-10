///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      09-ʮ��-2016 21:37:54
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "MyApp.h"

MyApp app;
CCriticalSection g_clsCriticalSection;
char g_cArray[10];
MyApp::MyApp(){

}



MyApp::~MyApp(){

}


UINT ThreadProc20(LPVOID lParam){
	g_clsCriticalSection.Lock();
	for (int i = 0; i < 10; i++){
		g_cArray[i] = 'a';
		Sleep(1);
	}
	g_clsCriticalSection.Unlock();
	return 0;
}

UINT ThreadProc21(LPVOID lParam){
	g_clsCriticalSection.Lock();
	for (int i = 0; i < 10; i++){
		g_cArray[10 - i - 1] = 'b';
		Sleep(1);
	}
	g_clsCriticalSection.Unlock();
	return 0;
}



BOOL MyApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w+t", stdout);

	AfxBeginThread(ThreadProc20, NULL);
	AfxBeginThread(ThreadProc21, NULL);

	Sleep(300);

	CString aResult = CString(g_cArray);
	//std::cout << aResult << std::endl;
	AfxMessageBox(aResult);
	return TRUE;
}