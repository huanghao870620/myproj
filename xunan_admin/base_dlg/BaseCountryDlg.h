#pragma once

#include"../resource.h"
#include"../util/Util.h"
#include"../util/ShowJpg.h"
#include"../service/country_service.h"
#include"../service/upload_service.h"
#include "afxdialogex.h"
// BaseCountryDlg 对话框

class BaseCountryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BaseCountryDlg)

public:
	BaseCountryDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BaseCountryDlg();

protected:
	CEdit nameEdit;
	CStatic imgControl;
	CEdit countryCodeEdit;
	CString localPath;
	country_service*cs;
	upload_service*us;

	void AddCountry();
	void SelPic();

	// 对话框数据
	enum { IDD = IDD_DIALOG_ADD_COUNTRY };
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
