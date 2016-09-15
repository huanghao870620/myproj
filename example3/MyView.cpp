///////////////////////////////////////////////////////////
//  MyView.cpp
//  Implementation of the Class MyView
//  Created on:      14-¾ÅÔÂ-2016 14:15:32
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyView.h"

BEGIN_MESSAGE_MAP(MyView,CHtmlView)
END_MESSAGE_MAP()

IMPLEMENT_DYNCREATE(MyView,CHtmlView)
MyView::MyView(){

}

void MyView::OnDraw(CDC *pDC){
	MyDoc *doc = this->GetDocument();
	ASSERT_VALID(doc);
}

MyView::~MyView(){

}

BOOL MyView::PreCreateWindow(CREATESTRUCT&cs){
	return CHtmlView::PreCreateWindow(cs);
}

void MyView::OnInitialUpdate(){
	CHtmlView::OnInitialUpdate();
	TCHAR szPath[MAX_PATH];
	GetModuleFileName(NULL, szPath, sizeof(szPath) / sizeof(TCHAR));
	CString string = szPath;
	int nIndex = string.ReverseFind('\\');
	ASSERT(nIndex != -1);
	string = string.Left(nIndex + 1) + "Clock.htm";
	Navigate(string);
	//CByteArray d;
	//OnBeforeNavigate2(0,0,0,d,0,0);
	//OnDownloadBegin();
	/*OnProgressChange(100 / 10000);
	OnProgressChange(150 / 10000);*/
}

#ifdef _DEBUG
void MyView::AssertValid() const{
	CHtmlView::AssertValid();
}

void MyView::Dump(CDumpContext&dc)const{
	CHtmlView::Dump(dc);
}

MyDoc* MyView::GetDocument(){
	ASSERT(this->m_pDocument->IsKindOf(RUNTIME_CLASS(MyDoc)));
	return (MyDoc*)this->m_pDocument;
}
#endif

void MyView::OnTitleChange(LPCTSTR lpszText){
	CHtmlView::OnTitleChange(lpszText);
	AfxGetMainWnd()->SetWindowTextA(lpszText);
}