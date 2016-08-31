///////////////////////////////////////////////////////////
//  CSquaresView.cpp
//  Implementation of the Class CSquaresView
//  Created on:      29-����-2016 17:23:50
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "CSquaresView.h"


BEGIN_MESSAGE_MAP(CSquaresView,CView)
END_MESSAGE_MAP()

IMPLEMENT_DYNCREATE(CSquaresView,CView)

CSquaresView::CSquaresView(){
	std::cout << "create csquareview" << std::endl;
}



CSquaresView::~CSquaresView(){

}

void CSquaresView::OnDraw(CDC* pDC){
	//std::cout << "on draw" << std::endl;
	CDocument * pDoc = this->GetDocument();
	ASSERT_VALID(pDoc);
	pDC->SetMapMode(MM_LOENGLISH);

	for (size_t i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++){
		}
	}
}

CSquaresDoc* CSquaresView::GetDocument(){
	ASSERT(this->m_pDocument->IsKindOf(RUNTIME_CLASS(CSquaresDoc)));
	return (CSquaresDoc*)this->m_pDocument;
}