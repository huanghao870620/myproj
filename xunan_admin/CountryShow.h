#pragma once

#include"resource.h"
#include"CountryListCtrl.h"
#include"charset_util.h"
#include"country_service.h"
#include"country.h"
#include"Util.h"

// CountryShow 对话框

class CountryShow : public CDialogEx
{
	DECLARE_DYNAMIC(CountryShow)

public:
	CountryShow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CountryShow();

// 对话框数据
	enum { IDD = IDD_DIALOG_COUNTRY_LIST };
private:CountryListCtrl clistCtrl;
private:country_service*cs;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
protected:virtual BOOL OnInitDialog(); //

	DECLARE_MESSAGE_MAP()
};
