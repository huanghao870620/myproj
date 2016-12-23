#pragma once

#include"../resource.h"
#include"../ctrl/CountryListCtrl.h"
#include"../util/charset_util.h"
#include"../service/country_service.h"
#include"../entity/country.h"
#include"../util/Util.h"
#include<gdiplus.h>

// CountryShow 对话框

class CountryShow : public CDialogEx
{
	DECLARE_DYNAMIC(CountryShow)

public:
	CountryShow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CountryShow();

// 对话框数据
	enum { IDD = IDD_DIALOG_COUNTRY_LIST };
private:CountryListCtrl clistCtrl;
private:country_service*cs;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
protected:virtual BOOL OnInitDialog(); //
		  bool CompressImagePixel(
			  const WCHAR* pszOriFilePath,
			  const WCHAR* pszDestFilePah,
			  UINT ulNewHeigth,
			  UINT ulNewWidth);

		  bool GetEncoderClsid(const WCHAR* pszFormat, CLSID* pClsid);

		  CBitmap Bitmap[4];
		  CImageList m_Imagelist;
		  WCHAR m_char16ImgName[MAX_PATH];
		  CBitmap * pBmp = NULL;
		  CBitmap bmp;
		  HBITMAP  bitmap;
		  int m_nX;
		  int m_nY;
		  int m_nNum;
		  int AddImage(CString imgPath);
		  BOOL LoadBitmapToList(CString strFileName);
		  void t();
	DECLARE_MESSAGE_MAP()
};
