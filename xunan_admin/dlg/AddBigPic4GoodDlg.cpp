// D:\cppwork\myproj\xunan_admin\dlg\AddBigPic4GoodDlg.cpp : 实现文件
//

#include "../stdafx.h"
#include "AddBigPic4GoodDlg.h"
#include "afxdialogex.h"


// AddBigPic4GoodDlg 对话框

IMPLEMENT_DYNAMIC(AddBigPic4GoodDlg, BaseBigPic4GoodDlg)

AddBigPic4GoodDlg::AddBigPic4GoodDlg(
 long goodId,
CWnd* pParent /*=NULL*/)
: BaseBigPic4GoodDlg(AddBigPic4GoodDlg::IDD, pParent)
{
	this->goodId = goodId;
	this->gfs= good_file_service::get_good_file_service();
	this->us = upload_service::get_upload_service();
}

AddBigPic4GoodDlg::~AddBigPic4GoodDlg()
{
}

void AddBigPic4GoodDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_BIGPIC, this->img);
}

BOOL AddBigPic4GoodDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	return TRUE;
}

/*选择文件*/
//void AddBigPic4GoodDlg::selFile(){
//	this->img.GetClientRect(&this->rect);
//	this->filePath = Util::GetFilePathName();
//	ShowJpg::ShowJpgGif(this->img.GetDC(), this->filePath, rect.left, rect.top);
//}

/*添加图片*/
void AddBigPic4GoodDlg::addBigPic(){
	std::string path = this->filePath.GetBuffer(0);
	this->gfs->add_good_file(path, GOOD_BIG_PHOTO, this->goodId, us);
}


BEGIN_MESSAGE_MAP(AddBigPic4GoodDlg, BaseBigPic4GoodDlg)
	ON_BN_CLICKED(IDC_BUTTON_SEL_BIGPIC, selFile)
	ON_BN_CLICKED(IDOK, addBigPic)
END_MESSAGE_MAP()


// AddBigPic4GoodDlg 消息处理程序
