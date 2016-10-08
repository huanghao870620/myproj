///////////////////////////////////////////////////////////
//  MyDoc.h
//  Implementation of the Class MyDoc
//  Created on:      07-Ê®ÔÂ-2016 17:15:54
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_240C78B9_A7BF_46e8_A900_909DC5DFAA35__INCLUDED_)
#define EA_240C78B9_A7BF_46e8_A900_909DC5DFAA35__INCLUDED_
#include<afxwin.h>
class MyDoc : public CDocument 
{

public:
	MyDoc();
	virtual ~MyDoc();
protected:DECLARE_DYNCREATE(MyDoc, CDocument);
protected:DECLARE_MESSAGE_MAP(MyDoc,CDocument)

};
#endif // !defined(EA_240C78B9_A7BF_46e8_A900_909DC5DFAA35__INCLUDED_)
