
#include <iostream>
#include <vld.h>
#include <afxwin.h>
#include <afxdisp.h>
#include "resource.h"
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
	SetRegistryKey("abc");
	LoadStdProfileSettings(4);
	CMultiDocTemplate * pDocTemplate;
	
	pDocTemplate = new CMultiDocTemplate(IDR_MAINFRAME, RUNTIME_CLASS(MyDocument), RUNTIME_CLASS(CMyFrameWnd), RUNTIME_CLASS(MyView));
	if (!pDocTemplate){
		return FALSE;
	}
	AddDocTemplate(pDocTemplate);

	CMyFrameWnd * frame = new CMyFrameWnd;
	
	if (!frame || !frame->LoadFrame(IDR_MAINFRAME)){
		return FALSE;
	}

	this->m_pMainWnd = frame;

	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	if (!ProcessShellCommand(cmdInfo)){
		return FALSE;
	}

	frame->ShowWindow(this->m_nCmdShow);
	frame->UpdateWindow();
	return TRUE;
}

void CMyWinApp::init() {
	AllocConsole();
	freopen("CONOUT$", "w+t", stdout);
	printf("hello world! \n");
}
