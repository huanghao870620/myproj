///////////////////////////////////////////////////////////
//  ip_address.h
//  Implementation of the Class ip_address
//  Created on:      04-¶þÔÂ-2017 0:39:34
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_CC6892CB_9B9E_4587_9DB0_BB127196E4B7__INCLUDED_)
#define EA_CC6892CB_9B9E_4587_9DB0_BB127196E4B7__INCLUDED_

#include"pcap.h"
class ip_address
{

public:
	ip_address();
	virtual ~ip_address();

	/*void set_byte1(u_char byte1){
		this->byte1 = byte1;
	}
	void set_byte2(u_char byte2){
		this->byte2 = byte2;
	}
	void set_byte3(u_char byte3){
		this->byte3 = byte3;
	}
	void set_byte4(u_char byte4){
		this->byte4 = byte4;
	}

	u_char get_byte1(){
		return this->byte1;
	}
	u_char get_byte2(){
		return this->byte2;
	}
	u_char get_byte3(){
		return byte3;
	}
	u_char get_byte4(){
		return byte4;
	}*/

	u_char byte1;
	u_char byte2;
	u_char byte3;
	u_char byte4;

};
#endif // !defined(EA_CC6892CB_9B9E_4587_9DB0_BB127196E4B7__INCLUDED_)

