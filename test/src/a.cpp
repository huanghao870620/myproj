#include <iostream>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>
#include "CDBOperation.h"

using boost::unit_test::test_suite;
test_suite* init_unit_test_suite(int, char*[]){
	std::cout << "111111" << std::endl;
	return 0;
}


BOOST_AUTO_TEST_SUITE(d)
BOOST_AUTO_TEST_CASE(test0){
	CDBOperation dbOper;
	bool bConn = dbOper.ConnToDB("Provider=OraOLEDB.Oracle;Persist Security Info=True;Data Source=192.168.10.208:1521/orcl", "junchuan", "junchuan");
	if (false == bConn){
		std::cout << "connection error!" << std::endl;
		return;
	}
}
BOOST_AUTO_TEST_SUITE_END()

