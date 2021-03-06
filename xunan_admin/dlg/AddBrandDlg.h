#pragma once
#include"../resource.h"
#include<iostream>
#include"../entity/brand.h"
#include"../service/brand_service.h"
#include"../util/Util.h"
#include"../entity/file.h"
#include"../service/file_service.h"
#include"../service/upload_service.h"
#include"../service/upload_type_service.h"
#include"../util/ShowJpg.h"

// AddBrandDlg 对话框

class AddBrandDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddBrandDlg)

public:
	AddBrandDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddBrandDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADDBRAND };
//
private:CEdit brandNameEdit; /*品牌名称*/
private:CEdit brandInfo;/*品牌描述*/
private:CStatic brandImg; /*品牌图片*/
private:CComboBox uploadTypeComboBox; /*上传类型 1-买手 2-寻安  3-商家*/

private:long uploadType;
private:CString filePath;
//
private:brand_service*bs;
private:file_service*fs;
private:upload_service*us;
private:upload_type_service*uts;
protected:afx_msg void addBrand();
protected:afx_msg void selectImg();
protected:afx_msg void selUploadType();
protected:virtual BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
