///////////////////////////////////////////////////////////
//  MyDoc.h
//  Implementation of the Class MyDoc
//  Created on:      15-����-2016 15:16:00
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_814AB1F4_82C2_4e3d_82B9_A65609CA142A__INCLUDED_)
#define EA_814AB1F4_82C2_4e3d_82B9_A65609CA142A__INCLUDED_
#include<afxwin.h>
class MyDoc : public CDocument
{
protected:DECLARE_DYNCREATE(MyDoc,CDocument)
protected:DECLARE_MESSAGE_MAP(MyDoc,CDocument)
public:
	MyDoc();
	virtual ~MyDoc();

};
#endif // !defined(EA_814AB1F4_82C2_4e3d_82B9_A65609CA142A__INCLUDED_)
