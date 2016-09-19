///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      16-¾ÅÔÂ-2016 15:39:01
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_65F0A035_1FF3_4486_8B94_C127775C2363__INCLUDED_)
#define EA_65F0A035_1FF3_4486_8B94_C127775C2363__INCLUDED_
#include<iostream>
#include"resource.h"
#include<afxwin.h>
class MyView : public CView
{

public:
	MyView();
	virtual ~MyView();
protected:DECLARE_DYNCREATE(MyView, CView);
protected:DECLARE_MESSAGE_MAP(MyView, CView);
private:CButton m_wndPushButton;
private:CButton m_wndRadio;
protected:void OnDraw(CDC*pDC);
protected:virtual BOOL OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:afx_msg void OnButton();
};
#endif // !defined(EA_65F0A035_1FF3_4486_8B94_C127775C2363__INCLUDED_)
