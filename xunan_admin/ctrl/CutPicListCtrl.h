#pragma once
#include"../resource.h"

// CutPicListCtrl �Ի���

class CutPicListCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CutPicListCtrl)

public:
	CutPicListCtrl(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CutPicListCtrl();

// �Ի�������
	enum { IDD = IDD_DIALOG_CUT_PIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
#pragma once

