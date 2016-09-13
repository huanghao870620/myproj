///////////////////////////////////////////////////////////
//  MyDoc.h
//  Implementation of the Class MyDoc
//  Created on:      12-¾ÅÔÂ-2016 17:46:05
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_DD9BA8D3_7275_4409_85D1_711DC239C7B9__INCLUDED_)
#define EA_DD9BA8D3_7275_4409_85D1_711DC239C7B9__INCLUDED_
#include<afxwin.h>
class MyDoc : public CDocument
{
	DECLARE_DYNCREATE(MyDoc,CDocument)
public:
	MyDoc();
	virtual ~MyDoc();

	DECLARE_MESSAGE_MAP()
};
#endif // !defined(EA_DD9BA8D3_7275_4409_85D1_711DC239C7B9__INCLUDED_)
