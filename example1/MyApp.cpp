
#include "MyApp.h"

MyApp app;
MyApp::MyApp(){

}



MyApp::~MyApp(){

}

BOOL MyApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("dd");
	freopen("", "", stdout);
	freopen("", "", stdin);
	return TRUE;
}