
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

	/*SetRegistryKey("ddd");
	LoadStdProfileSettings();*/

	MyDlg dlg;
	this->m_pMainWnd = &dlg;


	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	/*CSingleDocTemplate * temp;
	temp = new CSingleDocTemplate(IDR_MAINFRAME, RUNTIME_CLASS(MyDoc), RUNTIME_CLASS(MyMainFrame), RUNTIME_CLASS(MyView));
	this->AddDocTemplate(temp);
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);
	CCommandLineInfo info;
	ParseCommandLine(info);
	if (!ProcessShellCommand(info)){
		return FALSE;
	}*/

	return TRUE;
}