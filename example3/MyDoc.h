///////////////////////////////////////////////////////////
//  MyDoc.h
//  Implementation of the Class MyDoc
//  Created on:      14-¾ÅÔÂ-2016 14:15:26
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_89058C0A_1ABC_484e_B8D6_C2A42E5790C0__INCLUDED_)
#define EA_89058C0A_1ABC_484e_B8D6_C2A42E5790C0__INCLUDED_
#include<afxwin.h>
class MyDoc : public CDocument
{
protected: DECLARE_DYNCREATE(MyDoc,CDocument)
protected:DECLARE_MESSAGE_MAP()
public:
	MyDoc();
	virtual ~MyDoc();

};
#endif // !defined(EA_89058C0A_1ABC_484e_B8D6_C2A42E5790C0__INCLUDED_)
