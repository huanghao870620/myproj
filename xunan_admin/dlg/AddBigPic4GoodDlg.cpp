// D:\cppwork\myproj\xunan_admin\dlg\AddBigPic4GoodDlg.cpp : ʵ���ļ�
//

#include "../stdafx.h"
#include "AddBigPic4GoodDlg.h"
#include "afxdialogex.h"


// AddBigPic4GoodDlg �Ի���

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

/*ѡ���ļ�*/
//void AddBigPic4GoodDlg::selFile(){
//	this->img.GetClientRect(&this->rect);
//	this->filePath = Util::GetFilePathName();
//	ShowJpg::ShowJpgGif(this->img.GetDC(), this->filePath, rect.left, rect.top);
//}

/*���ͼƬ*/
void AddBigPic4GoodDlg::addBigPic(){
	std::string path = this->filePath.GetBuffer(0);
	this->gfs->add_good_file(path, GOOD_BIG_PHOTO, this->goodId, us);
}


BEGIN_MESSAGE_MAP(AddBigPic4GoodDlg, BaseBigPic4GoodDlg)
	ON_BN_CLICKED(IDC_BUTTON_SEL_BIGPIC, selFile)
	ON_BN_CLICKED(IDOK, addBigPic)
END_MESSAGE_MAP()


// AddBigPic4GoodDlg ��Ϣ�������
