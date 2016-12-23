//
//#include<afxwin.h>
//#include "CxImage/ximage.h"
//#include "ImageListCtrl.h"
//
//// CImageListCtrl
//
//IMPLEMENT_DYNAMIC(CImageListCtrl, CListCtrl)
//
//CImageListCtrl::CImageListCtrl()
//{
//	m_nNum = 0;
//}
//
//CImageListCtrl::~CImageListCtrl()
//{
//	m_ImageList.DeleteImageList();
//}
//
//
//BEGIN_MESSAGE_MAP(CImageListCtrl, CListCtrl)
//	ON_WM_CREATE()
//	ON_WM_DESTROY()
//	ON_WM_KEYDOWN()
//END_MESSAGE_MAP()
//
//
//
//// CImageListCtrl 消息处理程序
//
//int CImageListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	if (CListCtrl::OnCreate(lpCreateStruct) == -1)
//		return -1;
//
//	return 0;
//}
//
//BOOL CImageListCtrl::InitCtrl(int nX, int nY)
//{
//	m_nX = nX;
//	m_nY = nY;
//	SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);//LVS_EX_CHECKBOXES
//	if (!m_ImageList.Create(nX, nY, ILC_COLOR24, 1, 1))
//	{
//		return FALSE;
//	}
//
//	DeleteAllItems();
//	m_ImageList.SetBkColor(RGB(125, 125, 0));
//	if (SetImageList(&m_ImageList, LVSIL_NORMAL) == NULL)
//	{
//		return FALSE;
//	}
//	return TRUE;
//}
//
//
///*// 添加图片
//int CImageListCtrl::AddImage(CString imgPath)
//{
//CString strEnd = imgPath.Right(3);
//strEnd.MakeLower();
//if(strEnd.Compare(_T("jpg")) == 0 || strEnd.Compare(_T("gif")) == 0
//|| strEnd.Compare(_T("bmp")) == 0 || strEnd.Compare(_T("png")) == 0
//|| strEnd.Compare(_T("tga")) == 0)
//{
//CxImage image;
////应用CXImage载入图像，本程序是相对路径
//image.Load(imgPath);
//if (image.IsValid() == false)
//{
//return 0;
//}
//
//image.Resample(m_nX, m_nY, 2);
//CDC *pDC = GetDC();//应用CXImage在内存中生产位图
//HBITMAP hBit = image.MakeBitmap(pDC->GetSafeHdc());
//CBitmap bmp;
//bmp.Attach(hBit);
//int nResult = m_ImageList.Add(&bmp, RGB(255, 255, 255));
//bmp.Detach();
//ReleaseDC(pDC);
//
//int nIndex = imgPath.ReverseFind(_T('\\'));
//CString strFileName = imgPath.Right(imgPath.GetLength() - (nIndex + 1));
//InsertItem(m_nNum, strFileName, nResult);
//SetItemData(m_nNum, (DWORD_PTR)strdup(imgPath));
//
//RedrawItems(m_nNum, m_nNum);
//m_nNum++;
//
//return 1;
//}
//
//return 0;
//}*/
//
//
//int CImageListCtrl::AddImage(CString imgPath)
//{
//	CString strEnd = imgPath.Right(3);
//	strEnd.MakeLower();
//	if (strEnd.Compare(_T("jpg")) == 0 || strEnd.Compare(_T("gif")) == 0
//		|| strEnd.Compare(_T("bmp")) == 0 || strEnd.Compare(_T("png")) == 0
//		|| strEnd.Compare(_T("tga")) == 0)
//	{
//		int nStrLen = imgPath.GetLength();
//		char* pCharBuf = imgPath.GetBuffer(0);
//		imgPath.ReleaseBuffer();
//		int nLen = MultiByteToWideChar(CP_ACP, 0, pCharBuf, nStrLen, NULL, 0);
//		MultiByteToWideChar(CP_ACP, 0, pCharBuf, nStrLen, m_char16ImgName, nLen);
//		m_char16ImgName[nLen] = '\0'; //添加字符串结尾，注意不是len+1*/
//
//		Gdiplus::Bitmap image(m_char16ImgName);
//		Gdiplus::Bitmap* pThumbnail = (Gdiplus::Bitmap*)image.GetThumbnailImage(m_nX, m_nY);
//		HBITMAP hBmp;
//		pThumbnail->GetHBITMAP(Gdiplus::Color(255, 255, 255), &hBmp);
//
//		CBitmap bmp;
//		bmp.Attach(hBmp);
//		int nResult = m_ImageList.Add(&bmp, RGB(255, 255, 255));
//		bmp.Detach();
//		int nIndex = imgPath.ReverseFind(_T('\\'));
//		CString strFileName = imgPath.Right(imgPath.GetLength() - (nIndex + 1));
//
//		InsertItem(m_nNum, strFileName, nResult);
//		SetItemData(m_nNum, (DWORD_PTR)strdup(imgPath));
//		RedrawItems(m_nNum, m_nNum);
//
//		delete pThumbnail;
//		m_nNum++;
//
//		return 1;
//	}
//
//	return 0;
//}
//
//
//void CImageListCtrl::DelImage(CString imgPath)
//{
//	int nCount = GetItemCount();
//	for (int i = 0; i<nCount; i++)
//	{
//		char *pData = (char *)GetItemData(i);
//		if (pData != NULL)
//		{
//			CString str;
//			str.Format(_T("%s"), pData);
//			str = str.Trim();
//			if (str.CompareNoCase(imgPath) == 0)
//			{
//				free(pData);
//				DeleteItem(i);
//			}
//		}
//	}
//}
//
//void CImageListCtrl::RemoveAllImg(void)
//{
//	int nCount = GetItemCount();
//	for (int i = 0; i<nCount; i++)
//	{
//		char *pData = (char *)GetItemData(i);
//		if (pData != NULL)
//			free(pData);
//	}
//	DeleteAllItems();
//	m_nNum = 0;
//}
//
//// 获得当前显示所有图片的路径
//void CImageListCtrl::GetImgPathList(CStringList& strListPath)
//{
//	int nCount = GetItemCount();
//	strListPath.RemoveAll();
//	for (int i = 0; i<nCount; i++)
//	{
//		char *pData = (char *)GetItemData(i);
//		if (pData != NULL)
//		{
//			CString str;
//			str.Format(_T("%s"), pData);
//			str = str.Trim();
//			strListPath.AddTail(str);
//		}
//	}
//}
//
//
//void CImageListCtrl::OnDestroy()
//{
//	int nCnt = GetItemCount();
//	for (int i = 0; i < nCnt; i++)
//	{
//		char *pData = (char *)GetItemData(i);
//		if (pData)
//		{
//			delete[] pData;
//		}
//	}
//
//	CListCtrl::OnDestroy();
//}
//
////删除所有选中的项
//void CImageListCtrl::DeleteSelItem(void)
//{
//	POSITION pos = GetFirstSelectedItemPosition();
//	while (pos != NULL)
//	{
//		int nItem = GetNextSelectedItem(pos);
//		TRACE1("Item %d was selected!\n", nItem);
//
//		char *pData = (char *)GetItemData(nItem);
//		if (pData != NULL)
//		{
//			free(pData);
//		}
//
//		DeleteItem(nItem);
//		pos = GetFirstSelectedItemPosition();
//	}
//
//	Arrange(LVA_ALIGNLEFT);
//}
//
//void CImageListCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	if (nChar == VK_DELETE)
//	{
//		DeleteSelItem();
//	}
//	else if ((nChar == 'a' || nChar == 'A') && GetKeyState(VK_CONTROL))
//	{
//		for (int i = 0; i < m_nNum; ++i)
//		{
//			SetItemState(i, LVIS_SELECTED, LVIS_SELECTED);
//		}
//	}
//
//	CListCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
//}