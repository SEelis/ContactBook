#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include "contactBook.h"

using namespace std;

class Ui {
public:
	Ui();
	void mainMenu();

private:
	ContactBook contactBook;
	int getIntput(int ceiling, string meesage, bool cancelling);
	string inputName();
	string inputEmail();
	string inputNumber();
	string inputCity();
	int inputRelative();
	void addContact();
	bool checkCancel(string s, string message);
	void printLegend();
	void printLegendWithIndex();
	void saveLoadContacts(bool saveOrLoad);
	void removeContact();
	void searchCity();
	void printAllContacts();
};
