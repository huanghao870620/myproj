// D:\cppwork\myproj\xunan_admin\ctrl\CutPicListCtrl.cpp : 实现文件
//

#include "../stdafx.h"
#include "CutPicListCtrl.h"
#include "afxdialogex.h"


// CutPicListCtrl 对话框

IMPLEMENT_DYNAMIC(CutPicListCtrl, CDialogEx)

CutPicListCtrl::CutPicListCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CutPicListCtrl::IDD, pParent)
{

}

CutPicListCtrl::~CutPicListCtrl()
{
}

void CutPicListCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CutPicListCtrl, CDialogEx)
END_MESSAGE_MAP()


// CutPicListCtrl 消息处理程序
