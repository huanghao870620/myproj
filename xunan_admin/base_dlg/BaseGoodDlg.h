#pragma once
#pragma execution_character_set("utf-8")
#include<iostream>
#include<list>
#include<vector>

#include"../resource.h"
#include<afxdialogex.h>
#include"../dlg/MyFrame.h"
#include"../dlg/MyDoc.h"
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

//#include"util\"

// BaseGoodDlg �Ի���

class BaseGoodDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BaseGoodDlg)

public:
	BaseGoodDlg(CWnd* pParent = NULL);   // ��׼���캯��
	BaseGoodDlg(long goodId);
	virtual ~BaseGoodDlg();

	// �Ի�������
	enum { IDD = IDD_DIALOG_ADD_GOODS };
	void GetRecom(CString&recom);
	DECLARE_MESSAGE_MAP()

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg void addGood(); /*�����Ʒ*/
	afx_msg void uploadFileGatp(); /*�ϴ���Ʒ������*/
	afx_msg void uploadFileBgat(); /*�ς���Ʒ������*/
	afx_msg void uploadAdvPic();/*�ϴ����ͼ*/
	afx_msg void uploadFileBig1(); /*�ς���D1*/
	afx_msg void uploadFileBig2(); /*�ς���D2*/
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

	CString big1Path; /*��Ʒ��D1*/
	CString thumbPath;/*�s�ԈD*/
	CString advPath;/*���ͼ*/
	CString cutFigure1Path;/*�ЈD1*/
	long goodId;
	RECT big1Rect;
	CRect thumbRect;/*����ͼ*/
	CRect advRect;/*���ͼ*/
	int selClass; /*ѡ�����*/

	CStatic gatp;// ��Ʒ�s�ԈD
	CStatic advPic;//��Ʒ���ͼ
	CStatic big1;//��D1
	CStatic cutFigure1; //�ЈD1

	CEdit nameEdit; /*��Ʒ���Ʊ༭�ؼ�*/
	CEdit infoEdit;/*����*/
	CEdit capacityEdit;/*����*/
	CWnd dateOfProductionControl;/*��������*/
	CEdit lowestPriceEdit;/*��ͼ�*/
	CEdit highestPriceEdit;/*��߼�*/
	CEdit priceEdit;/*��Ʒʵ�ʼ۸�*/
	CEdit purchasPositonEdit;/*�ɹ�λ��*/
	CComboBox firstClass;/*һ������*/
	CComboBox secondClass;/*��������*/
	CComboBox thirdClass;/*��������*/
	CComboBox brandSel; /*Ʒ��*/
	CButton isRecom; /*�Ƽ�*/
	CButton isNotRecom;/*���Ƽ�*/
	int m_nYPos = 0;
	int m_nXPos = 0;
	std::string localPath;
	std::string thubmLocalPath;/*����ͼ���ش洢·��*/
	long thumbFileId; /*����ͼ�ļ�id*/
	std::list<file*> bigFileList; /*��Ʒ��ͼ*/
	std::list<file*> cutFileList; /*��Ʒ��ͼ*/
	long getClassId(std::list<long> *ls, int index);
	void SetCurSel(CComboBox *box, long id, int i);
	HRESULT ShowPic(CDC* pDC, CString strImgUrl, CRect rect);
	void init();
	file_service*fs;
	good_file_service*gfs;
	classification_service*cs;
	good_service*gs;
	upload_service*us;
	brand_service*bs;
	CStringW ConvertUTF82CStringW(char* instr);/*ת��Ϊutf8*/
	void ConvertUtf8ToGBK(CString &strUtf8);

};
