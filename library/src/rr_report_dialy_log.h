#if !defined(_RR_REPORT_DIALY_LOG_H)
#define _RR_REPORT_DIALY_LOG_H
#include <iostream>

class rr_report_dialy_log {

public:
	 rr_report_dialy_log();
	 ~rr_report_dialy_log();

	 std::string & get_id();
	 void set_id(std::string & id);

	 std::string & get_dateft();
	 void set_dateft(std::string & dateft);

	 std::string & get_org();
	 void set_org(std::string & org);

	 std::string & get_title();
	 void set_title(std::string & title);

	 std::string & get_type();
	 void set_type(std::string & type);

	 std::string & get_flag();
	 void set_flag(std::string & flag);

	 std::string & get_num();
	 void set_num(std::string & num);

	 std::string & get_exc_info();
	 void set_exc_info(std::string & exc_info);

	 std::string & get_create_time();
	 void set_create_time(std::string & create_time);

private:
	std::string id;
	std::string dateft;
	std::string org;
	std::string title;
	std::string type;
	std::string flag;
	std::string num;
	std::string exc_info;
	std::string creat_time;
};

#endif
