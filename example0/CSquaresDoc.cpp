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
	this->m_clrCurrentColor = RGB(0, 0, 255);
}

void CSquaresDoc::OnColorCyan(){
	this->m_clrCurrentColor = RGB(0, 255, 255);
}

void CSquaresDoc::OnColorGreen(){
	this->m_clrCurrentColor = RGB(0, 255, 0);
}

void CSquaresDoc::OnColorRed(){
	this->m_clrCurrentColor = RGB(255, 0, 0);
}

void CSquaresDoc::OnColorWhite(){
	this->m_clrCurrentColor = RGB(255, 255, 255);
}

void CSquaresDoc::OnColorYellow(){
	this->m_clrCurrentColor = RGB(255, 255, 0);
}

void CSquaresDoc::OnUpdateColorRed(CCmdUI *pCmdUI){
	pCmdUI->SetRadio(this->m_clrCurrentColor == RGB(255, 0, 0));
}

void CSquaresDoc::OnUpdateColorBlue(CCmdUI *pCmdUI){
	pCmdUI->SetRadio(this->m_clrCurrentColor == RGB(0, 0, 255));
}

void CSquaresDoc::OnUpdateColorCyan(CCmdUI *pCmdUI){
	pCmdUI->SetRadio(this->m_clrCurrentColor == RGB(0, 255, 255));
}

void CSquaresDoc::OnUpdateColorGreen(CCmdUI *pCmdUI){
	pCmdUI->SetRadio(this->m_clrCurrentColor == RGB(0, 255, 0));
}


void CSquaresDoc::OnUpdateColorWhite(CCmdUI *pCmdUI){
	pCmdUI->SetRadio(this->m_clrCurrentColor == RGB(255, 255, 255));
}

void CSquaresDoc::OnUpdateColorYellow(CCmdUI *pCmdUI){
	pCmdUI->SetRadio(this->m_clrCurrentColor == RGB(255, 255, 0));
}

COLORREF CSquaresDoc::GetSquares(int i, int j){
	ASSERT(i >= 0 && i <= 3 && j >= 0 && j <= 3);
	return this->m_clrGrid[i][j];
}
 
BOOL  CSquaresDoc::OnNewDocument(){
	if (!CDocument::OnNewDocument()){
		return FALSE;
	}
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			this->m_clrGrid[i][j] = RGB(255, 255, 255);
		}
	}

	this->m_clrCurrentColor = RGB(255, 0, 0);
	return TRUE;
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

COLORREF CSquaresDoc::GetCurrentColor(){
	return this->m_clrCurrentColor;
}

void CSquaresDoc::SetSquares(int i, int j, COLORREF color){
	ASSERT(i >= 0 && i <= 3 && j >= 0 && j <= 3);
	this->m_clrGrid[i][j] = color;
	SetModifiedFlag(TRUE);
	UpdateAllViews(NULL);
}

