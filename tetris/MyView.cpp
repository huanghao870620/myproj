///////////////////////////////////////////////////////////
//  MyView.cpp
//  Implementation of the Class MyView
//  Created on:      23-九月-2016 9:04:28
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyView.h"

IMPLEMENT_DYNCREATE(MyView,CView)
 
BEGIN_MESSAGE_MAP(MyView,CView)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

MyView::MyView(){
	//CRect leftSideRect(10, 10, 37, 520);
	//CBrush brush(RGB(0, 0, 0));
	//brush.DeleteObject();
	//Queue *queue = Queue::getInstance();
	//this->com = queue->get();
}


void MyView::OnMouseMove(UINT nFlags, CPoint point)
{
	
	//std::cout << "222" << std::endl;
	/*std::cout << "x : " << point.x << "\ty: " << point.y << std::endl;
	this->x = point.x;
	this->y = point.y;*/


	// TODO: 在此添加消息处理程序代码和/或调用默认值  

	/*TRACKMOUSEEVENT  tme = { 0 };
	tme.cbSize = sizeof(TRACKMOUSEEVENT);
	tme.dwFlags = TME_HOVER | TME_LEAVE;
	tme.dwHoverTime = HOVER_DEFAULT;
	tme.hwndTrack = this->m_hWnd;
	if (TrackMouseEvent(&tme)){}

	CStatic::OnMouseMove(nFlags, point);*/
}



MyView::~MyView(){

}
//ON_WM_MOUSEMOVE
/**/
void MyView::OnDraw(CDC*pDC){
	//pDC->Ellipse(this->x - r, this->y - r, this->x+10 + r, this->y+10 + r);
} 