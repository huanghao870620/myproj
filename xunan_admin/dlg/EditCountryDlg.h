#pragma once

#include"../resource.h"
#include "afxdialogex.h"
#include<iostream>
#include"../service/country_service.h"
// EditCountryDlg 对话框

class EditCountryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EditCountryDlg)

public:
	EditCountryDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~EditCountryDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADD_COUNTRY };

	BOOL OnInitDialog();
private:country_service*cs;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
