#pragma once

#include"../resource.h"
#include"../ctrl/MyCTreeCtrl.h"
#include"../service/classification_service.h"
#include"../util/charset_util.h"

// WatchClassDlg �Ի���

class WatchClassDlg : public CDialogEx
{
	DECLARE_DYNAMIC(WatchClassDlg)

public:
	WatchClassDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~WatchClassDlg();

// �Ի�������
	enum { IDD = IDD_WATCH_CLASS };
	//DDX_Control()
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
//protected:  void memberFxn(NMHDR * pNotifyStruct, LRESULT * result);
protected:virtual BOOL OnInitDialog();

private:classification_service *cs;

private:CImageList m_imageList;

private:MyCTreeCtrl m_webTree;
	DECLARE_MESSAGE_MAP()
};
