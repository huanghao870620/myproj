///////////////////////////////////////////////////////////
//  MyView.cpp
//  Implementation of the Class MyView
//  Created on:      12-ÆßÔÂ-2016 10:23:35
//  Original author: huang.hao
///////////////////////////////////////////////////////////
#include "MyView.h"
#include "MyDocument.h"
#include "resource.h"

IMPLEMENT_DYNCREATE(MyView,CView)

BEGIN_MESSAGE_MAP(MyView,CView)
	ON_WM_LBUTTONDOWN(OnLButtonDown)
	ON_WM_MOUSEMOVE(OnMouseMove)
	ON_WM_CREATE()
	ON_BN_CLICKED(1, OnClicked)
	ON_WM_LBUTTONUP(OnLButtonUp)
	ON_COMMAND(ID_40007, doCommand)
END_MESSAGE_MAP()

MyView::MyView(){
	this->m_bDraw = false;
	this->m_Hcursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
	std::cout << "myview constructor" << std::endl;
}



MyView::~MyView(){

}

void MyView::doCommand(){
	this->chatDialog = new ChatDialog;
	this->chatDialog->Create(IDD_DIALOG1, this);
	this->chatDialog->ShowWindow(SW_SHOWNORMAL);

	/*char server_ip[100];
	WORD versionRequested = MAKEWORD(1, 1);
	WSADATA  wsaData;
	WSAStartup(versionRequested, &wsaData);
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock <= 0){
		::MessageBox(NULL, _T("´´½¨socketÊ§°Ü!"), _T(""), MB_OK);
		return;
	}

	SOCKADDR_IN server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(6000);*/
	//Client2 * c2 = new Client2;
	

}

void MyView::OnClicked(){
	//this->MessageBox(_T("cc"));
	 MyDocument * doc = (MyDocument *)this->GetDocument();
	 doc->sendMsg(0);
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

