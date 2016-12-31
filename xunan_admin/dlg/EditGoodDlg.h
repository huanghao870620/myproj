#pragma once
#include"../resource.h"
#include<afxdialogex.h>
// EditGoodDlg 对话框

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
	EditGoodDlg(CWnd* pParent = NULL);   // 标准构造函数
	EditGoodDlg(long goodId);
	virtual ~EditGoodDlg();
	void GetRecom(CString&recom);

// 对话框数据
	enum { IDD = IDD_DIALOG_ADD_GOODS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
	//afx_msg void addAdvPic(); // 添加廣告圖



protected:
	afx_msg void editGood(); /*编辑商品*/
	afx_msg void uploadFileBgat(); /*上傳商品背面照*/
	afx_msg void uploadFileBig1(); /*上傳大圖1*/
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
	void showBigPic();

private:
	std::list<file> bigFileList; /*商品大图*/
	std::list<file> cutFileList; /*商品切图*/
	CStatic**bigCsList = NULL; 
	long adv_pic_id = 0;
};
