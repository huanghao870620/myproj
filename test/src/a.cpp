#include <iostream>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>

using boost::unit_test::test_suite;
test_suite* init_unit_test_suite(int, char*[]){
	std::cout << "222" << std::endl;
	return 0;
}
BOOST_AUTO_TEST_SUITE(a)
/*

BOOST_AUTO_TEST_CASE(test0)
{
	std::cout << "hello" << std::endl;
	
}

using boost::unit_test::test_suite;

test_suite* init_unit_test_suite(int, char*[])
{
	//framework::master_test_suite().p_name.value = "Unit test example 01";
	// register the test case in test tree and specify number of expected failures so   
	// this example will pass at runtime. We expect 2 errors: one from failed check and    
	// one from memory acces violation   
	//framework::master_test_suite().add(BOOST_TEST_CASE(&myTest), 1);
	
	return 0;
}


*/
BOOST_AUTO_TEST_SUITE_END()

