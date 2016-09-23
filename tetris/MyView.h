///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      23-¾ÅÔÂ-2016 9:04:27
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_043DDCAC_9485_4585_8D96_AE7288822F71__INCLUDED_)
#define EA_043DDCAC_9485_4585_8D96_AE7288822F71__INCLUDED_
#include<afxwin.h>
class MyView : public CView
{

public:
	MyView();
	virtual ~MyView();
protected:DECLARE_DYNCREATE(MyView, CView)
protected:DECLARE_MESSAGE_MAP(MyView, CView)
protected:virtual void OnDraw(CDC*pDC);
};
#endif // !defined(EA_043DDCAC_9485_4585_8D96_AE7288822F71__INCLUDED_)
