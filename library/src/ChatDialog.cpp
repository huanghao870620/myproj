///////////////////////////////////////////////////////////
//  ChatDialog.cpp
//  Implementation of the Class ChatDialog
//  Created on:      30-����-2016 15:02:19
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
	//this->MessageBox(_T("aabb"));
	CString dd;
	this->edit.GetWindowTextA(dd);
	std::cout << "dddd" << std::endl;
	Client *client = new Client;
	client->Send(dd);
}

void ChatDialog::addComp(){
}

BOOL ChatDialog::OnInitDialog(){
	this->edit.Create(ES_MULTILINE|WS_CHILD|WS_VISIBLE|WS_TABSTOP|WS_BORDER, CRect(10, 10, 200, 200), this, 36);
	this->but.Create(_T("����"), WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(210, 210, 250, 250), this, 333);
	return FALSE;
}