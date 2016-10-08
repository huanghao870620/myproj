///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      07-Ê®ÔÂ-2016 17:15:55
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_F6299627_B4A0_42b4_9C77_60F6C3DCCC93__INCLUDED_)
#define EA_F6299627_B4A0_42b4_9C77_60F6C3DCCC93__INCLUDED_
#include<afxwin.h>
class MyView : public CView
{

public:
	MyView();
	virtual ~MyView();
protected:DECLARE_DYNCREATE(MyView, CView)
protected:DECLARE_MESSAGE_MAP(MyView, CView)
public:void OnDraw(CDC*pDC);
};
#endif // !defined(EA_F6299627_B4A0_42b4_9C77_60F6C3DCCC93__INCLUDED_)
