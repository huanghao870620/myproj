///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      22-九月-2016 10:52:57
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_143BC8A0_EB2F_4c29_BB43_DF562A7B9E1E__INCLUDED_)
#define EA_143BC8A0_EB2F_4c29_BB43_DF562A7B9E1E__INCLUDED_
//#pragma execution_character_set("utf-8")
#include<afxwin.h>
#include"../resource.h"
#include<iostream>
#include"AddGoodsDlg.h"
#include"AddBrandDlg.h"
#include"AddCountryDlg.h"
#include"CountryShow.h"
#include"WatchClassDlg.h"
#include"AddClassDlg.h"
#include"AddVenue.h"
#include"ListGoodsDlg.h"
#include"TestDlg.h"
#include"AddCouponsDlg.h"

class MyView : public CView
{

public:
	MyView();
	virtual ~MyView();
	virtual void OnDraw(CDC*pDC);
	AddGoodsDlg*getAddGoodDlg();
	AddVenue*addVenueDlg;/*添加会场对话框*/
	CRect rc;

protected:
	
	virtual BOOL OnCreate(LPCREATESTRUCT lpcs);
	afx_msg void AddGood();/*添加商品*/
	afx_msg void addBrand();/*添加品牌*/
	afx_msg void addCountry();/*添加国家*/
	afx_msg void watchCountry();/*查看国家*/
	afx_msg void watchClass();/*查看分类*/
	afx_msg void AddClass();/*添加分类*/
	afx_msg void watchGoods();/*商品列表*/
	afx_msg void ShowAddVenueDlg();/*添加会场*/
	afx_msg void ShowTest();
	afx_msg void addCouponsDlg_();

	DECLARE_DYNCREATE(MyView, CView)
	DECLARE_MESSAGE_MAP()

private:
	AddGoodsDlg*pDlg;/*添加商品对话框*/
	AddBrandDlg*brandDlg;/*添加品牌对话框*/
	AddCountryDlg*addCountryDlg;/*添加国家对话框*/
	WatchClassDlg*watchClassDlg;/*查看分类对话框*/
	AddClassDlg*addClassDlg;/*添加分类对话框*/
	ListGoodsDlg*listGoodsDlg;
	CountryShow*countryShowDlg;
	TestDlg*testDlg;
	AddCouponsDlg *addCouponsDlg;
	
};
#endif // !defined(EA_143BC8A0_EB2F_4c29_BB43_DF562A7B9E1E__INCLUDED_)
