///////////////////////////////////////////////////////////
//  MyDoc.h
//  Implementation of the Class MyDoc
//  Created on:      16-Ê®ÔÂ-2016 22:43:39
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_1A587402_9222_424f_B2A1_44A8B7173A8B__INCLUDED_)
#define EA_1A587402_9222_424f_B2A1_44A8B7173A8B__INCLUDED_
#include<afxwin.h>
class MyDoc : public CDocument
{

public:
	MyDoc();
	virtual ~MyDoc();
protected:DECLARE_MESSAGE_MAP();
protected:DECLARE_DYNCREATE(MyDoc,CDocument);
};
#endif // !defined(EA_1A587402_9222_424f_B2A1_44A8B7173A8B__INCLUDED_)
