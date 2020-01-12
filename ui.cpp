#include "ui.h"

#define CANCEL true
#define NOCANCEL false

#define SAVE true
#define LOAD false

Ui::Ui() {
}

//menu for when program starts and to which we always return
void Ui::mainMenu() {
	int choice = -1;
	while (true) {
		cout << "(1) to clear all records." << endl;
		cout << "(2) to save on disk" << endl;
		cout << "(3) to load from disk" << endl;
		cout << "(4) to add a new contact" << endl;
		cout << "(5) to remove a contact" << endl;
		cout << "(6) to print every contact from given city" << endl;
		cout << "(7) to print all contacts: " << endl;

		choice = getIntput(7, "Please enter integer for your action", NOCANCEL);
		cout << endl;

		if (choice == 1) {
			contactBook.clearContacts();
		}
		else if (choice == 2) {
			saveLoadContacts(SAVE);
		}
		else if (choice == 3) {
			saveLoadContacts(LOAD);
		}
		else if (choice == 4) {
			addContact();
		}
		else if (choice == 5) {
			removeContact();
		}
		else if (choice == 6) {
			searchCity();
		}
		else if (choice == 7) {
			printAllContacts();
		}
		cout << endl << endl;
	}
}

//Takes care of adding new contacts
void Ui::addContact() {
	string message = "Cancelling adding a new contact";
	string name = inputName();
	if (checkCancel(name, message)) {
		return;
	}
	string email = inputEmail();
	if (checkCancel(email, message)) {
		return;
	}
	string number = inputNumber();
	if (checkCancel(number, message)) {
		return;
	}
	string city = inputCity();
	if (checkCancel(city, message)) {
		return;
	}
	int relative = inputRelative();
	bool brelative = true;
	if (relative == -1) {
		cout << message << endl;
		return;
	}
	else if (relative == 0) {
		brelative = false;
	}
	contactBook.addContact(name, email, number, city, brelative);
}

//checks if string is "cancel", also posts message passed to function if cancelled
bool Ui::checkCancel(string s, string message) {
	if (s.compare("cancel") == 0) {
		cout << message << endl;
		return true;
	}
	return false;
}

