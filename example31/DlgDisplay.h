#pragma once

#include"resource.h"

// CDlgDisplay 对话框

class CDlgDisplay : public CDialog
{
	DECLARE_DYNAMIC(CDlgDisplay)

public:
	CDlgDisplay(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgDisplay();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
