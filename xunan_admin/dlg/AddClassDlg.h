#pragma once
#include"../resource.h"

#include<iostream>


#include"../util/ShowJpg.h"
#include"../util/Util.h"
#include"../entity/classification.h"
#include"../util/UploadFile.h"
#include"../entity/file.h"
#include"../service/file_service.h"
#include"../service/classification_service.h"
#include"../util/charset_util.h"


// AddClass 对话框
class AddClassDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddClassDlg)

public:
	AddClassDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddClassDlg();

// 对话框数据
	enum { IDD = IDD_ADD_CLASS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
protected: virtual BOOL OnInitDialog();
private: CStatic img;
private:classification classi;/*分类*/
private:CString fileNamePath; /*分类文件路径*/
private:void uploadImg();
private:void AddClass();
	DECLARE_MESSAGE_MAP()
};
