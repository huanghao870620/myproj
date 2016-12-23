///////////////////////////////////////////////////////////
//  Config.h
//  Implementation of the Class Config
//  Created on:      21-Ê®¶þÔÂ-2016 16:29:44
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_7BAA41DD_A2D1_441d_AB38_80A704488374__INCLUDED_)
#define EA_7BAA41DD_A2D1_441d_AB38_80A704488374__INCLUDED_

#include<iostream>


class Config
{


private:Config();
public:	virtual ~Config();

public: char* get_db_user();
public: char* get_db_pass();
public: char* get_db_ip();

public:char* get_ftp_ip();
public:char* get_ftp_user();
public:char* get_ftp_pass();

private: std::string iniFile;

public:static Config* getConfig(){
	static Config config;
	return &config;
}
};
#endif // !defined(EA_7BAA41DD_A2D1_441d_AB38_80A704488374__INCLUDED_)
