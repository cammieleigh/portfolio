#ifndef contact_h
#define contact_h
#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;
using std::string;



	class Contact {
	private:
		string streetAddress;
		string city;
		string state;
		string zipCode;
		string phone;

	public:
		Contact();
		void getInfo();
		void displayInfo();

	};


#endif