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

		void colle(); //��ȡid
		void colle_all(); //��ȡ������
		int Delete(); // ɾ��

		std::list<char * > * get_fields();
		std::list<rr_report * > * get_report_list();
private:
        std::list<char *> fields;
		std::list<rr_report * >   report_list;
};  //end class DataCollection



#endif
