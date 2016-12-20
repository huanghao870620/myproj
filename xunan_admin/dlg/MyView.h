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

class MyView : public CView
{

public:
	MyView();
	virtual ~MyView();
protected:DECLARE_DYNCREATE(MyView, CView)
protected:DECLARE_MESSAGE_MAP()
public:virtual void OnDraw(CDC*pDC);
protected:virtual BOOL OnCreate(LPCREATESTRUCT lpcs);
protected:afx_msg void AddGood();/*添加商品*/
protected:afx_msg void addBrand();/*添加品牌*/
protected:afx_msg void addCountry();/*添加国家*/
protected:afx_msg void watchCountry();/*查看国家*/
protected:afx_msg void watchClass();/*查看分类*/
protected:afx_msg void AddClass();/*添加分类*/
protected:afx_msg void watchGoods();/*商品列表*/
protected:afx_msg void ShowAddVenueDlg();/*添加会场*/

private:AddGoodsDlg*pDlg;/*添加商品对话框*/
private:AddBrandDlg*brandDlg;/*添加品牌对话框*/
private:AddCountryDlg*addCountryDlg;/*添加国家对话框*/
private:WatchClassDlg*watchClassDlg;/*查看分类对话框*/
private:AddClassDlg*addClassDlg;/*添加分类对话框*/
private:ListGoodsDlg*listGoodsDlg;
private:CountryShow*countryShowDlg;

public: AddGoodsDlg*getAddGoodDlg();

private:AddVenue*addVenueDlg;/*添加会场对话框*/

		
};
#endif // !defined(EA_143BC8A0_EB2F_4c29_BB43_DF562A7B9E1E__INCLUDED_)
