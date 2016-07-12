///////////////////////////////////////////////////////////
//  ChatDialog.cpp
//  Implementation of the Class ChatDialog
//  Created on:      30-ÁùÔÂ-2016 15:02:19
//  Original author: huang.hao
///////////////////////////////////////////////////////////
#include <iostream>
#include <afxwin.h>
#include "ChatDialog.h"
#include "Client.h"

BEGIN_MESSAGE_MAP(ChatDialog, CDialog)
	ON_BN_CLICKED(333, OnChat)
END_MESSAGE_MAP()


ChatDialog::ChatDialog(){
}


ChatDialog::~ChatDialog(){

}

void ChatDialog::OnChat(){
	CString dd;
	this->edit.GetWindowTextA(dd);
	Client *client = new Client;
	client->Send(dd);
}

void ChatDialog::addComp(){
}	

BOOL ChatDialog::OnInitDialog(){
	this->edit.Create(ES_MULTILINE|WS_CHILD|WS_VISIBLE|WS_TABSTOP|WS_BORDER, CRect(10, 150, 200, 200), this, 36);
	CRect ct(10, 10, 100, 100);
	this->cs.Create("ÄãºÃ", WS_CHILD | WS_VISIBLE | CA_CENTER |WS_BORDER, ct, this);
	this->but.Create(_T("·¢ËÍ"), WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(210, 210, 250, 250), this, 333);
	return FALSE;
}