///////////////////////////////////////////////////////////
//  ChatDialog.h
//  Implementation of the Class ChatDialog
//  Created on:      30-ÁùÔÂ-2016 15:02:19
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_5B3D004C_A895_4c13_82B9_E5423BA9750A__INCLUDED_)
#define EA_5B3D004C_A895_4c13_82B9_E5423BA9750A__INCLUDED_
//#include <afxwin.h>
#include "Client2.h"
class ChatDialog : public CDialog
{

public:
	ChatDialog(Client2 * c2);
	ChatDialog();
	virtual BOOL OnInitDialog();
	virtual ~ChatDialog();
	afx_msg void OnChat();
	void addComp();

private:
	CEdit edit;
	CButton but;
	CStatic cs;
	Client2 * c2;

private:
	DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_5B3D004C_A895_4c13_82B9_E5423BA9750A__INCLUDED_)
