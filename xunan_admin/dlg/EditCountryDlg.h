#pragma once

#include"../resource.h"
#include "afxdialogex.h"
#include<iostream>
#include"../service/country_service.h"
#include"../service/file_service.h"
#include"../util/Config.h"
#include"../util/ShowJpg.h"
#include"../util/Util.h"
#include"../base_dlg/BaseCountryDlg.h"

class EditCountryDlg : public BaseCountryDlg
{
	DECLARE_DYNAMIC(EditCountryDlg)

public:
	EditCountryDlg(LONG id, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~EditCountryDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADD_COUNTRY };

	BOOL OnInitDialog();
private:
		file_service*fs;
		/*country_service*cs;
		upload_service*us;

		CEdit nameEdit;
		CStatic imgControl;
		CEdit countryCodeEdit;
		CString localPath;*/
		LONG id;
protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
		void OnPaint();
		void EditCountry();
		void t();
		DECLARE_MESSAGE_MAP()
};
