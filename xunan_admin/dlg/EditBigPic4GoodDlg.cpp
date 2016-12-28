// D:\cppwork\myproj\xunan_admin\dlg\EditBigPic4GoodDlg.cpp : 实现文件
//

#include "../stdafx.h"
#include "EditBigPic4GoodDlg.h"
#include "afxdialogex.h"


// EditBigPic4GoodDlg 对话框

IMPLEMENT_DYNAMIC(EditBigPic4GoodDlg, BaseBigPic4GoodDlg)

EditBigPic4GoodDlg::EditBigPic4GoodDlg(long picId, CWnd* pParent /*=NULL*/)
: BaseBigPic4GoodDlg(EditBigPic4GoodDlg::IDD, pParent)
{
	this->picId = picId;
	fs=file_service::get_file_service();
}

EditBigPic4GoodDlg::~EditBigPic4GoodDlg()
{
}

BOOL EditBigPic4GoodDlg::OnInitDialog(){
	BaseBigPic4GoodDlg::OnInitDialog();
	this->SetWindowTextA("编辑商品大图");

	file &f=fs->findById(this->picId);
	std::string path = f.get_uri_path();
	//std::string path=
	this->fs->downloadFtpFile(path);
	path = Config::getConfig()->get_local_path() + path;

	this->img.GetClientRect(&this->rect);
	this->filePath = path.c_str();
	ShowJpg::ShowJpgGif(this->img.GetDC(), path.c_str(), rect.left, rect.top);

	//Config::getConfig()->get_local_path();
	//std::string lpPath = std::string(Config::getConfig()->get_local_path()).append(f.get_uri_path());
	/*RECT cutRect;
	cutCsList[i]->GetClientRect(&cutRect);
	ShowJpg::ShowJpgGif(this->img.GetDC(), lpPath.c_str(), cutRect.left, cutRect.top);*/

	return TRUE;
}

void EditBigPic4GoodDlg::OnPaint(){
	BaseBigPic4GoodDlg::OnPaint();
	std::cout << "" << std::endl;
	this->img.GetClientRect(&this->rect);
	ShowJpg::ShowJpgGif(this->img.GetDC(), this->filePath, rect.left, rect.top);
}

void EditBigPic4GoodDlg::DoDataExchange(CDataExchange* pDX)
{
	BaseBigPic4GoodDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_BIGPIC, this->img);
}


void  EditBigPic4GoodDlg::editBigPic(){
	std::string path = this->filePath.GetBuffer(0);
	this->gfs->update_good_file(path, GOOD_BIG_PHOTO, this->goodId, this->picId, us);
}

BEGIN_MESSAGE_MAP(EditBigPic4GoodDlg, BaseBigPic4GoodDlg)
	ON_BN_CLICKED(IDOK, editBigPic)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// EditBigPic4GoodDlg 消息处理程序
