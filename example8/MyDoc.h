///////////////////////////////////////////////////////////
//  MyDoc.h
//  Implementation of the Class MyDoc
//  Created on:      17-¾ÅÔÂ-2016 19:24:53
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_0F190BC3_5E75_4939_BB87_536D66780293__INCLUDED_)
#define EA_0F190BC3_5E75_4939_BB87_536D66780293__INCLUDED_
#include<afxwin.h>
class MyDoc : public CDocument
{
protected:DECLARE_DYNCREATE(MyDoc,CDocument)
protected:DECLARE_MESSAGE_MAP()
public:
	MyDoc();
	virtual ~MyDoc();

};
#endif // !defined(EA_0F190BC3_5E75_4939_BB87_536D66780293__INCLUDED_)
