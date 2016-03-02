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

        afx_msg void OnPaint(); //绘图
        afx_msg void OnAbout();  //
		afx_msg void OnCreate();
		afx_msg void OnClicked(); // 监控状态
		afx_msg void OnClickedDupData(); // 重复数据
		afx_msg void OnClicked4ErrorLog(); //错误日志
		afx_msg void OnClose(); //关闭窗口

private:
	std::list<CStatic*> list; // 顶部文本控件
	std::list<CStatic *> content_list; // 内容文本控件
	std::list<std::string *> str_list; // 字符串
	CButton m_button; // 监控按钮
	CButton aofdup_data; // 管理重复数据
	CButton json_error_but; // json error button

	MfcMulti *mm = nullptr; // 线程
	MyDialog *mDialog = nullptr; // 对话框

private:
	void init_crect(CRect & ct); // 初始化
	void add_crect_hori(CRect & ct, int & x); //横轴增长
	void add_crect_vertical(CRect &ct, int & y); //纵轴增长
	

private:
		DECLARE_MESSAGE_MAP()
};  



#endif