//Gets integer input between 1 and the wanted upper limit, option to include 0 for cancelling
int Ui::getIntput(int highIndex, string message, bool cancel) {
	int choice;
	cout << message << " (1 - " << highIndex << ")";
	if (cancel) {
		cout << " or 0 to cancel";
	}
	cout << ": ";
	while (true) {
		cin >> choice;
		if (cin.fail() || choice > highIndex || choice < 0) {
			cout << "Please enter an integer between ";
			if (cancel) {
				cout << "0";
			}
			else {
				cout << "1";
			}

			cout << " and " << highIndex << ": ";
		}
		else {
			return choice;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

//Getting name for adding contact
string Ui::inputName() {
	string input;
	while (true) {
		cout << "Enter name (max " << MAX_NAME_LENGTH << " characters) of the contact, type \"cancel\" to cancel: ";
		cin >> input;
		if (input.compare("cancel") == 0) {
			return "cancel";
		}
		if (input.length() <= MAX_NAME_LENGTH) {
			return input;
		}
		if (input.length() == 0) {
			cout << "Please enter a name for contact";
		}
		cout << "Please enter name with under " << MAX_NAME_LENGTH << " characters";
	}
	return NULL;
}

//Getting email for adding contact
string Ui::inputEmail() {
	string input;
	while (true) {
		cout << "Enter email (max " << MAX_EMAIL_LENGTH << " characters) of the contact, type \"cancel\" to cancel: ";
		cin >> input;
		if (input.compare("cancel") == 0) {
			return "cancel";
		}
		if (input.length() <= MAX_EMAIL_LENGTH) {
			return input;
		}
		else {
			cout << "Please enter email with under " << MAX_EMAIL_LENGTH << " characters\n";
		}
	}
	return NULL;
}

//Getting phone number for adding contact
string Ui::inputNumber() {
	string input;
	while (true) {
		cout << "Enter phone number (max " << MAX_PHONE_NUMBER_LENGTH << " characters) of the contact, type \"cancel\" to cancel: ";
		cin >> input;
		if (input.compare("cancel") == 0) {
			return "cancel";
		}
		if (input.length() <= MAX_PHONE_NUMBER_LENGTH) {
			return input;
		}
		else {
			cout << "Please enter phone number with under " << MAX_PHONE_NUMBER_LENGTH << " characters\n";
		}
	}
	return NULL;
}

//Getting city name for adding contact
string Ui::inputCity() {
	string input;
	while (true) {
		cout << "Enter city name (max " << MAX_CITY_LENGTH << " characters) of the contact, type \"cancel\" to cancel: ";
		cin >> input;
		if (input.compare("cancel") == 0) {
			return "cancel";
		}
		if (input.length() <= MAX_CITY_LENGTH) {
			return input;
		}
		else {
			cout << "Please enter city name with under " << MAX_CITY_LENGTH << " characters\n";
		}
	}
	return NULL;
}

//Getting whether contact to be added is relative or not
int Ui::inputRelative() {
	string input;
	while (true) {
		cout << "Enter whether or not contact is your relative (Y/N), type \"cancel\" to cancel: ";
		cin >> input;
		if (input.compare("Y") == 0) {
			return 1;
		}
		else if (input.compare("N") == 0) {
			return 0;
		}
		else if (input.compare("cancel") == 0) {
			return -1;
		}
		else {
			cout << "Please enter Y for relative or N for not relative. \n";
		}
	}
}

//prints legends formatted for columns
void Ui::printLegend() {
	cout << left << setw(MAX_NAME_LENGTH + 2) << "Name" << setw(MAX_EMAIL_LENGTH + 2) << "Email" << setw(MAX_PHONE_NUMBER_LENGTH + 2) << "Phone number" << setw(MAX_CITY_LENGTH + 2) << "City" << "Relative" << endl;
}

//prints legends formatted for columns with column for index
void Ui::printLegendWithIndex() {
	cout << left << setw(INDEX_WIDTH) << "Index" << setw(MAX_NAME_LENGTH + 2) << "Name" << setw(MAX_EMAIL_LENGTH + 2) << "Email" << setw(MAX_PHONE_NUMBER_LENGTH + 2) << "Phone number" << setw(MAX_CITY_LENGTH + 2) << "City" << "Relative" << endl;
}

//Either saves or loads contact based on boolean. 
void Ui::saveLoadContacts(bool saveOrLoad) {
	string filename;
	cout << "Please enter file name, enter \"cancel\" to cancel: ";
	cin >> filename;
	string s = saveOrLoad ? "saving contacts." : "loading contacts.";
	if (checkCancel(filename, "Cancelling " + s)) {
		return;
	}
	if (saveOrLoad) {
		contactBook.saveContacts(filename);
	}
	else {
		contactBook.loadContacts(filename);
	}
}

//Handles input for removing contacts
void Ui::removeContact() {
	int size = contactBook.getSize();
	int choice;
	if (size != 0) {
		printLegendWithIndex();
		contactBook.printWithIndex();
		choice = getIntput(size, "Please enter index of the contact to remove", CANCEL);
		if (choice == 0) {
			cout << "Cancelling deleting a contact" << endl;
		}
		else {
			contactBook.deleteContact(choice - 1);
		}
	}
	else {
		cout << "No contacts to delete." << endl;
	}
}

//Handles input for searching contacts based on city
void Ui::searchCity() {
	string city;
	cout << "Enter the city name for the contacts you'd like to search, enter \"cancel\" to cancel: ";
	cin >> city;
	if (checkCancel(city, "Cancelling search.")) {
		return;
	}
	printLegend();
	contactBook.printListFromCity(city);
}

//prints all contacts formatted for columns, relatives first
void Ui::printAllContacts() {
	printLegend();
	contactBook.printRelatives();
	contactBook.printNonRelatives();
}