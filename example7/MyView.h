///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      16-¾ÅÔÂ-2016 15:39:01
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_65F0A035_1FF3_4486_8B94_C127775C2363__INCLUDED_)
#define EA_65F0A035_1FF3_4486_8B94_C127775C2363__INCLUDED_
#include<afxlistctrl.h>
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
private:CButton m_wndDefPushButton;
private:CButton m_wndRadio;
private:CButton m_wndAutoCheckBox;
private:CButton m_wnd3State;
private:CButton m_wndAuto3State;
private:CButton m_wndRadioButton;
private:CButton m_wndAutoRadioButton;
private:CButton m_wndGroupBox;
private:CListCtrl m_wndListCtrl;
private:CButton m_wndCheckBox0;
private:CButton m_wndCheckBox1;
private:CButton m_wndCheckBox2;
private:CButton m_wndCheckBox3;
private:CStatic m_wndStatic;

private:CStatic m_wndStatic0;
private:CButton m_wndRadioButton0;
private:CButton m_wndRadioButton1;
private:CButton m_wndRadioButton2;
private:CButton m_wndRadioButton3;

protected:void OnDraw(CDC*pDC);
protected:virtual BOOL OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:afx_msg void OnButton();
protected:afx_msg void OnCheckBox0();
protected:afx_msg void OnCheckBox1();
protected:afx_msg void OnCheckBox2();
protected:afx_msg void OnCheckBox3();

protected:afx_msg void OnRadioButton0();
protected:afx_msg void OnRadioButton1();
protected:afx_msg void OnRadioButton2();
protected:afx_msg void OnRadioButton3();
};
#endif // !defined(EA_65F0A035_1FF3_4486_8B94_C127775C2363__INCLUDED_)
