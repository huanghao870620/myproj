///////////////////////////////////////////////////////////
//  CMainWindow.h
//  Implementation of the Class CMainWindow
//  Created on:      18-¾ÅÔÂ-2016 12:19:01
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_534A6193_87C0_4270_B095_6AE96036C1C8__INCLUDED_)
#define EA_534A6193_87C0_4270_B095_6AE96036C1C8__INCLUDED_
#include"CMyApp.h"
#include<afxwin.h>
#include<iostream>
class CMainWindow : public CWnd
{

public:
	CMainWindow();
	virtual ~CMainWindow();
protected:DECLARE_MESSAGE_MAP()
protected:int m_cxChar;
protected:int m_cyChar;
protected:CFont m_fontMain;
protected:CFont m_fontSample;

protected:afx_msg BOOL OnCreate(LPCREATESTRUCT lpcs);
};
#endif // !defined(EA_534A6193_87C0_4270_B095_6AE96036C1C8__INCLUDED_)
