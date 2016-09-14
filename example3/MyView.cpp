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