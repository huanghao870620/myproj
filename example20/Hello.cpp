///////////////////////////////////////////////////////////
//  Hello.cpp
//  Implementation of the Class Hello
//  Created on:      10-Ê®ÔÂ-2016 22:36:39
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

	std::cout << hInstance << std::endl;
	std::cout << hPrevInstance << std::endl;
	std::cout << lpCmdLine << std::endl;
	std::cout << nCmdShow << std::endl;
	return (0);
}