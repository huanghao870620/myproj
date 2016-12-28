#pragma once

#include"../resource.h"
#include<iostream>
//#include"good_dao.h"
#include"../service/good_service.h"
#include"../util/charset_util.h"
#include"../ctrl/MyCListCtrl.h"
#include"../util/Util.h"

// ListGoodsDlg 对话框

class ListGoodsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ListGoodsDlg)

public:
	ListGoodsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ListGoodsDlg();
	
// 对话框数据
	enum { IDD = IDD_DIALOG_GOOD_LIST };

protected:afx_msg void OnItemChanged(NMHDR*pNMHDR,LRESULT*pResult);

private:MyCListCtrl listCtrl; /*列表控件*/
protected:BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void OnPaint();

	DECLARE_MESSAGE_MAP()
};
