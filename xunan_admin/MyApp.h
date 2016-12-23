///////////////////////////////////////////////////////////
//  MyApp.h
//  Implementation of the Class MyApp
//  Created on:      22-¾ÅÔÂ-2016 10:52:55
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_F9C0FC87_150C_45f1_8A53_42921EA228E0__INCLUDED_)
#define EA_F9C0FC87_150C_45f1_8A53_42921EA228E0__INCLUDED_
#include"resource.h"
#include"dlg\MyDoc.h"
#include"dlg\MyFrame.h"
#include"dlg\MyView.h"
#include"dlg\AddGoodsDlg.h"
#include<afxwin.h>
#include<iostream>
#include<afxmt.h>

#include<memory>
#include<odb\database.hxx>
#include<odb\mysql\database.hxx>
#include<odb\core.hxx>
#include"entity\good_file.h"

class MyApp : public CWinApp
{

public:
	MyApp();
	virtual ~MyApp();
public:virtual BOOL InitInstance();
};
#endif // !defined(EA_F9C0FC87_150C_45f1_8A53_42921EA228E0__INCLUDED_)
