#ifndef CODING_H
#define CODING_H

#include <WinSock2.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <exception>
#include <boost\locale.hpp>
#pragma comment(lib, "ws2_32.lib")


class Coding
{

    public:
        Coding(); 

        ~Coding(); 

		std::string URLDecode(const std::string &sIn);

		byte fromHex(const BYTE &x);

		void urldecode2(char *dst, const char *src);


};  //end class Coding



#endif
