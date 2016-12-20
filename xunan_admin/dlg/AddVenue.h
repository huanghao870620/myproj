#pragma once
#include"../resource.h"
#include"../util/Util.h"
#include"../service/venue_service.h"
#include"../service/upload_service.h"
#include"../util/ShowJpg.h"

// AddVenue �Ի���

class AddVenue : public CDialogEx
{
	DECLARE_DYNAMIC(AddVenue)
public:
	AddVenue(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddVenue();

private:CString localFilePath;
// �Ի�������
	enum { IDD = IDD_DIALOG_VNEUE };
protected:afx_msg void uploadImg();
protected:afx_msg void addVenue();
protected:virtual BOOL OnInitDialog();
private:venue_service*vs;
private:upload_service*us;

private:CEdit nameEdit;
private:CStatic imgCtrl;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};