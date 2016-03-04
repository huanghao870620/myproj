#include "ConnMysql.h"
#include "rr_report_dialy_log.h"

#include "LogOperator.h"

	LogOperator::LogOperator() {



	}

	LogOperator::~LogOperator(){
	}

	void LogOperator::select(){
		ConnMysql * conn = ConnMysql::getInstance();
		MYSQL_RES * res =  conn->select("select * from rr_report_daily_log limit 2");
		std::size_t sum = mysql_num_fields(res);
		MYSQL_ROW row;
		while (row = mysql_fetch_row(res)){
			std::string id;
			std::string dateft;
			std::string org;
			std::string title;
			std::string type;
			std::string flag;
			std::string num;
			std::string exc_info;
			std::string create_time;

			if (row[0] != nullptr){
				id=row[0];
			}
			if (row[1] != nullptr){
				dateft = row[1];
			}
			if (row[2] != nullptr){
				org = row[2];
			}
			if (row[3] != nullptr){
				title = row[3];
			}
			if (row[4] != nullptr){
				type = row[4];
			}


			if (row[5] != nullptr){
				flag = row[5];
			}
			if (row[6] != nullptr){
				num = row[6];
			}
			if (row[7] != nullptr){
				exc_info = row[7];
			}

			if (row[8] != nullptr){
				create_time = row[8];
			}

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


