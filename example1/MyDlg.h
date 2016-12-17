#pragma once
#include"resource.h"
#include<afxdialogex.h>
#include<iostream>
#include<afxinet.h>
// MyDlg 对话框

class MyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg)

public:
	MyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

private:CStatic pic;

protected:virtual BOOL OnInitDialog();
private:HRESULT ShowPic(char *lpstrImgUrl, CDC*pDC);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
