// AddVenue.cpp : 实现文件
//

#include "../stdafx.h"
#include "AddVenue.h"
#include "afxdialogex.h"


// AddVenue 对话框

IMPLEMENT_DYNAMIC(AddVenue, CDialogEx)

AddVenue::AddVenue(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddVenue::IDD, pParent)
{
	this->vs = venue_service::get_venue_service();
	this->us = upload_service::get_upload_service();
}

AddVenue::~AddVenue()
{
}

void AddVenue::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_VENUE_NAME, this->nameEdit);/*会场名称*/
	DDX_Control(pDX, IDC_STATIC_VENUE_ADV_PIC, this->imgCtrl);/*会场广告图*/
}

/*添加会场*/
void AddVenue::addVenue(){
	CString nameStr;
	this->nameEdit.GetWindowTextA(nameStr);
	std::string name = nameStr.GetBuffer(0);
	std::string adv_pic_path = this->localFilePath.GetBuffer(0);
	this->vs->add_venue(name, adv_pic_path, this->us);
}

BOOL AddVenue::OnInitDialog(){
	CDialogEx::OnInitDialog();
	return TRUE;
}

void AddVenue::uploadImg(){
	 this->localFilePath = Util::GetFilePathName();
	 RECT imgRect;
	 this->imgCtrl.GetClientRect(&imgRect);
	 ShowJpg::ShowJpgGif(this->imgCtrl.GetDC(),this->localFilePath, imgRect.left, imgRect.top);
}

BEGIN_MESSAGE_MAP(AddVenue, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEL_VNEUE, uploadImg)
	ON_BN_CLICKED(IDOK, addVenue)
END_MESSAGE_MAP()


// AddVenue 消息处理程序
