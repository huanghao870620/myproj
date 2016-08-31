///////////////////////////////////////////////////////////
//  CSquaresView.cpp
//  Implementation of the Class CSquaresView
//  Created on:      29-°ËÔÂ-2016 17:23:50
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
	CSquaresDoc * pDoc = this->GetDocument();
	ASSERT_VALID(pDoc);
	pDC->SetMapMode(MM_LOENGLISH);

	for (size_t i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++){
			COLORREF color = pDoc->GetSquares(i, j);
			CBrush brush(color);
			int x1 = (j * 100) + 50;
			int y1 = (i*-100) - 50;
			int x2 = x1 + 100;
			int y2 = y1 - 100;
			CRect rect(x1, y1, x2, y2);
			pDC->FillRect(rect, &brush);
		}
	}
}

CSquaresDoc* CSquaresView::GetDocument(){
	ASSERT(this->m_pDocument->IsKindOf(RUNTIME_CLASS(CSquaresDoc)));
	return (CSquaresDoc*)this->m_pDocument;
}