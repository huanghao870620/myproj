#pragma once
#include"../resource.h"
#include<afxwin.h>
#include<gdiplus.h>

// Ctrain13_Dlg �Ի���

class Ctrain13_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Ctrain13_Dlg)

public:
	Ctrain13_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Ctrain13_Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_TEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	CImageList *m_pImageList;
	CListCtrl m_picList;

	DECLARE_MESSAGE_MAP()
};
