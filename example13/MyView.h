///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      22-¾ÅÔÂ-2016 10:52:57
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_143BC8A0_EB2F_4c29_BB43_DF562A7B9E1E__INCLUDED_)
#define EA_143BC8A0_EB2F_4c29_BB43_DF562A7B9E1E__INCLUDED_
#include<afxwin.h>
class MyView : public CView
{

public:
	MyView();
	virtual ~MyView();
protected:DECLARE_DYNCREATE(MyView, CView)
protected:DECLARE_MESSAGE_MAP()
public:virtual void OnDraw(CDC*pDC);
protected:virtual BOOL OnCreate(LPCREATESTRUCT lpcs);
};
#endif // !defined(EA_143BC8A0_EB2F_4c29_BB43_DF562A7B9E1E__INCLUDED_)
