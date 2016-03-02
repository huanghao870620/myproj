#include "LogOperator.h"
#include "LogDialog.h"



BEGIN_MESSAGE_MAP(LogDialog, CDialog)
	/*ON_BN_CLICKED(IDB_BUT_CLEAR, OnClear)
	ON_BN_CLICKED(IDB_BUT_FLUSH, OnFlush)*/
	/*ON_COMMAND(2, OnAbout)
	ON_BN_CLICKED(IDC_MANADUPDATA, OnClickedDupData)
	ON_WM_PAINT()
	ON_WM_CLOSE(OnClose)*/
END_MESSAGE_MAP()

LogDialog::LogDialog()
{
}


LogDialog::~LogDialog()
{
}


BOOL LogDialog::OnInitDialog(){
	this->MessageBox(_T("abc"));
	this->logOperator->select();
	std::list<rr_report_dialy_log * > *log_list = this->logOperator->get_fields();
	std::list<rr_report_dialy_log *>::iterator iter = log_list->begin();
	while (iter != log_list->end())
	{
		rr_report_dialy_log * log = *iter;

	}


	this->listCtrl.Create(WS_BORDER | WS_VISIBLE | WS_CHILD | LVS_REPORT, CRect(10, 10, 1040, 280), this, 2);


	this->listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	this->listCtrl.SetBkColor(RGB(247, 247, 255));
	this->listCtrl.SetTextBkColor(RGB(247, 247, 255));

	this->listCtrl.InsertColumn(0, _T("id"), 0, 50);
	this->listCtrl.InsertColumn(1, _T("tick"), 0, 50);
	this->listCtrl.InsertColumn(2, _T("name"), 0, 50);
	this->listCtrl.InsertColumn(3, _T("dateft"), 0, 50);
	this->listCtrl.InsertColumn(4, _T("orgid"), 0, 50);
	return FALSE;
}