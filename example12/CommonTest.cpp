///////////////////////////////////////////////////////////
//  CommonTest.cpp
//  Implementation of the Class CommonTest
//  Created on:      21-¾ÅÔÂ-2016 9:54:46
//  Original author: huang.hao
///////////////////////////////////////////////////////////
#include "CommonTest.h"
#include <boost/test/included/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>
using boost::unit_test::test_suite;



void testCopy(){
	ScrapingOfPage * soPage = new ScrapingOfPage;
	soPage->grab();
}

test_suite* init_unit_test_suite(int, char*[]){
	int params[] = { 1, 2, 3, 4, 5 };
	//boost::unit_test::framework::master_test_suite().add(BOOST_TEST_CASE(&testDelete));
	boost::unit_test::framework::master_test_suite().add(BOOST_TEST_CASE(&testCopy));
	//boost::unit_test::framework::master_test_suite().add(BOOST_TEST_CASE(&testReceiver));
	//boost::unit_test::framework::master_test_suite().add(BOOST_TEST_CASE(&testClient2));
	//boost::unit_test::framework::master_test_suite().add(BOOST_PARAM_TEST_CASE(&test4, params, params + 5));
	return 0;
}



CommonTest::CommonTest(){

}



CommonTest::~CommonTest(){

}