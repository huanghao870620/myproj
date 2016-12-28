#pragma once

#include"../resource.h"
#include "afxdialogex.h"
#include<iostream>
#include"../service/country_service.h"
#include"../service/file_service.h"
#include"../util/Config.h"
#include"../util/ShowJpg.h"
#include"../util/Util.h"
//#include"../util/file_type_enum.h"
// EditCountryDlg �Ի���

class EditCountryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EditCountryDlg)

public:
	EditCountryDlg(LONG id, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~EditCountryDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADD_COUNTRY };

	BOOL OnInitDialog();
private:
		country_service*cs;
		file_service*fs;
		upload_service*us;

		CEdit nameEdit;
		CStatic imgControl;
		CEdit countryCodeEdit;
		CString localPath;
		LONG id;
protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
		void OnPaint();
		VOID SelPic();
		void EditCountry();
		void t();
		DECLARE_MESSAGE_MAP()
};
