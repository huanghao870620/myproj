// WatchClassDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "WatchClassDlg.h"
#include "afxdialogex.h"


// WatchClassDlg 对话框

IMPLEMENT_DYNAMIC(WatchClassDlg, CDialogEx)

WatchClassDlg::WatchClassDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(WatchClassDlg::IDD, pParent)
{
}

WatchClassDlg::~WatchClassDlg()
{
}

void WatchClassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, this->m_webTree);
}

BOOL WatchClassDlg::OnInitDialog(){
	CDialogEx::OnInitDialog();

	HICON hIcon[3];
	HTREEITEM hRoot;
	HTREEITEM hCataItem;
	HTREEITEM hArtItem;

	hIcon[0] = AfxGetApp()->LoadIconA(IDI_ICON1);
	hIcon[1] = AfxGetApp()->LoadIconA(IDI_ICON2);
	hIcon[2] = AfxGetApp()->LoadIconA(IDI_ICON3);

	this->m_imageList.Create(32, 32, ILC_COLOR32, 3, 3);
	for (int i = 0; i < 3; i++)
	{
		this->m_imageList.Add(hIcon[i]);
	}
	this->m_webTree.SetImageList(&m_imageList, TVSIL_NORMAL);

	hRoot = this->m_webTree.InsertItem("鸡啄米", 0, 0);
	hCataItem = this->m_webTree.InsertItem("IT互联网", 1, 1, hRoot, TVI_LAST);
	this->m_webTree.SetItemData(hCataItem, 1);
	hArtItem = this->m_webTree.InsertItem("百度文章1", 2, 2, hCataItem, TVI_LAST);
	this->m_webTree.SetItemData(hArtItem, 2);
	hArtItem = this->m_webTree.InsertItem("谷歌文章2", 2, 2, hCataItem, TVI_LAST);
	this->m_webTree.SetItemData(hArtItem, 3);
	/*hCataItem = m_webTree.InsertItem("数码生活", 1, 1, hRoot, TVI_LAST);
	this->m_webTree.SetItemData(hCataItem, 4);
	hArtItem = this->m_webTree.InsertItem("智能手机文章1", 2, 2, hCataItem, TVI_LAST);
	this->m_webTree.SetItemData(hArtItem, 5);*/
	/*hCataItem = this->m_webTree.InsertItem("软件开发", 1, 1, hRoot, TVI_LAST);
	this->m_webTree.SetItemData()*/
	/*hArtItem = this->m_webTree.InsertItem("平板电脑文章2", 2, 2, hCataItem, TVI_LAST);
	this->m_webTree.SetItemData(hArtItem, 6);

	hCataItem = this->m_webTree.InsertItem("软件开发", 1, 1, hRoot, TVI_LAST);
	this->m_webTree.SetItemData(hCataItem, 7);

	hArtItem = this->m_webTree.InsertItem("c++编程入门1", 2, 2, hCataItem, TVI_LAST);
	this->m_webTree.SetItemData(hArtItem, 8);

	hArtItem = this->m_webTree.InsertItem("VS2010/MFC编程入门2", 2, 2, hCataItem, TVI_LAST);
	this->m_webTree.SetItemData(hArtItem, 9);

	hCataItem = this->m_webTree.InsertItem("娱乐休闲", 1, 1, hRoot, TVI_LAST);
	this->m_webTree.SetItemData(hCataItem, 10);

	hArtItem = this->m_webTree.InsertItem("玛雅文明文章1", 2, 2, hCataItem, TVI_LAST);
	this->m_webTree.SetItemData(hArtItem, 11);

	hArtItem = this->m_webTree.InsertItem("IT笑话2", 2, 2, hCataItem, TVI_LAST);
	this->m_webTree.SetItemData(hArtItem, 12);*/
	//
	return TRUE;
}


/*NMTVGETINFOTIP *pTVTipInfo = (NMTVGETINFOTIP*)pNotifyStruct;
	HTREEITEM hRoot = this->m_webTree->GetRootItem();
	CString strText;
	if (pTVTipInfo->hItem == hRoot){
		strText = "";
	}
	else
	{
		strText.Format("%d", pTVTipInfo->lParam);
	}
	//wcscpy(pTVTipInfo->pszText, strText);
	strcpy(pTVTipInfo->pszText, strText);*/

BEGIN_MESSAGE_MAP(WatchClassDlg, CDialogEx)
	//ON_NOTIFY(TVN_SELCHANGED,IDC_TREE1,memberFxn)
END_MESSAGE_MAP()


// WatchClassDlg 消息处理程序
