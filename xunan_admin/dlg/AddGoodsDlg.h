#pragma once
#pragma execution_character_set("utf-8")
#include<iostream>
#include<list>
#include<vector>

#include"../resource.h"
#include<afxdialogex.h>
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
#include"../base_dlg/BaseGoodDlg.h"

//#include"util\"

// AddGoodsDlg 对话框

class AddGoodsDlg : public BaseGoodDlg
{
	DECLARE_DYNAMIC(AddGoodsDlg)

public:
		AddGoodsDlg(CWnd* pParent = NULL);   // 标准构造函数
		AddGoodsDlg(long goodId);
		virtual ~AddGoodsDlg();

// 对话框数据
		enum { IDD = IDD_DIALOG_ADD_GOODS };
		void GetRecom(CString&recom);
		DECLARE_MESSAGE_MAP()

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg void addGood(); /*添加商品*/
	afx_msg void uploadFileGatp(); /*上传商品正面照*/
	afx_msg void uploadFileBgat(); /*上傳商品背面照*/
	afx_msg void uploadAdvPic();/*上传广告图*/
	afx_msg void uploadFileBig1(); /*上傳大圖1*/
	afx_msg void uploadFileBig2(); /*上傳大圖2*/
	afx_msg void uploadCutFigure1(); /*切圖1*/
	afx_msg void uploadCutFigure2(); /*切圖2*/
	afx_msg void SetSecondClass();/*点击一级分类*/
	afx_msg void SetThirdClass();/*点击二级分类*/
	afx_msg void SelThirdClass();/*点击三级分类*/
	afx_msg void selRecommended();/*选择推荐*/
	afx_msg void selNotRecommended();/*选择不推荐*/
	virtual BOOL OnEraseBkgnd(CDC*pDC);
	afx_msg void f1();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnPaint(); 
	virtual BOOL OnInitDialog();
//
//private:
//	CString big1Path; /*商品大圖1*/
//	CString thumbPath;/*縮略圖*/
//	CString advPath;/*广告图*/
//	CString cutFigure1Path;/*切圖1*/
//	long goodId;
//	RECT big1Rect;
//	RECT thumbRect;/*缩略图*/
//	RECT advRect;/*广告图*/
//	int selClass; /*选择分类*/
//
//	CStatic gatp;// 商品縮略圖
//	CStatic advPic;//商品广告图
//	CStatic big1;//大圖1
//	CStatic cutFigure1; //切圖1
//
//	CEdit nameEdit; /*商品名称编辑控件*/
//	CEdit infoEdit;/*描述*/
//	CEdit capacityEdit;/*容量*/
//	CWnd dateOfProductionControl;/*生产日期*/
//	CEdit lowestPriceEdit;/*最低价*/
//	CEdit highestPriceEdit;/*最高价*/
//	CEdit priceEdit;/*商品实际价格*/
//	CEdit purchasPositonEdit;/*采购位置*/
//	CComboBox firstClass;/*一级分类*/
//	CComboBox secondClass;/*二级分类*/
//	CComboBox thirdClass;/*三级分类*/
//	CComboBox brandSel; /*品牌*/
//	CButton isRecom; /*推荐*/
//	CButton isNotRecom;/*不推荐*/
//	int m_nYPos = 0;
//	int m_nXPos = 0;
//	std::string localPath;
//	std::string thubmLocalPath;/*缩略图本地存储路径*/
//	long thumbFileId; /*缩略图文件id*/
//	std::list<file*> bigFileList; /*商品大图*/
//	std::list<file*> cutFileList; /*商品切图*/
//	long getClassId(std::list<long> *ls, int index);
//	void SetCurSel(CComboBox *box, long id, int i);
//	HRESULT ShowPic(CDC* pDC, CString strImgUrl, CRect rect);
//	void init();
//	file_service*fs;
//	good_file_service*gfs;
//	classification_service*cs;
//	good_service*gs;
//	upload_service*us;
//	brand_service*bs;
//	CStringW ConvertUTF82CStringW(char* instr);/*转换为utf8*/
//	void ConvertUtf8ToGBK(CString &strUtf8);
	
};
