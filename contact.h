#pragma once

#include <string>
#include <iostream>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 35
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_CITY_LENGTH 20

using namespace std;

class Contact {
public:
	Contact(string name = "0", string email = "0", string number = "0", string city = "0", bool relative = false);
	string getName();
	string getCity();
	bool getRelative();
	void printContact();
	friend ostream &operator << (ostream &os, const Contact &c);
	friend istream &operator >> (istream  &is, Contact &c);
	friend bool operator < (const Contact &c1, const Contact &c2);

private:
	string name;
	string email;
	string number;
	string city;
	bool relative;
};
