///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      19-¾ÅÔÂ-2016 16:07:21
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_BB551AA4_9112_45a3_A229_1752C69B5CF5__INCLUDED_)
#define EA_BB551AA4_9112_45a3_A229_1752C69B5CF5__INCLUDED_
#include<afxwin.h>
class MyView : public CView
{

public:
	MyView();
	virtual ~MyView();
protected:DECLARE_DYNCREATE(MyView, CView)
protected:DECLARE_MESSAGE_MAP()
public:virtual void OnDraw(CDC*pDC);
};
#endif // !defined(EA_BB551AA4_9112_45a3_A229_1752C69B5CF5__INCLUDED_)
