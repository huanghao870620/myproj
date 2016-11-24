#pragma once
#pragma execution_character_set("utf-8")
#include<iostream>
#include<list>
#include"resource.h"
#include<afxdialogex.h>
#include"MyFrame.h"
#include"MyDoc.h"
#include"charset_util.h"
#include"Util.h"
#include"ShowJpg.h"
#include"file_dao.h"
#include"good_file_dao.h"
#include"file.h"
#include"UploadFile.h"
//#include"util\"

// AddGoodsDlg 对话框

class AddGoodsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddGoodsDlg)

public:
	AddGoodsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddGoodsDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADD_GOODS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
protected:afx_msg void addGood(); /*添加商品*/
protected:afx_msg void uploadFileGatp(); /*上传商品正面照*/
protected:afx_msg void uploadFileBgat(); /*上傳商品背面照*/
protected:afx_msg void uploadFileBig1(); /*上傳大圖1*/
protected:afx_msg void uploadFileBig2(); /*上傳大圖2*/
protected:afx_msg void uploadCutFigure1(); /*切圖1*/
protected:afx_msg void uploadCutFigure2(); /*切圖2*/
protected:afx_msg void SetSecondClass();/*设置二级分类*/
protected:virtual BOOL OnEraseBkgnd(CDC*pDC);
private:CString Big1path; /*商品大圖1*/
private:CString big2Path; /*商品大圖2*/
private:CString thumbPath;/*縮略圖*/
private:CString cutFigure1Path;/*切圖1*/
private:CString cutFigure2Path;/*切圖2*/


private:RECT big1Rect;

protected:afx_msg void f1();
protected:afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
protected:afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
protected:afx_msg void OnPaint();

private:CStatic gatp; // 商品縮略圖
private:CStatic bgat; //商品大圖1
private:CStatic pp; // 商品大圖2

private:CStatic cutFigure1; // 切圖1
private:CStatic cutFigure2; //切圖2

private:int m_nYPos = 0;
private:int m_nXPos = 0;

private:CStringW ConvertUTF82CStringW(char* instr);/*转换为utf8*/
protected:virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
};
