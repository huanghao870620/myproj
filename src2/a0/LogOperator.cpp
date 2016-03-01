#include "ConnMysql.h"
#include "rr_report_dialy_log.h"
#include "LogOperator.h"

	LogOperator::LogOperator() {

	}

	LogOperator::~LogOperator(){
	}

	void LogOperator::select(){
		MYSQL_RES * res =  this->conn->select("select * from rr_report_daily_log limit 2");
		std::size_t sum = mysql_num_fields(res);
		MYSQL_ROW row;
		while (row = mysql_fetch_row(res)){
			std::string id = row[0];
			std::string dateft = row[1];
			std::string org = row[2];
			std::string title = row[3];
			std::string type = row[4];
			std::string flag = row[5];
			std::string num = row[6];
			std::string exc_info = row[7];
			std::string create_time = row[8];

			rr_report_dialy_log * log = new rr_report_dialy_log;
			log->set_id(id);
			log->set_dateft(dateft);
			log->set_org(org);
			log->set_title(title);
			log->set_type(type);
			log->set_flag(flag);
			log->set_num(num);
			log->set_exc_info(exc_info);
			log->set_create_time(create_time);
			this->fields.push_back(log);
		}
	}


	std::list<rr_report_dialy_log * > * LogOperator::get_fields(){
		return  & this->fields;
	}


