///////////////////////////////////////////////////////////
//  MyDoc.h
//  Implementation of the Class MyDoc
//  Created on:      22-九月-2016 10:52:56
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_0FD0FB7A_23CC_4e77_B1C3_9E588D3137C5__INCLUDED_)
#define EA_0FD0FB7A_23CC_4e77_B1C3_9E588D3137C5__INCLUDED_
#include<afxwin.h>
#include"../resource.h"
#include<iostream>
#include<list>
#include<memory>
#include<odb\database.hxx>
#include<odb\mysql\database.hxx>
#include<odb\core.hxx>
#include"../entity/goods.h"
#include"../odb/goods-odb.hxx"
#include"../entity/classification.h"
#include"../odb/classification-odb.hxx"
#include"../util/db_util.h"

#pragma execution_character_set("utf-8")
class MyDoc : public CDocument
{

public:
	MyDoc();
	virtual ~MyDoc();
protected:DECLARE_DYNCREATE(MyDoc, CDocument)
protected:DECLARE_MESSAGE_MAP()
protected:afx_msg void f0();
//public:void addGood(goods&good);
public:void query();
public:void query_classification(std::list<classification*>*class_list);/*获取一级分类*/
//public:void query_class_bypid(std::list<classification*>*child_class,DWORD_PTR pid);/*根据父节点获取子分类*/
private:std::auto_ptr<odb::database> db;
};
#endif // !defined(EA_0FD0FB7A_23CC_4e77_B1C3_9E588D3137C5__INCLUDED_)
