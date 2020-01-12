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

//prints contact formatted for columns
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

bool operator < (const Contact &c1, const Contact &c2) {
	if (c1.name != c2.name) {
		return c1.name < c2.name;
	} else if (c1.relative != c2.relative) {
		return c1.relative;
	} else if (c1.city != c2.city) {
		return c1.city < c2.city;
	} else if (c1.email != c2.email) {
		return c1.email < c2.email;
	} else if (c1.number != c2.number) {
		return c1.number < c2.number;
	} else {
		return false;
	}
}