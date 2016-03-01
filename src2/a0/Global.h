#ifndef GLOBAL_H
#define GLOBAL_H
#include <iostream>

class Global
{
    public:
		Global(int weight, std::string & name);
        ~Global(); 

    private:
        int weight;
		std::string name;
};  

#endif
