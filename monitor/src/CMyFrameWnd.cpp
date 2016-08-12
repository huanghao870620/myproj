//#include <afxwin.h>
#include <iostream>
#include "MfcMulti.h"
#include "StruInte.h"
#include "MyDialog.h"
#include "DrawFlag.h"
#include "LogDialog.h"
#include "ChatDialog.h"
#include "CMyFrameWnd.h"
#include "resource.h"


BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)	
	ON_COMMAND(2, OnAbout)
	ON_BN_CLICKED(IDC_DYNAMICBUTTON, OnClicked)
	ON_BN_CLICKED(IDC_MANADUPDATA, OnClickedDupData)
	ON_BN_CLICKED(88, OnClicked4ErrorLog)
	ON_BN_CLICKED(89,OnChat)
	ON_WM_PAINT()
	ON_WM_CLOSE(OnClose)
END_MESSAGE_MAP()

//IMPLEMENT_DYNAMIC(CMyFrameWnd,CFrameWnd)
IMPLEMENT_DYNCREATE(CMyFrameWnd,CFrameWnd)
void CMyFrameWnd::OnCreate(){
	this->MessageBox(_T("dd"));
}

CMyFrameWnd::~CMyFrameWnd()
{
	/*std::list<std::string *>::iterator iter = this->str_list.begin();
	while (iter != this->str_list.end())
	{
		std::string * s = *iter;
		delete s;
		iter++;
	}

	std::list<CStatic *>::iterator cs_iter = this->list.begin();
	while (cs_iter != this->list.end())
	{
		CStatic * cs = *cs_iter;
		delete cs;
		cs_iter++;
	}*/

}


CMyFrameWnd::CMyFrameWnd()
{
	std::cout << "cmyframewnd constructor" << std::endl;
	/*this->Create(NULL, _T("研报状态监控器"), WS_OVERLAPPEDWINDOW, this->rectDefault, NULL, NULL);
	HICON ico = AfxGetApp()->LoadIconA(IDR_DD1);
	SetIcon(ico, true);

	this->m_button.Create(_T("开始监控"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		CRect(50, 10, 130, 40),
		this,
		IDC_DYNAMICBUTTON
		);

	this->aofdup_data.Create(_T("管理重复数据"),
		WS_CHILD | WS_VISIBLE | WS_BORDER, 
		CRect(220, 10, 320, 40), this, IDC_MANADUPDATA);

	this->json_error_but.Create(_T("错误日志"), 
		WS_CHILD | WS_VISIBLE | WS_BORDER, 
		CRect(340, 10, 440, 40), this, 88);

	this->chatBut.Create(_T("聊天"), WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(460, 10, 500, 40), this, 89);

	std::string * num = new std::string("总条数");
	std::string * page_num = new std::string("页数");
	std::string * row_num = new std::string("行数");
	std::string * thread_state = new std::string("线程状态");
	std::string * type = new std::string("研报类型");
	std::string * dist_bet = new std::string("full/daily");

	this->str_list.push_back(num);
	this->str_list.push_back(page_num);
	this->str_list.push_back(row_num);
	this->str_list.push_back(thread_state);
	this->str_list.push_back(type);
	this->str_list.push_back(dist_bet);

	std::list<std::string * >::iterator iter = str_list.begin();
	CRect ct;
	this->init_crect(ct);

	int x = 120;
	int y = 0;

	while (iter != str_list.end())
	{
		std::string * ss = *iter;
		CStatic * cs = new CStatic;

		cs->Create(ss->c_str(), WS_CHILD | WS_VISIBLE | CA_CENTER, ct, this);
		this->add_crect_hori(ct, x);
		this->list.push_back(cs);
		iter++;
	}

	this->init_crect(ct);
	y = 30;
	ct.top = 100;
	ct.bottom = 120;
	for (size_t i = 0; i < 12; i++)
	{
		ct.left = 50;
		ct.right = 150;
		for (size_t j = 0; j < 6; j++){
			CStatic * cs = new CStatic;			
			char c[10];
			strcpy_s(c, "--");
			cs->Create(c, WS_CHILD | WS_VISIBLE | CA_CENTER, ct, this);
			this->add_crect_hori(ct, x);
			this->content_list.push_back(cs);
		}
		this->add_crect_vertical(ct, y);
	}*/

	
}
	

/*横轴*/
void CMyFrameWnd::add_crect_hori(CRect & ct, int & x){
	ct.left = ct.left + x;
	ct.right = ct.right + x;
}

/*纵轴*/
void CMyFrameWnd::add_crect_vertical(CRect & ct, int & y){
	ct.top = ct.top + y;
	ct.bottom = ct.bottom + y;
}

// 错误日志
void CMyFrameWnd::OnClicked4ErrorLog(){
	this->logDialog = new LogDialog;
	this->logDialog->Create(IDD_DIALOG2, this);
	this->logDialog->ShowWindow(SW_SHOWNORMAL);
}

void CMyFrameWnd::init_crect(CRect & ct){
	ct.left = 50;
	ct.right = 150;

	ct.top = 60;
	ct.bottom = 80;
}



//绘图
void CMyFrameWnd::OnPaint()
{

	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	DrawFlag * df = DrawFlag::GetInstance();
	static const MSG *msg = this->GetCurrentMessage();
	if (msg->lParam == NULL){
		return;
	}

	std::list<StruInte *> * list_stru = (std::list<StruInte *> *) msg->lParam;
	df->setFlag(true);
	if (list_stru != nullptr && list_stru->size() > 0){
		std::list<StruInte *>::iterator iter = list_stru->begin();
		std::list<CStatic * >::iterator content_iter = this->content_list.begin();
		while (iter != list_stru->end()){
			struct  StruInte *si = *iter;
			(*content_iter++)->SetWindowTextA(si->num.c_str()); // 总条数
			(*content_iter++)->SetWindowTextA(si->pageNum.c_str()); //页数
			(*content_iter++)->SetWindowTextA(si->rowNum.c_str()); //行数
			(*content_iter++)->SetWindowTextA(si->threadState.c_str()); // 线程状态
			(*content_iter++)->SetWindowTextA(si->type.c_str()); //研报类型
			(*content_iter++)->SetWindowTextA(si->distBet.c_str()); //全量/增量tt
			iter++;
		}
		df->setFlag(false);
	}

}


void CMyFrameWnd::OnAbout()
{
	CDialog about("AboutBox", this);
	about.DoModal();
}


void CMyFrameWnd::OnClicked(){
	mm = new MfcMulti();
	mm->Start();
}

void CMyFrameWnd::OnClickedDupData(){
	//MyDialog dlg(IDD_DIALOG1, this);
	//dlg.DoModal();
	this->mDialog = new MyDialog;
	this->mDialog->Create(IDD_DIALOG1, this);
	this->mDialog->ShowWindow(SW_SHOWNORMAL);
}

void CMyFrameWnd::OnClose(){
	if (this->mm != nullptr){
		Client & client = this->mm->getClientRef();
		client.Send("bye!");
		client.Close();
	}
	this->DestroyWindow();
}

/*聊天对话框*/
void CMyFrameWnd::OnChat(){
	this->chatDialog = new ChatDialog;
	this->chatDialog->Create(IDD_DIALOG3, this);
	this->chatDialog->addComp();
	this->chatDialog->ShowWindow(SW_SHOWNORMAL);
}

