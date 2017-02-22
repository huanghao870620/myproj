///////////////////////////////////////////////////////////
//  A0.h
//  Implementation of the Class A0
//  Created on:      13-¶þÔÂ-2017 20:43:27
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_A2E45D51_2AFB_41cc_8DD1_F4AC0078D661__INCLUDED_)
#define EA_A2E45D51_2AFB_41cc_8DD1_F4AC0078D661__INCLUDED_

#define HAVE_REMOTE
#include"pcap.h"

#include"ip_header.h"
#include"udp_header.h"

class A0
{

public:
	A0();
	virtual ~A0();
	void test0();
	void test1();
	void test2(int argc, char **argv);
	void test3();
	void test4(int argc, char**argv);
	void test5(int argc, char** argv);
	void test6(int argc, char** argv);
	void test7(int argc, char** argv);

};

void packet_handler(u_char*param, const pcap_pkthdr *header, const u_char *pkt_data);
void packet_handler0(u_char*dumpfile, const pcap_pkthdr *header, const u_char *pkt_data);
void dispatcher_handler(u_char*, const pcap_pkthdr*, const u_char*);
void dispatcher_handler0(u_char *temp1, const pcap_pkthdr *header, const u_char *pkt_data);
#define LINE_LEN 16
#endif 
