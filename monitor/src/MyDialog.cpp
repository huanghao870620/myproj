#include <iostream>
#include <resource.h>
#include "DataCollection.h"
#include "rr_report.h"
#include "MyDialog.h"


BEGIN_MESSAGE_MAP(MyDialog, CDialog)
	ON_BN_CLICKED(IDB_BUT_CLEAR, OnClear)
	ON_BN_CLICKED(IDB_BUT_FLUSH, OnFlush)
	/*ON_COMMAND(2, OnAbout)
	ON_BN_CLICKED(IDC_MANADUPDATA, OnClickedDupData)
	ON_WM_PAINT()
	ON_WM_CLOSE(OnClose)*/
END_MESSAGE_MAP()


MyDialog::MyDialog() 
{
	this->dc = new DataCollection;
}


MyDialog::MyDialog(int idd,CWnd *wnd) : CDialog(idd,wnd){
	this->dc = new DataCollection;
}

MyDialog::~MyDialog() 
{
	delete this->dc;
}

void MyDialog::OnClear(){
	int ret = this->MessageBox(_T("是否确认要删除?"), _T(""), MB_YESNO);
	if (ret == IDYES){
		int result = this->dc->Delete();
		if (result == 0){
			this->MessageBox(_T("删除完成!"));
		}
		else{
			this->MessageBox(_T("删除失败!"));
		}
	}
}

void MyDialog::OnFlush(){
	time_t start = clock();
	this->text.SetWindowTextA(_T("刷新中..."));
	this->ReDraw();
	time_t end = clock();

	char msg[100];
	sprintf_s(msg, "刷新完成,用时 : %.0f秒![%d]", double(end - start) / CLOCKS_PER_SEC, this->dc->get_report_list()->size());
	this->text.SetWindowTextA(msg);
}

BOOL MyDialog::OnInitDialog()
{
	
	CDialog::OnInitDialog();
	this->text.Create(_T(""), WS_CHILD | WS_VISIBLE | CA_CENTER, CRect(620,300,820,330),this, 0);
	this->cButton.Create(_T("删除"), WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(520, 300, 600, 330), this, IDB_BUT_CLEAR);
	this->flushButton.Create(_T("刷新"), WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(400, 300, 480, 330), this, IDB_BUT_FLUSH);

	this->m_UserList.Create(WS_BORDER | WS_VISIBLE | WS_CHILD | LVS_REPORT, CRect(10, 10, 1040, 280), this, 2);

	this->m_UserList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	this->m_UserList.SetBkColor(RGB(247, 247, 255));
	this->m_UserList.SetTextBkColor(RGB(247, 247, 255));

	this->m_UserList.InsertColumn(0, _T("id"), 0, 50);
	this->m_UserList.InsertColumn(1, _T("tick"), 0, 50);
	this->m_UserList.InsertColumn(2, _T("name"), 0, 50);
	this->m_UserList.InsertColumn(3, _T("dateft"), 0, 50);
	this->m_UserList.InsertColumn(4, _T("orgid"), 0, 50);
	this->m_UserList.InsertColumn(5, _T("org"), 0, 50);
	this->m_UserList.InsertColumn(6, _T("resname"), 0, 50);
	this->m_UserList.InsertColumn(7, _T("type"), 0, 50);
	this->m_UserList.InsertColumn(8, _T("title"), 0, 50);
	this->m_UserList.InsertColumn(9, _T("full_abs"), 0, 50);
	this->m_UserList.InsertColumn(10, _T("short_abs"), 0, 50);
	this->m_UserList.InsertColumn(11, _T("price"), 0, 50);
	this->m_UserList.InsertColumn(12, _T("rating"), 0, 50);
	this->m_UserList.InsertColumn(13, _T("rating_change"), 0, 50);
	this->m_UserList.InsertColumn(14, _T("pdf_url"), 0, 50);
	this->m_UserList.InsertColumn(15, _T("pdf_size"), 0, 50);
	this->m_UserList.InsertColumn(16, _T("pdf_path"), 0, 50);
	this->m_UserList.InsertColumn(17, _T("timestamp"), 0, 50);
	this->m_UserList.InsertColumn(18, _T("checkr"), 0, 50);

	this->m_UserList.SetRedraw(TRUE);
	return TRUE;
}

void MyDialog::ReDraw(){
	this->dc->colle_all();

	std::list<rr_report * > * report_list = this->dc->get_report_list();
	std::list<rr_report * >::iterator iter = report_list->begin();
	for (int i = 0; iter != report_list->end(); iter++, i++){
		rr_report * report = *iter;
		this->m_UserList.InsertItem(i, report->id.c_str());
		this->m_UserList.SetItemText(i, 1, report->tick.c_str());
		this->m_UserList.SetItemText(i, 2, report->name.c_str());
		this->m_UserList.SetItemText(i, 3, report->dateft.c_str());
		this->m_UserList.SetItemText(i, 4, report->orgid.c_str());
		this->m_UserList.SetItemText(i, 5, report->org.c_str());
		this->m_UserList.SetItemText(i, 6, report->resname.c_str());
		this->m_UserList.SetItemText(i, 7, report->type.c_str());
		this->m_UserList.SetItemText(i, 8, report->title.c_str());
		this->m_UserList.SetItemText(i, 9, report->full_abs.c_str());
		this->m_UserList.SetItemText(i, 10, report->short_abs.c_str());
		this->m_UserList.SetItemText(i, 11, report->price.c_str());
		this->m_UserList.SetItemText(i, 12, report->rating.c_str());
		this->m_UserList.SetItemText(i, 13, report->rating_change.c_str());
		this->m_UserList.SetItemText(i, 14, report->pdf_url.c_str());
		this->m_UserList.SetItemText(i, 15, report->pdf_size.c_str());
		this->m_UserList.SetItemText(i, 16, report->pdf_path.c_str());
		this->m_UserList.SetItemText(i, 17, report->timestamp.c_str());
		this->m_UserList.SetItemText(i, 18, report->checkr.c_str());
	}
}


/*
37726 需要删除的id
select id  from rr_report  where id not in (select t.id from (
select pdf_url,id from rr_report where pdf_url is not null) as t
group by t.pdf_url having count(1)=1)

and id not in (select t.id from (
select t2.pdf_url,count(1),t2.id from
(select pdf_url,id from rr_report where pdf_url is not null) as t2
group by pdf_url having count(1)>1 ) as t)

and id not in ( select id from rr_report where pdf_url is null)
*/