// DlgDisplay.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgDisplay.h"
#include "afxdialogex.h"


// CDlgDisplay �Ի���

IMPLEMENT_DYNAMIC(CDlgDisplay, CDialog)

CDlgDisplay::CDlgDisplay(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDisplay::IDD, pParent)
{

}

CDlgDisplay::~CDlgDisplay()
{
}

void CDlgDisplay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgDisplay, CDialog)
END_MESSAGE_MAP()


// CDlgDisplay ��Ϣ�������
