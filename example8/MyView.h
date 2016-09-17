///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      17-¾ÅÔÂ-2016 19:24:55
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_9826E1CD_DC3D_49ac_B8FC_AE0D6C6FDFEB__INCLUDED_)
#define EA_9826E1CD_DC3D_49ac_B8FC_AE0D6C6FDFEB__INCLUDED_
#include<afxwin.h>
class MyView : public CView
{
protected:DECLARE_DYNCREATE(MyView,CView)
protected:DECLARE_MESSAGE_MAP(MyView,CView)
public:
	MyView();
	virtual ~MyView();
protected:virtual void OnCreate(LPCREATESTRUCT lpCreateStruct);
public:afx_msg void OnDraw(CDC*pDC);

};
#endif // !defined(EA_9826E1CD_DC3D_49ac_B8FC_AE0D6C6FDFEB__INCLUDED_)
