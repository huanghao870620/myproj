///////////////////////////////////////////////////////////
//  customer.cpp
//  Implementation of the Class customer
//  Created on:      08-Ê®Ò»ÔÂ-2016 10:21:23
//  Original author: admin
///////////////////////////////////////////////////////////



#include "customer.h"
#include "customer-odb.hxx"
//using namespace std;
//using namespace odb::core;







customer::customer(){

}



customer::~customer(){

}

//std::string& customer::get_name(){
//	return this->name_;
//}



int
main(int argc, char* argv[])
{
	try
	{

		//auto_ptr<database> db (create_database (argc, argv));
		
		std::auto_ptr<odb::database> db(
			new odb::mysql::database("root", "xa", "test", "192.168.1.102", 3306)
			);

		std::cout << "1111111111" << std::endl;

		{
			/*customer john("john@doe.com", "John", "X", "Doe", 31);
			customer jane("jane@doe.com", "Jane", "Y", "Doe", 29);*/
			
			/*odb::core::transaction t(db->begin());
			db->persist(john);
			db->persist(jane);
			t.commit();*/


			customer a;
			odb::core::transaction t(db->begin());
			std::string name = "22154";
			a.set_mobile(name);
			db->persist(a);
			t.commit();

		}

		{
			/*typedef odb::result<person> result;

			transaction t(db->begin());
			result r(db->query<person>());

			for (result::iterator i(r.begin()); i != r.end(); ++i)
				cout << i->getFirst() << ' '
				<< i->g_middle() << ' '
				<< i->last() << ' '
				<< i->email() << ' '
				<< i->age() << endl;

			t.commit();*/


			typedef odb::result<customer> result;
			odb::core::transaction t(db->begin());
			result r(db->query<customer>());
			for (result::iterator i(r.begin()); i != r.end(); ++i){
				std::cout << i->get_mobile()<< std::endl;
				
			}
			t.commit();

		}
	}
	catch (const odb::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
