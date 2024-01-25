#include "account.h"
#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;
using std::string;
using std::cout;
using std::cin;
using bank_account::Account;
using std::string;
float withdrawal;
float deposit;

int Account::nextId = 1;

Account::Account() : id{ 0 }, name{ "" }, balance{ 0 }, member_contact(nullptr) {}
Account::Account(int aid, float abalance, string aname) : id{ aid }, balance{ abalance }, name{ aname }, member_contact{ nullptr } {}





void Account::initialize() {
    id = nextId++;

    cout << "Enter name:";
    cin >> name;

    cout << "Enter balance:";
    cin >> balance;

    
}
void Account::setId(int aid) {
    id = aid;
}

int Account::getId() {
    return id;
}

void Account::updateBalance(float newBalance) {
    balance = newBalance;
}

float Account::getBalance() {
    return balance;
}

void Account::setName(string aname) {
    name = aname;
}

void Account::setBalance(float abalance) {
    balance = abalance;
}


float Account::getDeposit() {
    cout << "Deposit amount:";
    cin >> deposit;
    balance += deposit;
    return balance;
}

float Account::getWithdrawal() {
    cout << "Withdrawal amount:";
    cin >> withdrawal;
    balance -= withdrawal;
    return balance;
}

void Account::display() {

    cout << "Account ID:" << id << " Name: " << name << " Balance: " << balance << endl;
    if (member_contact != nullptr)
    {
        member_contact->displayInfo();
    }

}

list<Account>::iterator findId(list<Account>& people, int searchId) {
    list<Account>::iterator it;
    for (it = people.begin(); it != people.end(); it++)
    {
        if (it->getId() == searchId)
        {
            return it;
        }
        else {
            cout << "ID is not found";
            return it;
        }
    }
}


void Account::add_info()
{
    member_contact = std::make_shared<Contact>();
    member_contact->getInfo();
}

