///////////////////////////////////////////////////////////
//  ip_header.h
//  Implementation of the Class ip_header
//  Created on:      15-¶þÔÂ-2017 21:16:12
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_FE906E51_C4B3_4840_A5A2_5287D912EBF9__INCLUDED_)
#define EA_FE906E51_C4B3_4840_A5A2_5287D912EBF9__INCLUDED_

#include"pcap.h"
#include"ip_address.h"
class ip_header
{

public:
	ip_header();
	virtual ~ip_header();

	/*void set_ver_ihl(u_char ver_ihl){
		this->ver_ihl = ver_ihl;
	}

	void set_tos(u_char tos){
		this->tos = tos;
	}

	void set_tlen(u_short tlen){
		this->tlen = tlen;
	}

	void set_identification(u_short identification){
		this->identification = identification;
	}

	void set_flags_fo(u_short flags_fo){
		this->flags_fo = flags_fo;
	}

	void set_ttl(u_char ttl){
		this->ttl = ttl;
	}


	void set_proto(u_char proto){
		this->proto = proto;
	}

	void set_crc(u_short crc){
		this->crc = crc;
	}

	void set_saddr(ip_address saddr){
		this->saddr = saddr;
	}

	void set_daddr(ip_address daddr){
		this->daddr = daddr;
	}

	void set_op_pad(u_int op_pad){
		this->op_pad = op_pad;
	}


	u_char  get_ver_ihl(){
		return ver_ihl;
	}

	u_char get_tos(){
		return tos;
	}

	u_short get_tlen(){
		return tlen;
	}

	u_short get_identification(){
		return identification;
	}

	u_short get_flags_fo(){
		return flags_fo;
	}

	u_char get_ttl(){
		return ttl;
	}

	u_char get_proto(){
		return proto;
	}

	u_short  get_crc(){
		return crc;
	}

	ip_address get_saddr(){
		return saddr;
	}

	ip_address get_daddr(){
		return daddr;
	}

	u_int get_op_pad(){
		return op_pad;
	}*/


	u_char ver_ihl;
	u_char tos;
	u_short tlen;
	u_short identification;
	u_short flags_fo;
	u_char ttl;
	u_char proto;
	u_short crc;
	ip_address saddr;
	ip_address daddr;
	u_int op_pad;
};
#endif // !defined(EA_FE906E51_C4B3_4840_A5A2_5287D912EBF9__INCLUDED_)
