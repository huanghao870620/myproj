#ifndef DATACOLLECTION_H
#define DATACOLLECTION_H
#include <list>
class ConnMysql;
class rr_report;
class DataCollection
{
    public:

        DataCollection(); 
        ~DataCollection(); 

		void colle(); //获取id
		void colle_all(); //获取所有列
		int Delete(); // 删除

		std::list<char * > * get_fields();
		std::list<rr_report * > * get_report_list();
private:
        std::list<char *> fields;
		std::list<rr_report * >   report_list;
};  //end class DataCollection



#endif
