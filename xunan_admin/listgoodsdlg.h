#pragma once

#include"resource.h"
#include<iostream>
#include"good_dao.h"

// ListGoodsDlg 对话框

class ListGoodsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ListGoodsDlg)

public:
	ListGoodsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ListGoodsDlg();
	
// 对话框数据
	enum { IDD = IDD_DIALOG2 };


private:CListCtrl listCtrl; /*列表控件*/
protected:BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
