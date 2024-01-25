#include <iostream>
#include <stdlib.h>
#include "account.h"
#include <list>
#include<algorithm>
#include<numeric>
using bank_account::Account;
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::for_each;


list<Account>::iterator findId(list<Account>& people, int searchId);

int main()
{
    list<Account> people;
    int quit = 1;
    Account a = Account();
    Contact c = Contact();

    

    while (quit != 0) {
        cout << "Account Menu:\n"
            "0. Quit program\n"
            "1. Display account information\n"
            "2. Add a deposit\n"
            "3. Make a withdrawal\n"
            "4. Create an account\n"
            "5. Find an account\n"
            "6. Remove an account\n"
            "7. Show total balance for all accounts\n"
            "8. Add a dividend\n"
            "9. Add contact info\n"
            "Your choice:";
        cin >> quit;

        if (quit == 1) {


            for_each(people.begin(), people.end(), [](auto& people)
                {
                    people.display();
                    
                });
        }
        else if (quit == 2) {
            int searchId;
            cout << "Enter an ID: ";
            cin >> searchId;
            list<Account>::iterator it;
            it = findId(people, searchId);
            if (it != people.end()) {
                it->getDeposit();
            }
            else {
                cout << "ID does not exist";
            }
        }
        else if (quit == 3) {
            int searchId;
            cout << "Enter an ID: ";
            cin >> searchId;
            list<Account>::iterator it;
            it = findId(people, searchId);
            if (it != people.end()) {
                it->getWithdrawal();
            }
            else {
                cout << "ID does not exist";
            }
        }
        else if (quit == 4) {
            Account account;
            account.initialize();
            people.push_back(account);
        }


        else if (quit == 5) {
            int searchId;
            cout << "Enter an ID: ";
            cin >> searchId;
            list<Account>::iterator it;
            it = findId(people, searchId);
            if (it != people.end()) {
                it->display();
            }
            else {
                cout << "ID does not exist";
            }
        }
        else if (quit == 6) {
            int removeAccount;
            cout << "Enter ID for account: ";
            cin >> removeAccount;

            auto new_end = remove_if(people.begin(), people.end(), [removeAccount](auto& person)
                {
                    return person.getId() == removeAccount;
                }

            );
            people.erase(new_end, people.end());
        }

        else if (quit == 7) {
            float balanceTotal = accumulate(people.begin(), people.end(), 0.0f, [](auto addition, auto& person)
                {
                    return addition + person.getBalance();
                });
            cout << "Total in all accounts: $" << balanceTotal << endl;
        }

        else if (quit == 8) {
            float percentage;
            cout << "Enter a percentage: ";
            cin >> percentage;
            float decimal = percentage / 100;
            auto dividend = transform(people.begin(), people.end(), people.begin(), [decimal](auto& person)
                {
                    float addBalance = person.getBalance() * decimal;
                    person.updateBalance(person.getBalance() + addBalance);
                    return person;

                }
            );
        }

        else if (quit == 9) {

            int searchId;
            cout << "Enter an ID: ";
            cin >> searchId;
            list<Account>::iterator it;
            it = findId(people, searchId);
            if (it != people.end()) {
                it->add_info();
            }
            else {
                cout << "ID does not exist";
            }

        }

        else {
            break;
        }

    }
};
