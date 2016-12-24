// D:\cppwork\myproj\xunan_admin\dlg\EditCountryDlg.cpp : 实现文件
//

#include "../stdafx.h"
#include "EditCountryDlg.h"


// EditCountryDlg 对话框
IMPLEMENT_DYNAMIC(EditCountryDlg, CDialogEx)

EditCountryDlg::EditCountryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(EditCountryDlg::IDD, pParent)
{
	this->cs = country_service::get_country_service();
}

EditCountryDlg::~EditCountryDlg()
{
}

BOOL EditCountryDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	this->SetWindowTextA("编辑国家");

	return TRUE;
}

void EditCountryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(EditCountryDlg, CDialogEx)
END_MESSAGE_MAP()


// EditCountryDlg 消息处理程序
