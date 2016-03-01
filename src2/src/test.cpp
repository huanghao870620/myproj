#include <iostream>
#include "test.h"
#include "Crawler.h"

using namespace std;

test::test()
{
}


test::~test()
{
}

void test::CalOfByte(char * oIn){
	while (*oIn != '\0'){
		cout << *oIn << endl;
		cout << (int)*oIn << endl;
		oIn++;
	}
}

