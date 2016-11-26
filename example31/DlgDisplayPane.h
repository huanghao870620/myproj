#pragma once
#include "afxdockablepane.h"
#include"DlgDisplay.h"
class CDlgDisplayPane :
	public CDockablePane
{
public:
	CDlgDisplayPane();
	~CDlgDisplayPane();

private:CDlgDisplay m_display;
protected:virtual int OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:DECLARE_MESSAGE_MAP();
};

