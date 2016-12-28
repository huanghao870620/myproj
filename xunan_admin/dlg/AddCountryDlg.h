#pragma once

#include"../resource.h"
#include"../util/Util.h"
#include"../util/ShowJpg.h"
#include"../service/country_service.h"
#include"../service/upload_service.h"
#include "afxdialogex.h"
// AddCountryDlg �Ի���

class AddCountryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddCountryDlg)

public:
		AddCountryDlg(CWnd* pParent = NULL);   // ��׼���캯��
		virtual ~AddCountryDlg();

private:
		CEdit nameEdit;
		CStatic imgControl;
		CEdit countryCodeEdit;
		CString localPath;
		country_service*cs;
		upload_service*us;

		void AddCountry();
		void SelPic();

// �Ի�������
		enum { IDD = IDD_DIALOG_ADD_COUNTRY };
protected:
	      virtual BOOL OnInitDialog();
		  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
