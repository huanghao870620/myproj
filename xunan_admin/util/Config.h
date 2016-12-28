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

private:
		Config();		
		std::string iniFile;
public:	
		virtual ~Config();
		char* get_db_user();
		char* get_db_pass();
		char* get_db_ip();

		char* get_ftp_ip();
		char* get_ftp_user();
		char* get_ftp_pass();
		char* get_img_ip();
		char* get_local_path();
		char* get_remote_path();

		static Config* getConfig(){
			static Config config;
			return &config;
		}
};
#endif // !defined(EA_7BAA41DD_A2D1_441d_AB38_80A704488374__INCLUDED_)
