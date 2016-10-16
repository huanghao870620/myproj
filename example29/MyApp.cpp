///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      16-Ê®ÔÂ-2016 20:07:11
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "MyApp.h"


MyApp::MyApp(){

}


MyApp app;
MyApp::~MyApp(){

}

CEvent g_event;

UINT f0(LPVOID lParam){
	A*a = (A*)lParam;
	std::cout << a << std::endl;
	std::cout << "out a : " << a->getA() << std::endl;
	return(0);
}

UINT f1(LPVOID lParam){
	A*a = (A*)lParam;
	std::cout << a << std::endl;
	return(1);
}

BOOL MyApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w+t", stdout);


	A*a = new A;
	std::cout << a << std::endl;
	std::cout << "out a : " << a->getA() << std::endl;
	delete a;
	AfxBeginThread(f0, a);
	AfxBeginThread(f1, a);

	Sleep(1000 * 3600);
	return(TRUE);
}