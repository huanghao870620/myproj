///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      09-¾ÅÔÂ-2016 14:04:31
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_DCB932D8_BD41_44e0_AC36_031FE79178C8__INCLUDED_)
#define EA_DCB932D8_BD41_44e0_AC36_031FE79178C8__INCLUDED_
#include<afxwin.h>
class MyView : public CView
{
	DECLARE_DYNCREATE(MyView)
public:
	MyView();
	virtual ~MyView();

protected:afx_msg void OnDraw(CDC *pDC);
	DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_DCB932D8_BD41_44e0_AC36_031FE79178C8__INCLUDED_)
