#pragma once
#include <afxwin.h>
#include <afxcmn.h>

class LogOperator;

class LogDialog : public CDialog
{
public:
	LogDialog();
	~LogDialog();

	//afx_msg void OnFlush();
	virtual BOOL OnInitDialog();

private:
	LogOperator * logOperator = nullptr;
	CListCtrl listCtrl;

private:
	DECLARE_MESSAGE_MAP()
};

