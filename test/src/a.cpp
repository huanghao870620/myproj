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
 
}
BOOST_AUTO_TEST_SUITE_END()

