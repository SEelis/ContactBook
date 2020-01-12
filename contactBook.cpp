#include "contactBook.h"

ContactBook::ContactBook() {
}

void ContactBook::clearContacts() {
	contacts.clear();
}

void ContactBook::addContact(string name, string email, string number, string city, bool relative) {
	contacts.push_back(Contact(name, email, number, city, relative));
}

void ContactBook::deleteContact(int index) {
	contacts.erase(contacts.begin() + index);
}


void ContactBook::printContacts() {
	for (auto i = contacts.begin(); i != contacts.end(); ++i) {
		i->printContact();
	}
}

void ContactBook::printRelatives() {
	for (auto i = contacts.begin(); i != contacts.end(); ++i) {
		if (i->getRelative()) {
			i->printContact();
		}
	}
}

void ContactBook::printNonRelatives() {
	for (auto i = contacts.begin(); i != contacts.end(); ++i) {
		if (!i->getRelative()) {
			i->printContact();
		}
	}
}

void ContactBook::printWithIndex() {
	int index = 0;
	for (auto i = contacts.begin(); i != contacts.end(); ++i) {
		cout << right << setw(INDEX_WIDTH - 2) << ++index << "  ";
		i->printContact();
	}
}

int ContactBook::getSize() {
	return contacts.size();
}

void ContactBook::printListFromCity(string city) {
	for (auto i = contacts.begin(); i != contacts.end(); ++i) {
		if (city.compare(i->getCity()) == 0) {
			i->printContact();
		}
	}
}

void ContactBook::saveContacts(string filename) {
	ofstream savefile;
	savefile.open(filename, ios::out | ios::trunc);
	if (savefile.is_open()) {
		for (auto i = contacts.begin(); i != contacts.end(); ++i) {
			savefile << *i << endl;
		}
		savefile.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void ContactBook::loadContacts(string filename) {
	ifstream readfile;
	readfile.open(filename, ios::in);
	Contact c;
	if (readfile.is_open()) {
		contacts.clear();
		while (readfile >> c) {
			contacts.push_back(c);
		}
		readfile.close();
	}
	else {
		cout << "Unable to open file";
	}
}