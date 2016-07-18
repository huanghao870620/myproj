///////////////////////////////////////////////////////////
//  MyView.cpp
//  Implementation of the Class MyView
//  Created on:      12-����-2016 10:23:35
//  Original author: huang.hao
///////////////////////////////////////////////////////////
#include "MyView.h"

//IMPLEMENT_DYNAMIC(MyView,CView)
IMPLEMENT_DYNCREATE(MyView,CView)


BEGIN_MESSAGE_MAP(MyView,CView)
	ON_WM_LBUTTONDOWN(OnLButtonDown)
	ON_WM_MOUSEMOVE(OnMouseMove)
	ON_WM_CREATE()
	ON_BN_CLICKED(1, OnClicked)
	ON_WM_LBUTTONUP(OnLButtonUp)
	ON_COMMAND(id,dd)
END_MESSAGE_MAP()

MyView::MyView(){
	this->m_bDraw = false;
	this->m_Hcursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
}



MyView::~MyView(){

}

void MyView::OnClicked(){
	this->MessageBox(_T("cc"));
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

int MyView::OnCreate(LPCREATESTRUCT lpcs){
	OutputDebugString(_T(""));
	this->but.Create(_T("aa"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(10, 10, 100, 30), this, 1);
	return 0;
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

