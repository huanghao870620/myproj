///////////////////////////////////////////////////////////
//  CSquaresDoc.h
//  Implementation of the Class CSquaresDoc
//  Created on:      29-°ËÔÂ-2016 17:22:57
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_AC3DFB64_8283_4b48_8B1F_7974621F5D26__INCLUDED_)
#define EA_AC3DFB64_8283_4b48_8B1F_7974621F5D26__INCLUDED_
#include<iostream>
#include<afxwin.h>

class CSquaresDoc : public CDocument
{
	DECLARE_DYNCREATE(CSquaresDoc)
public: CSquaresDoc();
public:virtual ~CSquaresDoc();
public: void SetSquares(int i, int j, COLORREF color);
public: COLORREF GetSquares(int i, int j);
public: COLORREF GetCurrentColor();

#ifdef _DEBUG
public:virtual void AssertValid() const;
public:virtual void Dump(CDumpContext &dc) const;
#endif

protected:afx_msg void OnColorRed();
protected:afx_msg void OnColorYellow();
protected:afx_msg void OnColorGreen();
protected:afx_msg void OnColorCyan();
protected:afx_msg void OnColorBlue();
protected:afx_msg void OnColorWhite();

protected:afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
protected:afx_msg void OnUpdateColorYellow(CCmdUI *pCmdUI);
protected:afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
protected:afx_msg void OnUpdateColorCyan(CCmdUI *pCmdUI);
protected:afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
protected:afx_msg void OnUpdateColorWhite(CCmdUI *pCmdUI);
	DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_AC3DFB64_8283_4b48_8B1F_7974621F5D26__INCLUDED_)
