///////////////////////////////////////////////////////////
//  ChatDialog2.cpp
//  Implementation of the Class ChatDialog2
//  Created on:      08-����-2016 11:36:04
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "ChatDialog2.h"


ChatDialog2::ChatDialog2(){

}




ChatDialog2::~ChatDialog2(){

}

BOOL ChatDialog2::OnInitDialog(){
	/*
	CDialog::OnInitDialog();
	UINT targetCtrlId = IDC_STATIC;
	CWnd *pWnd = this->GetDlgItem(targetCtrlId);
	CRect rectTargetCtrl;
	pWnd->GetWindowRect(rectTargetCtrl);
	pWnd->DestroyWindow();
	this->ScreenToClient(rectTargetCtrl);

	if (NULL == this->m_pDrawView){
		return FALSE;
	}
	this->m_pDrawView = (CDrawView*)RUNTIME_CLASS(CDrawView)->CreateObject();
	this->m_pDrawView->Create(NULL, NULL, AFX_WS_DEFAULT_VIEW | WS_VSCROLL | WS_HSCROLL, rectTargetCtrl, this, targetCtrlId);*/


	/*ASSERT(1 == 1);
	ASSERT(2 > 1);
	ASSERT(3 < 2);*/
	//ASSERT((ID_40007 & 0xFFF0) == ID_40007);
	//ASSERT(IDM_ABOUTBOX < 0XF000);

	CDialog::OnInitDialog();
	CMenu * pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL){
		CString strAboutMenu;
		strAboutMenu.LoadStringA(IDS_STRING204);
		if (!strAboutMenu.IsEmpty()){
			//pSysMenu->AppendMenuA("");
		}
	}
	HICON ico = LoadIcon(NULL, IDI_ERROR);
	SetIcon(ico, TRUE);
	return TRUE;
}