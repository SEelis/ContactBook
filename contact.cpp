#include "contact.h"
#include <iostream>
#include <iomanip>

using namespace std;

Contact::Contact(string cname, string cemail, string cnumber, string ccity, bool crelative) {
	name = cname;
	email = cemail;
	number = cnumber;
	city = ccity;
	relative = crelative;
}

string Contact::getName() {
	return name;
}

string Contact::getCity() {
	return city;
}

bool Contact::getRelative() {
	return relative;
}

void Contact::printContact() {
	cout << left << setw(MAX_NAME_LENGTH + 2) << name << setw(MAX_EMAIL_LENGTH + 2) << email << setw(MAX_PHONE_NUMBER_LENGTH + 2) << number << setw(MAX_CITY_LENGTH + 2) << city;
	if (relative) {
		cout << right << setw(8) << "x";
	}
	cout << endl;
}

ostream &operator<<(ostream &os, const Contact &c) {
	os << c.name << " " << c.email << " " << c.number << " " << c.city << " " << c.relative;
	return os;
}

istream &operator >> (istream  &is, Contact &c) {
	is >> c.name >> c.email >> c.number >> c.city >> c.relative;
	return is;
}