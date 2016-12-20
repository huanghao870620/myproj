#pragma once

#include"../resource.h"
#include"../util/Util.h"
#include"../util/ShowJpg.h"
#include"../service/country_service.h"
#include"../service/upload_service.h"

// AddCountryDlg �Ի���

class AddCountryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddCountryDlg)

public:
	AddCountryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddCountryDlg();

private:CEdit nameEdit;
private:CStatic imgControl;
private:CEdit countryCodeEdit;

private:CString localPath;
private:country_service*cs;
private:upload_service*us;

// �Ի�������
	enum { IDD = IDD_DIALOG_ADD_COUNTRY };
protected:virtual BOOL OnInitDialog();

private:void AddCountry();
private:void SelPic();
//private:void t();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
