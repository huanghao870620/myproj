///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      16-Ê®ÔÂ-2016 20:35:52
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "MyApp.h"


MyApp::MyApp(){

}



MyApp::~MyApp(){

}

UINT f0(LPVOID lParam){
	A*a = (A*)lParam;
	while (true)
	{
	//g_event.SetEvent();
		/*g_event.Lock();
		g_event.Unlock();*/
	std::cout << "A";
	Sleep(1);
	}
	return(0);
}

UINT f1(LPVOID lParam){
	A*a = (A*)lParam;
	while (true)
	{
		//g_event.SetEvent();
		std::cout << "B";
		Sleep(1);
	}
	return(0);
}


BOOL MyApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w+t", stdout);
	
	A*a = new A;
	AfxBeginThread(f0, a);
	AfxBeginThread(f1, a);

	Sleep(3600000);
	return TRUE;
}
