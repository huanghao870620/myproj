///////////////////////////////////////////////////////////
//  MyDocument.h
//  Implementation of the Class MyDocument
//  Created on:      12-ÆßÔÂ-2016 10:22:38
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_63C861EC_1575_4b0c_A1B6_165863ED73A5__INCLUDED_)
#define EA_63C861EC_1575_4b0c_A1B6_165863ED73A5__INCLUDED_
#include<iostream>
//#include<afxwin.h>
#include "Client2.h"
/**
 * ÎÄµµ
 */
class MyDocument : public CDocument
{
	//DECLARE_DYNAMIC(MyDocument)
	DECLARE_DYNCREATE(MyDocument)
public:
	MyDocument();
	virtual ~MyDocument();

	void sendMsg(char * msg);

private:
	Client2 * c2;

	DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_63C861EC_1575_4b0c_A1B6_165863ED73A5__INCLUDED_)
