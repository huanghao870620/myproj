///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      16-Ê®ÔÂ-2016 22:43:38
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_991878FC_1DC8_4beb_BAC3_87E0FC90B0A5__INCLUDED_)
#define EA_991878FC_1DC8_4beb_BAC3_87E0FC90B0A5__INCLUDED_
#include<afxwin.h>
class MyView : public CView
{

public:
	MyView();
	virtual ~MyView();
protected:DECLARE_DYNCREATE(MyView, CView)
protected:DECLARE_MESSAGE_MAP(MyView, CView)
public:virtual void OnDraw(CDC*pDC);
};
#endif // !defined(EA_991878FC_1DC8_4beb_BAC3_87E0FC90B0A5__INCLUDED_)
