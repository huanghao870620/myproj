///////////////////////////////////////////////////////////
//  BaseBigPic4GoodDlg.cpp
//  Implementation of the Class BaseBigPic4GoodDlg
//  Created on:      27-十二月-2016 13:10:14
//  Original author: admin
///////////////////////////////////////////////////////////

#include "BaseBigPic4GoodDlg.h"

#include "../stdafx.h"
#include "AddBigPic4GoodDlg.h"

IMPLEMENT_DYNAMIC(BaseBigPic4GoodDlg, CDialogEx)

BaseBigPic4GoodDlg::BaseBigPic4GoodDlg(
long goodId,
CWnd* pParent /*=NULL*/)
: CDialogEx(BaseBigPic4GoodDlg::IDD, pParent)
{
	this->goodId = goodId;
	this->gfs = good_file_service::get_good_file_service();
	this->us = upload_service::get_upload_service();
}

BaseBigPic4GoodDlg::~BaseBigPic4GoodDlg()
{
}

void BaseBigPic4GoodDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_BIGPIC, this->img);
}

BOOL BaseBigPic4GoodDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();
	return TRUE;
}

/*选择文件*/
void BaseBigPic4GoodDlg::selFile(){
	this->img.GetClientRect(&this->rect);
	this->filePath = Util::GetFilePathName();
	ShowJpg::ShowJpgGif(this->img.GetDC(), this->filePath, rect.left, rect.top);
}

/*添加图片*/
void BaseBigPic4GoodDlg::addBigPic(){
	std::string path = this->filePath.GetBuffer(0);
	this->gfs->add_good_file(path, GOOD_BIG_PHOTO, this->goodId, us);
}

void BaseBigPic4GoodDlg::OnPaint(){
	CDialogEx::OnPaint();
}


BEGIN_MESSAGE_MAP(BaseBigPic4GoodDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEL_BIGPIC, selFile)
	ON_BN_CLICKED(IDOK, addBigPic)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// AddBigPic4GoodDlg 消息处理程序
