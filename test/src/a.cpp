#include <iostream>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>
//#include "CDBOperation.h"
//#include "MyTest.h"
//#include "ReceiverTest.h"
//#include "Client2Test.h"
//#include<Windows.h>
//#include"UploadFile.h"
#include"generate_random.h"



void testUpload(){
	//UploadFile *uf = new UploadFile;
	//delete uf;
}

void test0(){
	generate_random *gr = new generate_random;
	gr->t();
}

boost::unit_test::test_suite* init_unit_test_suite(int, char*[]){
	int params[] = { 1, 2, 3, 4, 5 };
	std::cout << "111111" << std::endl;
	//boost::unit_test::framework::master_test_suite().add(BOOST_TEST_CASE(&testDelete));
	boost::unit_test::framework::master_test_suite().add(BOOST_TEST_CASE(&test0));
	//boost::unit_test::framework::master_test_suite().add(BOOST_TEST_CASE(&testReceiver));
	//boost::unit_test::framework::master_test_suite().add(BOOST_TEST_CASE(&testClient2));
	//boost::unit_test::framework::master_test_suite().add(BOOST_PARAM_TEST_CASE(&test4, params, params + 5));
	return 0;
}

/*
BOOST_AUTO_TEST_SUITE(d)
BOOST_AUTO_TEST_CASE(test0){
	CDBOperation dbOper;
	bool bConn = dbOper.ConnToDB("Provider=OraOLEDB.Oracle;Persist Security Info=True;Data Source=192.168.10.208:1521/orcl", "junchuan", "junchuan");
	if (false == bConn){
		std::cout << "connection error!" << std::endl;
		return;
	}

	_RecordsetPtr pRst;
	char sql[255] = { 0 };
	strcpy_s(sql, "select * from menu where 1=1");
	pRst = dbOper.ExecuteWithResSQL(sql);
	if (NULL == pRst){
		std::cout << "data query error!" << std::endl;
		return;
	}

	if (pRst->adoEOF){
		pRst->Close();
		return;
	}

	_variant_t id, parentId,menuName,url;
	while (!pRst->adoEOF)
	{
		id = pRst->GetCollect(_variant_t("id"));
		parentId = pRst->GetCollect(_variant_t("parent_id"));
		menuName = pRst->GetCollect(_variant_t("menu_name"));
		url = pRst->GetCollect(_variant_t("url"));
		std::cout << (_bstr_t)id << "\t" << (_bstr_t)parentId << "\t" << (_bstr_t)menuName << "\t" << (_bstr_t)url << std::endl;
		pRst->MoveNext();
	}

	std::cout << "" << std::endl;
}

BOOST_AUTO_TEST_CASE(test1){

}


BOOST_AUTO_TEST_SUITE_END()
*/
