// D:\cppwork\myproj\xunan_admin\dlg\EditCountryDlg.cpp : ʵ���ļ�
//

#include "../stdafx.h"
#include "EditCountryDlg.h"


// EditCountryDlg �Ի���
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
	this->SetWindowTextA("�༭����");

	return TRUE;
}

void EditCountryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(EditCountryDlg, CDialogEx)
END_MESSAGE_MAP()


// EditCountryDlg ��Ϣ�������
