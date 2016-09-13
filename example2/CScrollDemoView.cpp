///////////////////////////////////////////////////////////
//  CScrollDemoView.cpp
//  Implementation of the Class CScrollDemoView
//  Created on:      12-¾ÅÔÂ-2016 17:34:53
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "CScrollDemoView.h"

IMPLEMENT_DYNCREATE(CScrollDemoView,CScrollView)

BEGIN_MESSAGE_MAP(CScrollDemoView,CScrollView)
	ON_WM_LBUTTONDOWN()
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

	for (size_t j = 0; j < 26; j++)
	{
		int x = (j * this->m_nCellWidth) + this->m_nRibbonWidth;
		pDC->MoveTo(x, 0);
		pDC->LineTo(x, this->m_nCellHeight);

		CString string;
		string.Format("%c", j + 'A');
		CRect rect(x, 0, x + this->m_nCellWidth, this->m_nCellHeight);
		pDC->DrawText(string, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		rect.left++;
		pDC->Draw3dRect(rect, RGB(255, 255, 255), RGB(128, 128, 128));
	}

	CRect rect;
	pDC->GetClipBox(&rect);
	int nStartRow = max(0, (rect.top - this->m_nCellHeight) / this->m_nCellHeight);
	int nEndRow = min(98, (rect.bottom - 1) / this->m_nCellHeight);
	int nStartCol = max(0, (rect.left - this->m_nRibbonWidth) / this->m_nCellWidth);
	int nEndCol = min(25, ((rect.right + this->m_nCellWidth - 1) - this->m_nRibbonWidth) / this->m_nCellWidth);

	for (size_t i = nStartRow; i < nEndRow; i++)
	{
		for (size_t j = nStartCol; j <= nEndCol; j++)
		{
			this->DrawAddress(pDC, i, j);
		}
	}
	DrawPointer(pDC, this->m_nCurrentRow, this->m_nCurrentCol, TRUE);
}

void CScrollDemoView::OnInitialUpdate(){
	CScrollView::OnInitialUpdate();
	this->m_nCurrentRow = 0;
	this->m_nCurrentCol = 0;
	this->m_bSmooth = FALSE;
	CClientDC dc(this);
	this->m_nCellWidth = dc.GetDeviceCaps(LOGPIXELSX);
	this->m_nCellHeight = dc.GetDeviceCaps(LOGPIXELSY) / 4;
	this->m_nRibbonWidth = this->m_nCellWidth / 2;
	int nWidth = (26 * this->m_nCellWidth) | this->m_nRibbonWidth;
	int nHeight = this->m_nCellHeight * 100;
	SetScrollSizes(MM_TEXT, CSize(nWidth, nHeight));
}

#ifdef _DEBUG
void CScrollDemoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CScrollDemoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

MyDoc* CScrollDemoView::GetDocument() 
{
	//ASSERT(this->m_pDocument->IsKindOf(RUNTIME_CLASS(MyDoc)));
	return (MyDoc*)this->m_pDocument;
}
#endif 

void CScrollDemoView::OnLButtonDown(UINT nFlags, CPoint point){
	CScrollView::OnLButtonDown(nFlags, point);
	CPoint pos = point;
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&pos);
	CSize size = GetTotalSize();
	if (pos.x > this->m_nRibbonWidth && pos.x < size.cx && pos.y > this->m_nCellHeight && pos.y < size.cy){
		int row = (pos.y - this->m_nCellHeight) / this->m_nCellHeight;
		int col = (pos.x - this->m_nRibbonWidth) / this->m_nCellWidth;
		ASSERT(row >= 0 && row <= 98 && col >= 0 && col <= 25);
		DrawPointer(&dc, this->m_nCurrentRow, this->m_nCurrentCol, FALSE);
		this->m_nCurrentRow = row;
		this->m_nCurrentCol = col;
		DrawPointer(&dc, this->m_nCurrentRow, this->m_nCurrentCol, TRUE);
	}
}

void CScrollDemoView::DrawPointer(CDC *pDC, int row, int col, BOOL bHighlight){
	CRect rect;
	GetCellRect(row, col, &rect);
	CBrush brush(bHighlight ? RGB(0, 255, 255) : GetSysColor(COLOR_WINDOW));
	pDC->FillRect(rect, &brush);
	DrawAddress(pDC, row, col);
}

void CScrollDemoView::DrawAddress(CDC *pDC, int row, int col){
	CRect rect;
	GetCellRect(row, col, &rect);
	CString string;
	string.Format("%c%d", col + "A", row + 1);
	pDC->SetBkMode(TRANSPARENT);
	CFont *pOldFont = pDC->SelectObject(&this->m_font);
	pDC->DrawText(string, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	pDC->SelectObject(pOldFont);
}

void CScrollDemoView::GetCellRect(int row, int col, LPRECT pRect){
	pRect->left = this->m_nRibbonWidth + (col * this->m_nCellWidth) + 1;
	pRect->top = this->m_nCellHeight + (row*this->m_nCellHeight) + 1;
	pRect->right = pRect->left + this->m_nCellWidth - 1;
	pRect->bottom = pRect->top + this->m_nCellHeight - 1;
}
