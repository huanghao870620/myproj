#pragma once

#include"../resource.h"
#include "afxdialogex.h"
#include<iostream>
#include"../service/country_service.h"
// EditCountryDlg �Ի���

class EditCountryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EditCountryDlg)

public:
	EditCountryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~EditCountryDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADD_COUNTRY };

	BOOL OnInitDialog();
private:country_service*cs;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
