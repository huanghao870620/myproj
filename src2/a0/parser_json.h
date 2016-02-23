#ifndef PARSER_JSON_H
class DrawFlag;

#define PARSER_JSON_H
#include <list>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
class parser_json
{
    public:

        parser_json(DrawFlag * df); 

        ~parser_json(); 

        void colle_msg(char *ptr);

		std::list<struct  StruInte *> * get_msg_list();

		void append_dist_bet(const char * distBet,  char * type);
private:

	void loading(boost::property_tree::ptree * tree);

	char * str = nullptr;
	std::list<struct StruInte *> msg_list;
	//struct StruInte si;
	boost::property_tree::ptree pt;
	DrawFlag * df = nullptr;
};  



#endif
