#include <iostream>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>


BOOST_AUTO_TEST_SUITE(stringtest)

BOOST_AUTO_TEST_CASE(test0)
{
	std::cout << "hello" << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()
