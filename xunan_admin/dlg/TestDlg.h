#pragma once

#include"../resource.h"
#include<afxwin.h>
#include<afxdlgs.h>
#include"../util/ShowJpg.h"
#include"../ctrl/CImageListCtrl.h"

// TestDlg �Ի���

class TestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TestDlg)

public:
	TestDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TestDlg();
protected:virtual BOOL OnInitDialog();
// �Ի�������
	enum { IDD = IDD_DIALOG1 };
	CImageListCtrl ctrl;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

public:void TestDlg::OnBnClickedBtnBrowse();
	DECLARE_MESSAGE_MAP()
};
