// TestDlg.cpp : 实现文件
//

#include "../stdafx.h"
#include "TestDlg.h"
#include "afxdialogex.h"


// TestDlg 对话框

IMPLEMENT_DYNAMIC(TestDlg, CDialogEx)

TestDlg::TestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(TestDlg::IDD, pParent)
{

}

TestDlg::~TestDlg()
{
}

void TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}



//************************************  
// 方法说明:    浏览图片  
// 返回值:      void  
//************************************  
void TestDlg::OnBnClickedBtnBrowse()
{
	// TODO: Add your control notification handler code here  
	CFileDialog dlg(TRUE, "png", "*.png", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"*.png", NULL);
	if (dlg.DoModal() == IDOK)
	{
		//SetDlgItemText(IDC_TXT_PATH, dlg.GetPathName());

		////设置静态控件的样式，使其可以使用位图，并使位图显示居中  
		//((CStatic*)GetDlgItem(IDC_STATIC_IMG))->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);

		//CDC *pDC = NULL;
		//pDC = GetDlgItem(IDC_STATIC_IMG)->GetDC();
		////ShowJpgGif(pDC,dlg.GetPathName(),0,0);  
		//ShowJpg::ShowImage(pDC, dlg.GetPathName(), 0, 0);

		//this->ReleaseDC(pDC);


		/*ImageAttributes imAtt;
		imAtt.SetColorKey(Color(0, 0, 0), Color(10, 10, 10), ColorAdjustTypeDefault);
		graphics.SetSmoothingMode(SmoothingModeAntiAlias);
		Image imageBlue(TEXT(".\\res\\NumbersBlue.png"));
		graphics.DrawImage(&imageYear, Rect(cx, 0, iYearWidth, iYearHeight), 0, iYearHeight, iYearWidth, iYearHeight, UnitPixel, &imAtt);*/
	}

}



BEGIN_MESSAGE_MAP(TestDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedBtnBrowse)
END_MESSAGE_MAP()


// TestDlg 消息处理程序
