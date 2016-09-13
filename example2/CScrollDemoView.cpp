///////////////////////////////////////////////////////////
//  CScrollDemoView.cpp
//  Implementation of the Class CScrollDemoView
//  Created on:      12-¾ÅÔÂ-2016 17:34:53
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "CScrollDemoView.h"

IMPLEMENT_DYNCREATE(CScrollDemoView,CScrollView)

BEGIN_MESSAGE_MAP(CScrollDemoView,CScrollView)
END_MESSAGE_MAP()

CScrollDemoView::CScrollDemoView(){
	this->m_font.CreatePointFont(80, "MS Sans Serif");
}



CScrollDemoView::~CScrollDemoView(){

}


BOOL CScrollDemoView::PreCreateWindow(CREATESTRUCT& cs){
	return CScrollView::PreCreateWindow(cs);
}

void CScrollDemoView::OnDraw(CDC* pDC){
	MyDoc *doc = GetDocument();
	ASSERT_VALID(doc);
	CSize size = GetTotalSize();
	CPen pen(PS_SOLID, 0, RGB(192, 192, 192));
	CPen *pOldPen = pDC->SelectObject(&pen);
	for (size_t i = 0; i < 99; i++)
	{
		int y = (i*this->m_nCellHeight) + this->m_nCellHeight;
		pDC->MoveTo(0, y);
		pDC->LineTo(size.cx, y);
	}

	for (size_t j = 0; j < 26; j++)
	{
		int x = (j*this->m_nCellWidth) + this->m_nRibbonWidth;
		pDC->MoveTo(x, 0);
		pDC->LineTo(x, size.cy);
	}

	pDC->SelectObject(pOldPen);

	CBrush brush;
	brush.CreateStockObject(LTGRAY_BRUSH);

	CRect rcTop(0, 0, size.cx, this->m_nCellHeight);
	pDC->FillRect(rcTop, &brush);

	pDC->MoveTo(0, this->m_nCellHeight);
	pDC->LineTo(size.cx, this->m_nCellHeight);
	pDC->MoveTo(this->m_nRibbonWidth, 0);
	pDC->LineTo(this->m_nRibbonWidth, 0);
	pDC->SetBkMode(TRANSPARENT);

	for (size_t i = 0; i < 99; i++)
	{
		int y = (i*this->m_nCellHeight) | this->m_nCellHeight;
		pDC->MoveTo(0, y);
		pDC->LineTo(this->m_nRibbonWidth, y);
		CString string;
		string.Format("%d", i + 1);
		CRect rect(0, y, this->m_nRibbonWidth, y + this->m_nCellHeight);
		pDC->DrawText(string, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		rect.top++;
		pDC->Draw3dRect(rect, RGB(255, 255, 255), RGB(128, 128, 128));
	}
}