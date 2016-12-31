#pragma once
#include"../resource.h"
#include<afxdialogex.h>
// EditGoodDlg �Ի���

#pragma execution_character_set("utf-8")
#include<iostream>
#include<list>
#include<vector>

#include"MyFrame.h"
#include"MyDoc.h"
#include"..\util\charset_util.h"
#include"..\util\Util.h"
#include"..\util\ShowJpg.h"
#include"../service/good_file_service.h"
#include"../entity/file.h"
#include"../util/UploadFile.h"
#include"../service/good_service.h"
#include"../service/classification_service.h"
#include"../service/file_service.h"
#include"../service/upload_service.h"
#include"../service/brand_service.h"
#include"../util/Constants.h"
#include"BigPicDlg.h"
#include"../base_dlg/BaseGoodDlg.h"

class EditGoodDlg : public BaseGoodDlg
{
	DECLARE_DYNAMIC(EditGoodDlg)

public:
	EditGoodDlg(CWnd* pParent = NULL);   // ��׼���캯��
	EditGoodDlg(long goodId);
	virtual ~EditGoodDlg();
	void GetRecom(CString&recom);

// �Ի�������
	enum { IDD = IDD_DIALOG_ADD_GOODS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
	//afx_msg void addAdvPic(); // ��ӏV��D



protected:
	afx_msg void editGood(); /*�༭��Ʒ*/
	afx_msg void uploadFileBgat(); /*�ς���Ʒ������*/
	afx_msg void uploadFileBig1(); /*�ς���D1*/
	afx_msg void uploadCutFigure1(); /*�ЈD1*/
	afx_msg void uploadCutFigure2(); /*�ЈD2*/
	afx_msg void SetSecondClass();/*���һ������*/
	afx_msg void SetThirdClass();/*�����������*/
	afx_msg void SelThirdClass();/*�����������*/
	afx_msg void selRecommended();/*ѡ���Ƽ�*/
	afx_msg void selNotRecommended();/*ѡ���Ƽ�*/
	virtual BOOL OnEraseBkgnd(CDC*pDC);
	afx_msg void f1();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	void showBigPic();

private:
	std::list<file> bigFileList; /*��Ʒ��ͼ*/
	std::list<file> cutFileList; /*��Ʒ��ͼ*/
	CStatic**bigCsList = NULL; 
	long adv_pic_id = 0;
};
