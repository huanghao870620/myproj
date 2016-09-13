///////////////////////////////////////////////////////////
//  CScrollDemoView.h
//  Implementation of the Class CScrollDemoView
//  Created on:      12-¾ÅÔÂ-2016 17:34:53
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_CA6B56CD_31C4_495b_AFE8_73426F02D3B7__INCLUDED_)
#define EA_CA6B56CD_31C4_495b_AFE8_73426F02D3B7__INCLUDED_
#include"MyDoc.h"
#include<afxwin.h>
class CScrollDemoView : public CScrollView
{

public:
	CScrollDemoView();
	virtual ~CScrollDemoView();
	DECLARE_DYNCREATE(CScrollDemoView)

public: MyDoc* GetDocument();
public:virtual void OnDraw(CDC *pDC);
public:virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:virtual void OnInitialUpdate();
protected:BOOL m_bSmooth;
protected:void GetCellRect(int row, int col, LPRECT pRect);
protected:void DrawAddress(CDC *pDC, int row, int col);
protected:void DrawPointer(CDC *pDc, int row, int col, BOOL bHighlight);
protected: CFont m_font;
protected:int m_nCurrentCol;
protected:int m_nCurrentRow;
protected:int m_nRibbonWidth;
protected:int m_nCellHeight;
protected:int m_nCellWidth;
#ifdef _DEBUG
protected:void AssertValid() const;
protected:void Dump(CDumpContext& dc) const;
#endif
protected: afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
protected: DECLARE_MESSAGE_MAP();
};
#endif // !defined(EA_CA6B56CD_31C4_495b_AFE8_73426F02D3B7__INCLUDED_)
