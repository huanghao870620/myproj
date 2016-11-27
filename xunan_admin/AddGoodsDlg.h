#pragma once
#pragma execution_character_set("utf-8")
#include<iostream>
#include<list>
#include<vector>

#include"resource.h"
#include<afxdialogex.h>
#include"MyFrame.h"
#include"MyDoc.h"
#include"charset_util.h"
#include"Util.h"
#include"ShowJpg.h"
#include"good_file_service.h"
#include"file.h"
#include"UploadFile.h"
#include"good_service.h"
#include"classification_service.h"
#include"file_service.h"

//#include"util\"

// AddGoodsDlg 对话框

class AddGoodsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddGoodsDlg)

public:
	AddGoodsDlg(CWnd* pParent = NULL);   // 标准构造函数
public:AddGoodsDlg(long goodId);
public:virtual ~AddGoodsDlg();

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
protected:afx_msg void SetSecondClass();/*点击一级分类*/
protected:afx_msg void SetThirdClass();/*点击二级分类*/
protected:afx_msg void SelThirdClass();/*点击三级分类*/
protected:virtual BOOL OnEraseBkgnd(CDC*pDC);
private:CString Big1path; /*商品大圖1*/
private:CString big2Path; /*商品大圖2*/
private:CString thumbPath;/*縮略圖*/
private:CString cutFigure1Path;/*切圖1*/
private:CString cutFigure2Path;/*切圖2*/

private:long goodId;

private:RECT big1Rect;
private:RECT thumbRect;/*缩略图*/

private:int selClass; /*选择分类*/

protected:afx_msg void f1();
protected:afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
protected:afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
protected:afx_msg void OnPaint();

private:CStatic gatp; // 商品縮略圖
private:CStatic bgat; //商品大圖1
private:CStatic pp; // 商品大圖2

private:CStatic cutFigure1; // 切圖1
private:CStatic cutFigure2; //切圖2

private:CEdit nameEdit; /*商品名称编辑控件*/
private:CEdit infoEdit;/*描述*/
private:CEdit capacityEdit;/*容量*/
private:CWnd dateOfProductionControl;/*生产日期*/
private:CEdit lowestPriceEdit;/*最低价*/
private:CEdit highestPriceEdit;/*最高价*/
private:CEdit purchasPositonEdit;/*采购位置*/
private:CComboBox firstClass;/*一级分类*/
private:CComboBox secondClass;/*二级分类*/
private:CComboBox thirdClass;/*三级分类*/

private:int m_nYPos = 0;
private:int m_nXPos = 0;


private:std::string localPath;


private:long thumbFileId; /*缩略图文件id*/


private:std::list<file*> bigFileList; /*商品大图*/

private:long getClassId(std::list<long> *ls, int index);
private:void SetCurSel(CComboBox *box, long id, int i);
private:HRESULT ShowPic(CDC* pDC, CString strImgUrl, CRect rect);
private:std::string getPath(std::string&path, std::string&filename);
private:BOOL CreateMuliteDirectory(CString P);
private:BOOL FolderExists(CString s);
private:std::vector<std::string> mySplit(const std::string& str, std::string sp_string);
private:std::string myReplaceAll(const std::string& str, std::string org_str, std::string rep_str);

private:void init();

private:file_service*fs;
private:good_file_service*gfs;
private:classification_service*cs;

private:CStringW ConvertUTF82CStringW(char* instr);/*转换为utf8*/
protected:virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
};
