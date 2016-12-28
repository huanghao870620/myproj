///////////////////////////////////////////////////////////
//  BaseBigPic4GoodDlg.h
//  Implementation of the Class BaseBigPic4GoodDlg
//  Created on:      27-十二月-2016 13:10:14
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_3748ACDA_2BA4_4f6b_BFC5_FB46EBE5FE91__INCLUDED_)
#define EA_3748ACDA_2BA4_4f6b_BFC5_FB46EBE5FE91__INCLUDED_
#include "afxdialogex.h"

#include"../resource.h"
#include"../util/Util.h"
#include"../util/ShowJpg.h"
#include"../service/good_file_service.h"
#include"../service/upload_service.h"
#include"../util/file_type_enum.h"

class BaseBigPic4GoodDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BaseBigPic4GoodDlg)

	

public:
	BaseBigPic4GoodDlg(long goodId, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BaseBigPic4GoodDlg();

	// 对话框数据
	enum { IDD = IDD_DIALOG_ADD_BIGPIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg void selFile();
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void addBigPic();
	afx_msg void OnPaint();

	CStatic img;
	CRect rect;
	CString filePath;
	

	long goodId;

	good_file_service *gfs;
	upload_service *us;
};



#endif // !defined(EA_3748ACDA_2BA4_4f6b_BFC5_FB46EBE5FE91__INCLUDED_)
