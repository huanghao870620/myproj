
#if !defined(_LOGOPERATOR_H)
#define _LOGOPERATOR_H
#include <iostream>
#include <list>
class ConnMysql;
class rr_report_dialy_log;


class LogOperator {
public:
	LogOperator();
	~LogOperator();

	void select();

	std::list<rr_report_dialy_log * > * get_fields();
	
private:
	ConnMysql * conn;
	std::list<rr_report_dialy_log * > fields;
};

#endif  
