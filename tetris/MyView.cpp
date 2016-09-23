///////////////////////////////////////////////////////////
//  MyView.cpp
//  Implementation of the Class MyView
//  Created on:      23-¾ÅÔÂ-2016 9:04:28
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyView.h"

IMPLEMENT_DYNCREATE(MyView,CView)
BEGIN_MESSAGE_MAP(MyView,CView)
END_MESSAGE_MAP()
MyView::MyView(){

}



MyView::~MyView(){

}

void MyView::OnDraw(CDC*pDC){
	/*CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(rect, RGB(0, 255, 0));*/

	/*CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BG);
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);
	dcCompatible.SelectObject(bitmap);

	CRect rect;
	GetClientRect(&rect);
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);*/

	/*CPaintDC dc(this);
	CFile m_file("C:\\Users\\Public\\Pictures\\Sample Pictures\\Desert.jpg", CFile::modeRead);
	DWORD m_filelen = m_file.GetLength();
	HGLOBAL m_hglobal = GlobalAlloc(GMEM_MOVEABLE, m_filelen);
	LPVOID pvdata = NULL;
	pvdata = GlobalLock(m_hglobal);
	m_file.Read(pvdata, m_filelen);
	IStream *m_stream;
	GlobalUnlock(m_hglobal);
	CreateStreamOnHGlobal(m_hglobal, TRUE, &m_stream);
	OleLoadPicture(m_stream, m_filelen, TRUE, IID_IPicture, (LPVOID*)&m_picture);
	m_stream->Release();
	m_picture->get_Width(&this->m_width);
	m_picture->get_Height(&this->m_height);
	this->m_IsShow = TRUE;
	m_file.Close();
	if (m_IsShow==TRUE)
	{
		CRect rect;
		GetClientRect(rect);
		int nW, nH;
		nW = rect.Width();
		nH = rect.Height();
		m_picture->Render(dc, 0, 0, nW, nH, 0, m_height, m_width, -m_height, &rect);
		CView::OnDraw(pDC);
	}*/

	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	pDC->SelectObject(pen);
	pDC->MoveTo(10, 20);
	pDC->LineTo(300, 20);
}