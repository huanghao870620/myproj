#pragma once
#include"../resource.h"
#include"../ctrl/BigPicListCtrl.h"
#include"../service/good_file_service.h"
#include"../util/file_type_enum.h"
#include"AddBigPic4GoodDlg.h"

// BigPicDlg 对话框

class BigPicDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BigPicDlg)

public:
	BigPicDlg(long goodId, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BigPicDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_BIG_PIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

	afx_msg void addBigPic();
	afx_msg void refresh();
	afx_msg void delBigPic();

private:
	BigPicListCtrl clistCtrl;
	//CImageList m_Imagelist;
	good_file_service*gfs;
	long goodId;
	CButton add;

	typedef odb::core::transaction tran;
	typedef odb::transaction t;
	typedef std::auto_ptr<odb::database> data;

};
