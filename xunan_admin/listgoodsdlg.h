#pragma once

#include"resource.h"
#include<iostream>
//#include"good_dao.h"
#include"good_service.h"
#include"charset_util.h"
#include"MyCListCtrl.h"
#include"Util.h"

// ListGoodsDlg �Ի���

class ListGoodsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ListGoodsDlg)

public:
	ListGoodsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ListGoodsDlg();
	
// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:afx_msg void OnItemChanged(NMHDR*pNMHDR,LRESULT*pResult);

private:MyCListCtrl listCtrl; /*�б�ؼ�*/
protected:BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
