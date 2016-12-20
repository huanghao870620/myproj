#pragma once

#include"../resource.h"
#include"../ctrl/CountryListCtrl.h"
#include"../util/charset_util.h"
#include"../service/country_service.h"
#include"../entity/country.h"
#include"../util/Util.h"

// CountryShow �Ի���

class CountryShow : public CDialogEx
{
	DECLARE_DYNAMIC(CountryShow)

public:
	CountryShow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CountryShow();

// �Ի�������
	enum { IDD = IDD_DIALOG_COUNTRY_LIST };
private:CountryListCtrl clistCtrl;
private:country_service*cs;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
protected:virtual BOOL OnInitDialog(); //

	DECLARE_MESSAGE_MAP()
};
