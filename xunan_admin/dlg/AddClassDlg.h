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
