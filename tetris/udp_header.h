///////////////////////////////////////////////////////////
//  udp_header.h
//  Implementation of the Class udp_header
//  Created on:      15-¶þÔÂ-2017 21:27:37
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_8F98A05D_030B_4f75_A270_10C0909E26BC__INCLUDED_)
#define EA_8F98A05D_030B_4f75_A270_10C0909E26BC__INCLUDED_

#include"pcap.h"
class udp_header
{

public:
	udp_header();
	virtual ~udp_header();

	/*void set_sport(u_short sport){
		this->sport = sport;
	}

	void set_dport(u_short dport){
		this->dport = dport;
	}

	void set_len(u_short len){
		this->len = len;
	}

	void set_crc(u_short crc){
		this->crc = crc;
	}

	u_short get_sport(){
		return sport;
	}

	u_short get_dport(){
		return dport;
	}

	u_short get_len(){
		return len;
	}

	u_short get_crc(){
		return crc;
	}*/

	u_short sport;
	u_short dport;
	u_short len;
	u_short crc;

};
#endif // !defined(EA_8F98A05D_030B_4f75_A270_10C0909E26BC__INCLUDED_)
