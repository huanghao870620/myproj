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

		void ReDraw(); // �ػ�

		afx_msg void OnClear(); // ɾ��
		afx_msg void OnFlush(); // ˢ��

		virtual BOOL OnInitDialog();

private:
	CStatic text;
	CListCtrl m_UserList;
	DataCollection * dc = nullptr;
	CButton cButton; // �����ť
	CButton flushButton; // ˢ�°�ť

private:
	DECLARE_MESSAGE_MAP()
};  //end class MyDialog



#endif
