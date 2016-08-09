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
	UINT targetCtrlId = IDC_STATIC;
	CWnd *pWnd = this->GetDlgItem(targetCtrlId);
	CRect rectTargetCtrl;
	pWnd->GetWindowRect(rectTargetCtrl);
	pWnd->DestroyWindow();
	this->ScreenToClient(rectTargetCtrl);

}