#pragma once
#include"resource.h"
#include<afxdialogex.h>
#include<iostream>
#include<afxinet.h>
// MyDlg �Ի���

class MyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg)

public:
	MyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

private:CStatic pic;

protected:virtual BOOL OnInitDialog();
private:HRESULT ShowPic(char *lpstrImgUrl, CDC*pDC);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
