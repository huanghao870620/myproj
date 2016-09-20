///////////////////////////////////////////////////////////
//  MyDoc.h
//  Implementation of the Class MyDoc
//  Created on:      19-¾ÅÔÂ-2016 16:07:20
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_EBD3B551_9803_4c02_B823_4A34DDC937FA__INCLUDED_)
#define EA_EBD3B551_9803_4c02_B823_4A34DDC937FA__INCLUDED_
#include<afxwin.h>
class MyDoc : public CDocument
{

public:
	MyDoc();
	virtual ~MyDoc();
protected:DECLARE_DYNCREATE(MyDoc, CDocument);
protected:DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_EBD3B551_9803_4c02_B823_4A34DDC937FA__INCLUDED_)
