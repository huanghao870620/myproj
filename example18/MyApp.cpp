///////////////////////////////////////////////////////////
//  MyApp.cpp
//  Implementation of the Class MyApp
//  Created on:      10-Ê®ÔÂ-2016 19:33:22
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "MyApp.h"

MyApp app;
MyApp::MyApp(){

}



MyApp::~MyApp(){

}

UINT f0(LPVOID lParam){
	Singleton *inst = Singleton::getInstance();
	while (true){
	A* a = new A;
	inst->addA(a);
	Sleep(1000);
	}
	
	return 0;
}

UINT f1(LPVOID lParam){
	Singleton*inst = Singleton::getInstance();
	std::list<A*> *aList = inst->getAList();
	while (true){
	int size = aList->size();
	std::cout << "size : " << size << std::endl;
	Sleep(1000);
	}
	return 0;
}

BOOL MyApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w+t", stdout);

	AfxBeginThread(f0, NULL);
	AfxBeginThread(f1, NULL);

	AfxMessageBox("");
	return TRUE;
}