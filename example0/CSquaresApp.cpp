///////////////////////////////////////////////////////////
//  CSquaresApp.cpp
//  Implementation of the Class CSquaresApp
//  Created on:      29-°ËÔÂ-2016 16:41:48
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include"resource.h"
#include"CMainFrame.h"
#include"CSquaresDoc.h"
#include"CSquaresView.h"
#include "CSquaresApp.h"
#include"CAboutDlg.h"

BEGIN_MESSAGE_MAP(CSquaresApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT,/*CSquaresApp::*/OnAppAbout)
END_MESSAGE_MAP()


CSquaresApp theApp;
CSquaresApp::CSquaresApp(){

}



CSquaresApp::~CSquaresApp(){

}

BOOL CSquaresApp::InitInstance(){
	AllocConsole();
	SetConsoleTitle("²âÊÔ´°¿Ú");
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r+t", stdin);
	std::cout << "dddddddddd" << std::endl;


	SetRegistryKey("bbcdd");
	LoadStdProfileSettings();
	CSingleDocTemplate *pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(IDR_MAINFRAME, RUNTIME_CLASS(CSquaresDoc), RUNTIME_CLASS(CMainFrame), RUNTIME_CLASS(CSquaresView));
	this->AddDocTemplate(pDocTemplate);

	EnableShellOpen();
	RegisterShellFileTypes(TRUE);
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	if (!ProcessShellCommand(cmdInfo)){
		return FALSE;
	}

	this->m_pMainWnd->ShowWindow(SW_SHOW);
	this->m_pMainWnd->UpdateWindow();
	return TRUE;
}

void CSquaresApp::OnAppAbout(){
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}