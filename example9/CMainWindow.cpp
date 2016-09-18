///////////////////////////////////////////////////////////
//  CMainWindow.cpp
//  Implementation of the Class CMainWindow
//  Created on:      18-¾ÅÔÂ-2016 12:19:01
//  Original author: huanghao
///////////////////////////////////////////////////////////

#include "CMainWindow.h"

BEGIN_MESSAGE_MAP(CMainWindow,CWnd)
END_MESSAGE_MAP()
CMyApp myApp;
CMainWindow::CMainWindow(){
	CString strWndClass = AfxRegisterWndClass(0, myApp.LoadStandardCursor(IDC_ARROW), (HBRUSH)(COLOR_3DFACE+1), myApp.LoadStandardIcon(IDI_WINLOGO));
	CreateEx(0, strWndClass, "FontView", WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, NULL);
	CRect rect(0, 0, this->m_cxChar * 68, this->m_cyChar * 26);
	CalcWindowRect(&rect);
	SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(), SWP_NOZORDER | SWP_NOMOVE | SWP_NOREDRAW);
}



CMainWindow::~CMainWindow(){

}

BOOL CMainWindow::OnCreate(LPCREATESTRUCT lpcs){
	if (CWnd::OnCreate(lpcs)==-1)
	{
		return FALSE;
	}
	this->m_fontMain.CreatePointFont(80, "MS Sans Serif");
	CClientDC dc(this);
	dc.SelectObject(&this->m_fontMain);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	tm.tmAveCharWidth;
	return TRUE;
}