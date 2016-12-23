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
	this->db = db_util::get_db_util()->get_db();
}

void MyDoc::f0(){
}


MyDoc::~MyDoc(){
	std::cout << "" << std::endl;
}


/**/



/**/
void MyDoc::query(){
	odb::core::transaction t(db->begin());
	odb::result<goods> r(db->query<goods>(odb::query<goods>::id>1));
	for (odb::result<goods>::iterator i(r.begin()); i != r.end(); ++i){
		std::cout << i->get_info() << std::endl;
	}
	t.commit();
}



