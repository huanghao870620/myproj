#include <iostream>
#include <afxwin.h>
#include <afxdisp.h>
#include "MyDocument.h"
#include "MyView.h"
#include "CMyFrameWnd.h"
#include "CMyWinApp.h"


using namespace std;

CMyWinApp::CMyWinApp() 
{
}

CMyWinApp::~CMyWinApp() 
{
}

CMyWinApp theApp;
BOOL CMyWinApp::InitInstance() {
	InitCommonControls();
	CWinApp::InitInstance();
	AfxOleInit();
	AfxEnableControlContainer();
	SetRegistryKey("");
	LoadStdProfileSettings(4);
	TRACE("");
	CMultiDocTemplate * pDocTemplate;
	
	pDocTemplate = new CMultiDocTemplate(2, RUNTIME_CLASS(MyDocument), RUNTIME_CLASS(CMyFrameWnd), RUNTIME_CLASS(MyView));
	return TRUE;
}

void CMyWinApp::init() {
	AllocConsole();
	freopen("CONOUT$", "w+t", stdout);
	printf("hello world! \n");
}
