///////////////////////////////////////////////////////////
//  MyView.cpp
//  Implementation of the Class MyView
//  Created on:      12-ÆßÔÂ-2016 10:23:35
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyView.h"

//IMPLEMENT_DYNAMIC(MyView,CView)
IMPLEMENT_DYNCREATE(MyView,CView)


BEGIN_MESSAGE_MAP(MyView,CView)
	ON_WM_LBUTTONDOWN(OnLButtonDown)
	ON_WM_MOUSEMOVE(OnMouseMove)
	ON_WM_LBUTTONUP(OnLButtonUp)
END_MESSAGE_MAP()

MyView::MyView(){
	this->m_bDraw = false;
	this->m_Hcursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
}



MyView::~MyView(){

}


void MyView::OnDraw(CDC *pDC){
	OutputDebugString("");
}

void MyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetCursor(this->m_Hcursor);
	this->m_bDraw = true;
	this->m_pOld = point;
	this->SetCapture();

	CRect rect;
	GetClientRect(&rect);
	ClientToScreen(&rect);
	ClipCursor(rect);
	CView::OnLButtonDown(nFlags, point);
}

void MyView::OnMouseMove(UINT nFlags, CPoint point){
	if (this->m_bDraw){
		CClientDC dc(this);
		dc.MoveTo(this->m_pOld);
		dc.LineTo(point);
		this->m_pOld = point;
	}
	CView::OnMouseMove(nFlags, point);
}

void MyView::OnLButtonUp(UINT nFlags, CPoint point){
	this->m_bDraw = false;
	ReleaseCapture();
	ClipCursor(NULL);
	CView::OnLButtonUp(nFlags, point);
}

