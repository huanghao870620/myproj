#pragma once

#include"../resource.h"
#include"../util/Util.h"
#include"../util/ShowJpg.h"
#include"../service/country_service.h"
#include"../service/upload_service.h"
#include "afxdialogex.h"
// BaseCountryDlg �Ի���

class BaseCountryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BaseCountryDlg)

public:
	BaseCountryDlg(CWnd* pParent = NULL);   // ��׼���캯��
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

	// �Ի�������
	enum { IDD = IDD_DIALOG_ADD_COUNTRY };
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
