// DlgDisplay.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgDisplay.h"
#include "afxdialogex.h"


// CDlgDisplay 对话框

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


// CDlgDisplay 消息处理程序
