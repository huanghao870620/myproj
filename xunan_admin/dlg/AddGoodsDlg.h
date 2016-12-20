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
protected:afx_msg void uploadAdvPic();/*上传广告图*/
protected:afx_msg void uploadFileBig1(); /*上傳大圖1*/
protected:afx_msg void uploadFileBig2(); /*上傳大圖2*/
protected:afx_msg void uploadCutFigure1(); /*切圖1*/
protected:afx_msg void uploadCutFigure2(); /*切圖2*/
protected:afx_msg void SetSecondClass();/*点击一级分类*/
protected:afx_msg void SetThirdClass();/*点击二级分类*/
protected:afx_msg void SelThirdClass();/*点击三级分类*/
protected:afx_msg void selRecommended();/*选择推荐*/
protected:afx_msg void selNotRecommended();/*选择不推荐*/
protected:virtual BOOL OnEraseBkgnd(CDC*pDC);
private:CString big1Path; /*商品大圖1*/
private:CString big2Path; /*商品大圖2*/
private:CString big3Path;
private:CString big4Path;
private:CString big5Path;
private:CString big6Path;
private:CString big7Path;
private:CString big8Path;
private:CString thumbPath;/*縮略圖*/
private:CString advPath;/*广告图*/
private:CString cutFigure1Path;/*切圖1*/
private:CString cutFigure2Path;/*切圖2*/
private:CString cutFigure3Path;/*切图3*/
private:CString cutFigure4Path;/*切图4*/
private:CString cutFigure5Path;/*切图5*/
private:CString cutFigure6Path;/*切图6*/
private:CString cutFigure7Path;/*切图7*/
private:CString cutFigure8Path;/*切图8*/
private:CString cutFigure9Path;/*切图9*/
private:CString cutFigure10Path;/*切图10*/
private:CString cutFigure11Path;/*切图11*/
private:CString cutFigure12Path;/*切图12*/
private:CString cutFigure13Path;/*切图13*/
private:CString cutFigure14Path;/*切图14*/
private:CString cutFigure15Path;/*切图15*/
private:CString cutFigure16Path;/*切图16*/
private:CString cutFigure17Path;/*切图17*/
private:CString cutFigure18Path;/*切图18*/
private:CString cutFigure19Path;/*切图19*/
private:CString cutFigure20Path;/*切图20*/

		

private:long goodId;

private:RECT big1Rect;
private:RECT thumbRect;/*缩略图*/
private:RECT advRect;/*广告图*/

private:int selClass; /*选择分类*/

protected:afx_msg void f1();
protected:afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
protected:afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
protected:afx_msg void OnPaint();

private:CStatic gatp;// 商品縮略圖
private:CStatic advPic;//商品广告图

private:CStatic big1;//大圖1
private:CStatic big2;//大图2
private:CStatic big3;//大图3
private:CStatic big4;//大图4
private:CStatic big5;//大图5
private:CStatic big6;//大图6
private:CStatic big7;//大图7
private:CStatic big8;//大图8

private:CStatic cutFigure1; //切圖1
private:CStatic cutFigure2; //切圖2
private:CStatic cutFigure3;//切圖3
private:CStatic cutFigure4;//切圖4
private:CStatic cutFigure5;//切圖5
private:CStatic cutFigure6;//切圖6
private:CStatic cutFigure7;//切圖7
private:CStatic cutFigure8;//切圖8
private:CStatic cutFigure9;//切圖9
private:CStatic cutFigure10;//切圖10
private:CStatic cutFigure11;//切圖11
private:CStatic cutFigure12;//切圖12
private:CStatic cutFigure13;//切圖13
private:CStatic cutFigure14;//切圖14
private:CStatic cutFigure15;//切圖15
private:CStatic cutFigure16;//切圖16
private:CStatic cutFigure17;//切圖17
private:CStatic cutFigure18;//切圖18
private:CStatic cutFigure19;//切圖19
private:CStatic cutFigure20;//切圖20

private:CEdit nameEdit; /*商品名称编辑控件*/
private:CEdit infoEdit;/*描述*/
private:CEdit capacityEdit;/*容量*/
private:CWnd dateOfProductionControl;/*生产日期*/
private:CEdit lowestPriceEdit;/*最低价*/
private:CEdit highestPriceEdit;/*最高价*/
private:CEdit priceEdit;/*商品实际价格*/
private:CEdit purchasPositonEdit;/*采购位置*/
private:CComboBox firstClass;/*一级分类*/
private:CComboBox secondClass;/*二级分类*/
private:CComboBox thirdClass;/*三级分类*/

private:CComboBox brandSel; /*品牌*/

private:CButton isRecom; /*推荐*/
private:CButton isNotRecom;/*不推荐*/

private:int m_nYPos = 0;
private:int m_nXPos = 0;


private:std::string localPath;
//private:std::string thubmLocalPath;/*缩略图本地存储路径*/


private:long thumbFileId; /*缩略图文件id*/


private:std::list<file*> bigFileList; /*商品大图*/
private:std::list<file*> cutFileList; /*商品切图*/

private:long getClassId(std::list<long> *ls, int index);
private:void SetCurSel(CComboBox *box, long id, int i);
private:HRESULT ShowPic(CDC* pDC, CString strImgUrl, CRect rect);
private:std::string getPath(std::string&path, std::string&filename);
private:BOOL CreateMuliteDirectory(CString P);
private:BOOL FolderExists(CString s);
private:std::vector<std::string> mySplit(const std::string& str, std::string sp_string);
private:std::string myReplaceAll(const std::string& str, std::string org_str, std::string rep_str);

private:void init();
private:void downloadFtpFile(file*f);

private:file_service*fs;
private:good_file_service*gfs;
private:classification_service*cs;
private:good_service*gs;
private:upload_service*us;
private:brand_service*bs;

private:CStringW ConvertUTF82CStringW(char* instr);/*转换为utf8*/
protected:virtual BOOL OnInitDialog();

public:void GetRecom(CString&recom);

	DECLARE_MESSAGE_MAP()
};
