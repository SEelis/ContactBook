#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Contact.h"
#include <algorithm>

#define INDEX_WIDTH 7

using namespace std;

class ContactBook {
public:
	ContactBook();
	void addContact(string name, string email, string number, string city, bool relative);
	void deleteContact(int index);
	void clearContacts();
	bool saveContacts(string filename);
	bool loadContacts(string filename);
	void printListFromCity(string city);
	void printContacts();
	void printRelatives();
	void printNonRelatives();
	void printWithIndex();
	int getSize();
	void orderAlphabetically();

private:
	vector<Contact> contacts;
};