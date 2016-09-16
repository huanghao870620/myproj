///////////////////////////////////////////////////////////
//  MyDoc.h
//  Implementation of the Class MyDoc
//  Created on:      16-¾ÅÔÂ-2016 15:39:00
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_F9E9D898_7146_4214_9EB3_70F2564830FB__INCLUDED_)
#define EA_F9E9D898_7146_4214_9EB3_70F2564830FB__INCLUDED_
#include<afxwin.h>
class MyDoc : public CDocument
{

public:
	MyDoc();
	virtual ~MyDoc();
protected:DECLARE_DYNCREATE(MyDoc,CDocument)
protected:DECLARE_MESSAGE_MAP(MyDoc,CDocument)
};
#endif // !defined(EA_F9E9D898_7146_4214_9EB3_70F2564830FB__INCLUDED_)
