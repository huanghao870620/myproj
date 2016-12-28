#pragma once
#include"../resource.h"
#include"../util/Config.h"
#include"BaseBigPic4GoodDlg.h"
#include"../service/file_service.h"
// EditBigPic4GoodDlg �Ի���

class EditBigPic4GoodDlg : public BaseBigPic4GoodDlg
{
	DECLARE_DYNAMIC(EditBigPic4GoodDlg)

public:
	EditBigPic4GoodDlg(long picId,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~EditBigPic4GoodDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADD_BIGPIC };

private:
		long picId;
		file_service *fs;
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

	afx_msg void  editBigPic();
	void OnPaint();
};
