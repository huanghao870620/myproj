///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      16-¾ÅÔÂ-2016 10:53:27
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_E633DE67_9DB0_404e_9FE2_0ED4D9249371__INCLUDED_)
#define EA_E633DE67_9DB0_404e_9FE2_0ED4D9249371__INCLUDED_
#include<iostream>
#include<afxwin.h>
class MyApp : public CWinApp
{

public:
	MyApp();
	virtual ~MyApp();
public:virtual BOOL InitInstance();
//private:CButton m_wndPushButton;
//protected:DECLARE_MESSAGE_MAP(MyApp,CWinApp)
};
#endif // !defined(EA_E633DE67_9DB0_404e_9FE2_0ED4D9249371__INCLUDED_)
