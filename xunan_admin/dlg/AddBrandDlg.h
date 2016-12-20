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

// AddBrandDlg �Ի���

class AddBrandDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddBrandDlg)

public:
	AddBrandDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddBrandDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADDBRAND };
//
private:CEdit brandNameEdit; /*Ʒ������*/
private:CEdit brandInfo;/*Ʒ������*/
private:CStatic brandImg; /*Ʒ��ͼƬ*/
private:CComboBox uploadTypeComboBox; /*�ϴ����� 1-���� 2-Ѱ��  3-�̼�*/

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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
