
#include "MyApp.h"

MyApp app;
MyApp::MyApp(){

}



MyApp::~MyApp(){

}

BOOL MyApp::InitInstance(){
	AllocConsole();  
	SetConsoleTitle("dd");
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r+t", stdin);

	CSingleDocTemplate * temp;
	temp = new CSingleDocTemplate(IDR_MAINFRAME, RUNTIME_CLASS(MyView), RUNTIME_CLASS(MyDoc), RUNTIME_CLASS(MyMainFrame));
	CCommandLineInfo info;
	ParseCommandLine(info);

	return TRUE;
}