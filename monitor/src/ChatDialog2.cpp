///////////////////////////////////////////////////////////
//  ChatDialog2.cpp
//  Implementation of the Class ChatDialog2
//  Created on:      08-°ËÔÂ-2016 11:36:04
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "ChatDialog2.h"


ChatDialog2::ChatDialog2(){

}




ChatDialog2::~ChatDialog2(){

}

BOOL ChatDialog2::OnInitDialog(){
	CDialog::OnInitDialog();
	CMenu * pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL){
		CString strAboutMenu;
		strAboutMenu.LoadStringA(IDS_STRING204);
		if (!strAboutMenu.IsEmpty()){
			pSysMenu->AppendMenuA(MF_SEPARATOR);
			pSysMenu->AppendMenuA(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	HICON ico = LoadIcon(NULL, IDI_ERROR);
	SetIcon(ico, TRUE);
	SetIcon(ico, FALSE);

	this->text = new CStatic;
	this->text->Create("my static", WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(10, 10, 150, 50), this);
	CRect rectTargetCtrl;
	this->text->GetWindowRect(rectTargetCtrl);
	this->ScreenToClient(rectTargetCtrl);
	this->m_pView = (CDrawView *)RUNTIME_CLASS(CDrawView)->CreateObject();
	if (NULL == this->m_pView){
		return FALSE;
	}
	//this->m_pView->Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, rectTargetCtrl, this, IDC_STATIC);
	return TRUE;
}