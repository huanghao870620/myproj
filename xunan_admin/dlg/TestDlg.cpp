// TestDlg.cpp : ʵ���ļ�
//

#include "../stdafx.h"
#include "TestDlg.h"
#include "afxdialogex.h"


// TestDlg �Ի���

IMPLEMENT_DYNAMIC(TestDlg, CDialogEx)

TestDlg::TestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(TestDlg::IDD, pParent)
{

}

TestDlg::~TestDlg()
{
}

void TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, this->ctrl);
}

BOOL TestDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	this->ctrl.InitCtrl(100, 100);
	this->ctrl.AddImage("d:\\test\\Chrysanthemum.bmp");
	//this->ctrl.AddImage("C:\\Users\\admin\\Pictures\\abc.jpg");
	return TRUE;
}

//************************************  
// ����˵��:    ���ͼƬ  
// ����ֵ:      void  
//************************************  
void TestDlg::OnBnClickedBtnBrowse()
{

}



BEGIN_MESSAGE_MAP(TestDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedBtnBrowse)
END_MESSAGE_MAP()


// TestDlg ��Ϣ�������
