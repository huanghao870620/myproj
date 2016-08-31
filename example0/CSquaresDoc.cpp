///////////////////////////////////////////////////////////
//  CSquaresDoc.cpp
//  Implementation of the Class CSquaresDoc
//  Created on:      29-°ËÔÂ-2016 17:22:57
//  Original author: huang.hao
///////////////////////////////////////////////////////////
#include "resource.h"
#include "CSquaresDoc.h"

BEGIN_MESSAGE_MAP(CSquaresDoc,CDocument)
	ON_COMMAND(ID_COLOR_BLUE, OnColorBlue)
	ON_COMMAND(ID_COLOR_CYAN,OnColorCyan)
	ON_COMMAND(ID_COLOR_GREEN,OnColorGreen)
	ON_COMMAND(ID_COLOR_RED,OnColorRed)
	ON_COMMAND(ID_COLOR_WHITE,OnColorWhite)
	ON_COMMAND(ID_COLOR_YELLOW,OnColorYellow)

	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE,OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_CYAN,OnUpdateColorCyan)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN,OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_WHITE,OnUpdateColorWhite)
	ON_UPDATE_COMMAND_UI(ID_COLOR_YELLOW,OnUpdateColorYellow)
END_MESSAGE_MAP()


IMPLEMENT_DYNCREATE(CSquaresDoc,CDocument)

CSquaresDoc::CSquaresDoc(){
	std::cout << "create csquaresdoc" << std::endl;
}



CSquaresDoc::~CSquaresDoc(){

}

void CSquaresDoc::OnColorBlue(){

}

void CSquaresDoc::OnColorCyan(){

}

void CSquaresDoc::OnColorGreen(){}

void CSquaresDoc::OnColorRed(){
	std::cout << "select red menu" << std::endl;
}

void CSquaresDoc::OnColorWhite(){}

void CSquaresDoc::OnColorYellow(){}

void CSquaresDoc::OnUpdateColorRed(CCmdUI *pCmdUI){
	std::cout << "update red" << std::endl;
}

void CSquaresDoc::OnUpdateColorBlue(CCmdUI *pCmdUI){
	std::cout << "update blue" << std::endl;
}

void CSquaresDoc::OnUpdateColorCyan(CCmdUI *pCmdUI){
	std::cout << "update cyan" << std::endl;
}

void CSquaresDoc::OnUpdateColorGreen(CCmdUI *pCmdUI){
	std::cout << "update green" << std::endl;
}


void CSquaresDoc::OnUpdateColorWhite(CCmdUI *pCmdUI){
	std::cout << "update white" << std::endl;
}

void CSquaresDoc::OnUpdateColorYellow(CCmdUI *pCmdUI){
	std::cout << "update yellow" << std::endl;
}

COLORREF CSquaresDoc::GetSquares(int i, int j){
	ASSERT(i >= 0 && i <= 3 && j >= 0 && j <= 3);
	return this->m_clrGrid[i][j];
}


#ifdef _DEBUG
void  CSquaresDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSquaresDoc::Dump(CDumpContext &dc) const
{
	CDocument::Dump(dc);
}
	  
#endif // _DEBUG
