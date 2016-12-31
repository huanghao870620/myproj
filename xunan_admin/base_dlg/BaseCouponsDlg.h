#pragma once
#include"../resource.h"
#include "afxdialogex.h"
#include<afxdtctl.h>
#include<list>
#include"../entity/classification.h"
#include"../service/classification_service.h"
#include"../service/brand_service.h"
#include"../util/charset_util.h"
// BaseCouponsDlg �Ի���

class BaseCouponsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BaseCouponsDlg)

public:
	BaseCouponsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BaseCouponsDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADD_COUPONS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()


	CEdit priceEdit;
	CEdit sillEdit;
	CDateTimeCtrl limitStart;
	CDateTimeCtrl limitEnd;
	CComboBox classBox;
	CComboBox brandBox;
	virtual BOOL OnInitDialog();

	classification_service *cs;
	brand_service *bs;

private:
	void loadClass();
	void loadBrand();

};
