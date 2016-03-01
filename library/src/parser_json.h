#ifndef PARSER_JSON_H

#define PARSER_JSON_H
#include <list>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class StruInte;

class parser_json
{
    public:

        parser_json(); 

        ~parser_json(); 

        void colle_msg(char *ptr);

		std::list<StruInte *> * get_msg_list();

		void append_dist_bet(const char * distBet,  char * type);
private:

	void loading(boost::property_tree::ptree * tree);
	char * str = nullptr;
	std::list<StruInte *> msg_list;
	boost::property_tree::ptree pt;
};  



#endif
