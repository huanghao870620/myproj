
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

	SetRegistryKey("ddd");
	LoadStdProfileSettings();
	CSingleDocTemplate * temp;
	temp = new CSingleDocTemplate(IDR_MAINFRAME, RUNTIME_CLASS(MyDoc), RUNTIME_CLASS(MyMainFrame), RUNTIME_CLASS(MyView));
	this->AddDocTemplate(temp);
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);
	CCommandLineInfo info;
	ParseCommandLine(info);
	if (!ProcessShellCommand(info)){
		return FALSE;
	}

	return TRUE;
}