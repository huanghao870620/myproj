#pragma once
#include"resource.h"

#include<iostream>


#include"ShowJpg.h"
#include"Util.h"
#include"classification.h"
#include"UploadFile.h"
#include"file.h"
#include"file_dao.h"
#include"classification_dao.h"
#include"charset_util.h"



// AddClass �Ի���

class AddClassDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddClassDlg)

public:
	AddClassDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddClassDlg();

// �Ի�������
	enum { IDD = IDD_ADD_CLASS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
protected: virtual BOOL OnInitDialog();
private: CStatic img;
private:classification classi;/*����*/
private:CString fileNamePath; /*�����ļ�·��*/
private:void uploadImg();
private:void AddClass();
	DECLARE_MESSAGE_MAP()
};
