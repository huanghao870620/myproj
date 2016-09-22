///////////////////////////////////////////////////////////
//  MyDoc.h
//  Implementation of the Class MyDoc
//  Created on:      22-¾ÅÔÂ-2016 10:52:56
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_0FD0FB7A_23CC_4e77_B1C3_9E588D3137C5__INCLUDED_)
#define EA_0FD0FB7A_23CC_4e77_B1C3_9E588D3137C5__INCLUDED_
#include<afxwin.h>
class MyDoc : public CDocument
{

public:
	MyDoc();
	virtual ~MyDoc();
protected:DECLARE_DYNCREATE(MyDoc,CDocument)
protected:DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_0FD0FB7A_23CC_4e77_B1C3_9E588D3137C5__INCLUDED_)
