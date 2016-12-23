/////////////////////////////////////////////////////////////
////  CImageListCtrl.h
////  Implementation of the Class CImageListCtrl
////  Created on:      22-十二月-2016 20:00:20
////  Original author: admin
/////////////////////////////////////////////////////////////
//
//#if !defined(EA_45D17A32_AD47_4c33_941F_507EEE5668F8__INCLUDED_)
//#define EA_45D17A32_AD47_4c33_941F_507EEE5668F8__INCLUDED_
//
//#include<afxcmn.h>
//class CImageListCtrl : public CListCtrl
//{
//	DECLARE_DYNAMIC(CImageListCtrl)
//
//public:
//	CImageListCtrl();
//	virtual ~CImageListCtrl();
//	CImageList m_ImageList;
//	WCHAR m_char16ImgName[MAX_PATH];
//
//protected:
//	DECLARE_MESSAGE_MAP()
//
//public:
//	// 添加图片
//	int AddImage(CString imgPath);
//	void DelImage(CString imgPath);
//	void RemoveAllImg(void);
//	// 获得当前显示所有图片的路径
//	void GetImgPathList(CStringList& strListPath);
//	BOOL InitCtrl(int nX, int nY);
//	void DeleteSelItem(void);
//
//private:
//	int m_nX;
//	int m_nY;
//	int m_nNum;
//
//public:
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnDestroy();
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//
//};
//#endif // !defined(EA_45D17A32_AD47_4c33_941F_507EEE5668F8__INCLUDED_)
