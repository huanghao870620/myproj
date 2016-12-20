#pragma once

#include"../resource.h"
#include"../util/Util.h"
#include"../util/ShowJpg.h"
#include"../service/country_service.h"
#include"../service/upload_service.h"

// AddCountryDlg 对话框

class AddCountryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddCountryDlg)

public:
	AddCountryDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddCountryDlg();

private:CEdit nameEdit;
private:CStatic imgControl;
private:CEdit countryCodeEdit;

private:CString localPath;
private:country_service*cs;
private:upload_service*us;

// 对话框数据
	enum { IDD = IDD_DIALOG_ADD_COUNTRY };
protected:virtual BOOL OnInitDialog();

private:void AddCountry();
private:void SelPic();
//private:void t();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
