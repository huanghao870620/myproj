#pragma once

#include"../resource.h"
#include<afxwin.h>
#include<afxdlgs.h>
#include"../util/ShowJpg.h"
#include"../ctrl/CImageListCtrl.h"

// TestDlg 对话框

class TestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TestDlg)

public:
	TestDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TestDlg();
protected:virtual BOOL OnInitDialog();
// 对话框数据
	enum { IDD = IDD_DIALOG1 };
	CImageListCtrl ctrl;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

public:void TestDlg::OnBnClickedBtnBrowse();
	DECLARE_MESSAGE_MAP()
};
