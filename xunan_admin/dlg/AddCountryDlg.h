#pragma once

#include"../resource.h"
#include"../util/Util.h"
#include"../util/ShowJpg.h"
#include"../service/country_service.h"
#include"../service/upload_service.h"
#include "afxdialogex.h"
#include"../base_dlg/BaseCountryDlg.h"
// AddCountryDlg 对话框

class AddCountryDlg : public BaseCountryDlg
{
	DECLARE_DYNAMIC(AddCountryDlg)

public:
		AddCountryDlg(CWnd* pParent = NULL);   // 标准构造函数
		virtual ~AddCountryDlg();

private:

		void AddCountry();

// 对话框数据
		enum { IDD = IDD_DIALOG_ADD_COUNTRY };
protected:
	      virtual BOOL OnInitDialog();
		  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
