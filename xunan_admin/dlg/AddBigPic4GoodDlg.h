#pragma once

#include"../resource.h"
#include"../util/Util.h"
#include"../util/ShowJpg.h"
#include"../service/good_file_service.h"
#include"../service/upload_service.h"
#include"../util/file_type_enum.h"
#include"BaseBigPic4GoodDlg.h"

// AddBigPic4GoodDlg �Ի���

class AddBigPic4GoodDlg : public BaseBigPic4GoodDlg
{
	DECLARE_DYNAMIC(AddBigPic4GoodDlg)
//
//private:
//	CStatic img;
//	CRect rect;
//	CString filePath;
//
//	long goodId;
//
//	good_file_service *gfs;
//	upload_service *us;
	
public:
	AddBigPic4GoodDlg(long goodId, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddBigPic4GoodDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADD_BIGPIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//afx_msg void selFile();
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void addBigPic();
};
