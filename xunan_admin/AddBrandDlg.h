#pragma once
#include"resource.h"
#include<iostream>
#include"brand.h"
#include"brand_service.h"
#include"Util.h"
#include"file.h"
#include"file_service.h"
#include"upload_service.h"
#include"ShowJpg.h"

// AddBrandDlg �Ի���

class AddBrandDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddBrandDlg)

public:
	AddBrandDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddBrandDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADDBRAND };

private:CEdit brandNameEdit; /*Ʒ������*/
private:CStatic brandImg; /*Ʒ��ͼƬ*/

private:CString filePath;

private:brand_service*bs;
private:file_service*fs;
private:upload_service*us;
protected:afx_msg void addBrand();
protected:afx_msg void selectImg();
protected:virtual BOOL OnInitDialog();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
