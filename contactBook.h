#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Contact.h"
#include <sstream>
#include <locale>

#define INDEX_WIDTH 7

using namespace std;

class ContactBook {
public:
	ContactBook();
	void addContact(string name, string email, string number, string city, bool relative);
	void deleteContact(int index);
	void clearContacts();
	void saveContacts(string filename);
	void loadContacts(string filename);
	void printListFromCity(string city);
	void printContacts();
	void printRelatives();
	void printNonRelatives();
	void printWithIndex();
	int getSize();

private:
	vector<Contact> contacts;
};