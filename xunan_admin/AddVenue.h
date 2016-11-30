#pragma once
#include"resource.h"
#include"Util.h"
#include"venue_service.h"
#include"upload_service.h"
#include"ShowJpg.h"

// AddVenue 对话框

class AddVenue : public CDialogEx
{
	DECLARE_DYNAMIC(AddVenue)
public:
	AddVenue(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddVenue();

private:CString localFilePath;
// 对话框数据
	enum { IDD = IDD_DIALOG_VNEUE };
protected:afx_msg void uploadImg();
protected:afx_msg void addVenue();
protected:virtual BOOL OnInitDialog();
private:venue_service*vs;
private:upload_service*us;

private:CEdit nameEdit;
private:CStatic imgCtrl;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
