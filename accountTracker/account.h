#ifndef account_h
#define account_h
#include <iostream>
#include <stdlib.h>
#include <list>
#include "contact.h"
#include <memory>
using namespace std;
using std::string;

namespace bank_account {
	class Account {
	private:
		int id;
		string name;
		float balance;
		static int nextId;
		std::shared_ptr<Contact> member_contact;

	public:
		Account();
		Account(int a_id, float a_balance, string a_name);
		void initialize();
		void setId(int aid);
		int getId();
		void setName(string aname);
		void setBalance(float abalance);
		float getWithdrawal();
		float getDeposit();
		void display();
		float getBalance();
		void updateBalance(float newBalance);
		void add_info();
	};
	
}
#endif

