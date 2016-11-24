///////////////////////////////////////////////////////////
//  MyDoc.cpp
//  Implementation of the Class MyDoc
//  Created on:      22-九月-2016 10:52:56
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#include "MyDoc.h"
#pragma execution_character_set("utf-8")
IMPLEMENT_DYNCREATE(MyDoc,CDocument)
BEGIN_MESSAGE_MAP(MyDoc,CDocument)
	ON_BN_CLICKED(IDOK,f0)
END_MESSAGE_MAP()
MyDoc::MyDoc(){
	std::cout << "文档构造" << std::endl;
	//this->db = *db_util::get_db();
	this->db = db_util::get_db_util()->get_db();
}

void MyDoc::f0(){
}


MyDoc::~MyDoc(){
	std::cout << "" << std::endl;
}


/**/
void MyDoc::addGood(goods&good){
	try{
	{
	odb::core::transaction t(db->begin());
	db->persist(good);
	t.commit();
	}
	}
	catch (const odb::exception&e){
		std::cerr << e.what() << std::endl;
	}

}


/**/
void MyDoc::query(){
	odb::core::transaction t(db->begin());
	odb::result<goods> r(db->query<goods>(odb::query<goods>::id>1));
	for (odb::result<goods>::iterator i(r.begin()); i != r.end(); ++i){
		std::cout << i->get_info() << std::endl;
	}
	t.commit();
}

/**/
void MyDoc::query_classification(std::list<classification*>*class_list){
	 odb::core::transaction t(db->begin());
	 odb::result<classification> r(db->query<classification>(odb::query<classification>::pid==-1));
	 for (odb::result<classification>::iterator i(r.begin()); i != r.end(); ++i){
		 classification *cla = new classification;
		 cla->set_id(i->get_id());
		 cla->set_name(i->get_name());
		 cla->set_pid(i->get_pid());
		 class_list->push_back(cla);
	 }
	 t.commit();
}

/**/
void MyDoc::query_class_bypid(std::list<classification*>*child_class,DWORD_PTR pid){
	odb::core::transaction t(db->begin());
	odb::result<classification> r(db->query<classification>(odb::query<classification>::pid == pid));
	for (odb::result<classification>::iterator i(r.begin()); i != r.end(); ++i){
		classification *cla = new classification;
		cla->set_id(i->get_id());
		cla->set_name(i->get_name());
		cla->set_pid(i->get_pid());
		child_class->push_back(cla);
	}
	t.commit();
}