///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      16-ʮ��-2016 16:39:22
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "MyApp.h"


MyApp::MyApp(){

}



MyApp::~MyApp(){

}

CEvent g_event;

UINT f0(LPVOID lParam){
	while (true){
		std::cout << "A";
		Sleep(1);
		g_event.Lock();
	}
	return(0);
}

UINT f1(LPVOID lParam){
	while (true){
		std::cout << "B";
		Sleep(1);
		g_event.Lock();
	}
	return(0);
}


MyApp app;
BOOL MyApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w+t", stdout);

	AfxBeginThread(f0, NULL);
	AfxBeginThread(f1, NULL);

	Sleep(1000 * 3600);
	return TRUE;
}