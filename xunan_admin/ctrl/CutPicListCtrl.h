#pragma once
#include"../resource.h"

// CutPicListCtrl 对话框

class CutPicListCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CutPicListCtrl)

public:
	CutPicListCtrl(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CutPicListCtrl();

// 对话框数据
	enum { IDD = IDD_DIALOG_CUT_PIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
#pragma once

