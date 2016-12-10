#include "DlgDisplayPane.h"


CDlgDisplayPane::CDlgDisplayPane()
{
}


CDlgDisplayPane::~CDlgDisplayPane()
{
}

int CDlgDisplayPane::OnCreate(LPCREATESTRUCT lpCreateStruct){
	/*if (CDockablePane::OnCreate(lpCreateStruct) == -1){
		return -1;
	}
	if (!this->m_display.Create(IDD_DIALOG_DISPLAY, this)){
		TRACE0("未能创建窗口");
		return -1;
	}*/
	//this->m_display.ShowWindow(SW_SHOW);
	return 0;
}

BEGIN_MESSAGE_MAP(CDlgDisplayPane, CDockablePane)
	ON_WM_CREATE()
END_MESSAGE_MAP()