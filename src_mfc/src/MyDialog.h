#ifndef MYDIALOG_H
#define MYDIALOG_H
#include <afxwin.h>
#include <afxcmn.h>

class DataCollection;
class MyDialog : public CDialog
{

    public:

        MyDialog(); 

		MyDialog(int idd,CWnd *wnd);

        ~MyDialog(); 

		void ReDraw(); // 重绘

		afx_msg void OnClear(); // 删除
		afx_msg void OnFlush(); // 刷新

		virtual BOOL OnInitDialog();

private:
	DataCollection *dc = nullptr;
	CStatic text;
	CListCtrl m_UserList;
	CButton cButton; // 清除按钮
	CButton flushButton; // 刷新按钮

private:
	DECLARE_MESSAGE_MAP()
};  



#endif
