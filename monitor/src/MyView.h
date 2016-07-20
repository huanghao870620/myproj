///////////////////////////////////////////////////////////
//  MyView.h
//  Implementation of the Class MyView
//  Created on:      12-∆ﬂ‘¬-2016 10:23:35
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_B1AC21D4_BA72_4fe2_BB2A_CC2B823CB3B2__INCLUDED_)
#define EA_B1AC21D4_BA72_4fe2_BB2A_CC2B823CB3B2__INCLUDED_
#include<afxwin.h>
#include"ChatDialog.h"
/**
 *  ”Õº
 */
class MyView : public CView
{
	DECLARE_DYNCREATE(MyView)
public:
	MyView();
	virtual ~MyView();

	CButton but;

protected:
	bool m_bDraw;
	HCURSOR m_Hcursor;
	CPoint m_pOld;


	afx_msg void OnLButtonDown(UINT nFlags, CPoint  point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDraw(CDC* pDC);
	afx_msg void OnClicked();
	afx_msg int OnCreate(LPCREATESTRUCT lpcs);
	afx_msg void doCommand();
	DECLARE_MESSAGE_MAP();

private:
	ChatDialog *chatDialog = nullptr;

};
#endif // !defined(EA_B1AC21D4_BA72_4fe2_BB2A_CC2B823CB3B2__INCLUDED_)
