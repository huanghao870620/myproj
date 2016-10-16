///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      16-Ê®ÔÂ-2016 12:23:36
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "MyApp.h"


MyApp::MyApp(){

}



MyApp::~MyApp(){

}

CCriticalSection g_cs;
std::list<A*> ls0;
UINT f0(LPVOID lParam){
	while (true)
	{
		g_cs.Lock();
		//std::cout << "A";
		A*a = new A;
		ls0.push_back(a);
		Sleep(2);
		//g_cs.Unlock();
	}
	return 0;
}

UINT f1(LPVOID lParam){
	while (true)
	{
		g_cs.Lock(); 
		std::cout << "B";
		Sleep(2);
		//g_cs.Unlock();
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