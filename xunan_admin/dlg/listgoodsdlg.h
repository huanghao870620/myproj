#pragma once

#include"../resource.h"
#include<iostream>
//#include"good_dao.h"
#include"../service/good_service.h"
#include"../util/charset_util.h"
#include"../ctrl/MyCListCtrl.h"
#include"../util/Util.h"
#include"../service/good_file_service.h"
#include"AddGoodsDlg.h"

// ListGoodsDlg 对话框

class ListGoodsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ListGoodsDlg)

public:
	ListGoodsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ListGoodsDlg();
	
// 对话框数据
	enum { IDD = IDD_DIALOG_GOOD_LIST };


private:
	MyCListCtrl listCtrl; /*列表控件*/
	AddGoodsDlg addGoodDlg;

	good_file_service *gfs;
	good_service *gs;
	file_service *fs;


protected:
	afx_msg void OnItemChanged(NMHDR*pNMHDR,LRESULT*pResult);
	BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void OnPaint();

	DECLARE_MESSAGE_MAP()

	afx_msg void delGood();
	afx_msg void Refresh();
	afx_msg void AddGood();
};
