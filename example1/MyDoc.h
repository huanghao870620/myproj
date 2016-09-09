///////////////////////////////////////////////////////////
//  MyDoc.h
//  Implementation of the Class MyDoc
//  Created on:      09-¾ÅÔÂ-2016 14:04:07
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_CDC63B32_9CB0_4c4c_A8CA_679E1FE12E92__INCLUDED_)
#define EA_CDC63B32_9CB0_4c4c_A8CA_679E1FE12E92__INCLUDED_
#include<afxwin.h>
class MyDoc : public CDocument
{
	DECLARE_DYNCREATE(MyDoc)
public:
	MyDoc();
	virtual ~MyDoc();
	DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_CDC63B32_9CB0_4c4c_A8CA_679E1FE12E92__INCLUDED_)
