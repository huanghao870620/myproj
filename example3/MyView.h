///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      14-¾ÅÔÂ-2016 14:15:32
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_753C7D69_F941_4600_A5DD_C99DDFFB08D9__INCLUDED_)
#define EA_753C7D69_F941_4600_A5DD_C99DDFFB08D9__INCLUDED_
#include"MyDoc.h"
#include<afxwin.h>
#include<afxhtml.h>
class MyView : public CHtmlView
{
	DECLARE_DYNCREATE(MyView,CHtmlView)
public:
	MyView();
	virtual ~MyView();
	DECLARE_MESSAGE_MAP()

public:MyDoc* GetDocument();
public:virtual void OnDraw(CDC *pDC);
public:virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:virtual void OnTitleChange(LPCTSTR lpszText);
protected: virtual void OnInitialUpdate();

#ifdef _DEBUG
public:virtual void AssertValid() const;
public:virtual void Dump(CDumpContext&dc) const;
#endif
};
#endif // !defined(EA_753C7D69_F941_4600_A5DD_C99DDFFB08D9__INCLUDED_)
