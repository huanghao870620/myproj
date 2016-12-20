#pragma once

#include"../resource.h"
#include<afxwin.h>
#include<afxdlgs.h>
#include"../util/ShowJpg.h"

// TestDlg 对话框

class TestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TestDlg)

public:
	TestDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TestDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

public:void TestDlg::OnBnClickedBtnBrowse();
	DECLARE_MESSAGE_MAP()
};
