#include <iostream>
#include <afxwin.h>
#include <afxdisp.h>
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
	
	//pDocTemplate = new CMultiDocTemplate(idr_mdite)
	return TRUE;
}

void CMyWinApp::init() {
	AllocConsole();
	freopen("CONOUT$", "w+t", stdout);
	printf("hello world! \n");
}
