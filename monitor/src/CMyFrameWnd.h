#ifndef CMYFRAMEWND_H
#define CMYFRAMEWND_H
#include <list>
#include <string>
#include "Client.h"

class MfcMulti;
class MyDialog;

class CMyFrameWnd : public CFrameWnd
{
    public:

        CMyFrameWnd(); 
        ~CMyFrameWnd(); 

        afx_msg void OnPaint(); //��ͼ
        afx_msg void OnAbout();  //
		afx_msg void OnCreate();
		afx_msg void OnClicked(); // ���״̬
		afx_msg void OnClickedDupData(); // �ظ�����
		afx_msg void OnClicked4ErrorLog(); //������־
		afx_msg void OnClose(); //�رմ���

private:
	std::list<CStatic*> list; // �����ı��ؼ�
	std::list<CStatic *> content_list; // �����ı��ؼ�
	std::list<std::string *> str_list; // �ַ���
	CButton m_button; // ��ذ�ť
	CButton aofdup_data; // �����ظ�����
	CButton json_error_but; // json error button

	MfcMulti *mm = nullptr; // �߳�
	MyDialog *mDialog = nullptr; // �Ի���

private:
	void init_crect(CRect & ct); // ��ʼ��
	void add_crect_hori(CRect & ct, int & x); //��������
	void add_crect_vertical(CRect &ct, int & y); //��������
	

private:
		DECLARE_MESSAGE_MAP()
};  



#endif
