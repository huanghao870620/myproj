#pragma once

#include"resource.h"

// CDlgDisplay �Ի���

class CDlgDisplay : public CDialog
{
	DECLARE_DYNAMIC(CDlgDisplay)

public:
	CDlgDisplay(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgDisplay();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
