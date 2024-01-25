#include "contact.h"
#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::string;


Contact::Contact() : streetAddress{ "" }, city{ "" }, state{ "" }, zipCode{ "" }, phone{ "" } {}


void Contact::getInfo() {

    cout << "Enter street address: ";
    cin >> streetAddress;
    cout << "Enter city: ";
    cin >> city;
    cout << "Enter state: ";
    cin >> state;
    cout << "Enter zip code: ";
    cin >> zipCode;
    cout << "Enter phone number: ";
    cin >> phone;


}

void Contact::displayInfo() {

    cout << "Street Address:" << streetAddress << endl << "City: " << city << endl << " State: " << state << endl << "Zipcode: " << zipCode << endl << "Phone number: " << phone << endl;

}