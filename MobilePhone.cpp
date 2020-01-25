#include "MobilePhone.h"
#include "List.h"
using std::cout;
using std::endl;
using std::cin;


MobilePhone::MobilePhone(string number) {

	number = number;
	list = List();

}

MobilePhone::MobilePhone() {

	cout << "Enter your phone number: \n";
	cin >> number;
	list = List();

}
MobilePhone::~MobilePhone() {

	list.~List();

}
void MobilePhone::chooseContact() {

	cout << "Enter name of contact that you want to find: ";
	string name;
	cin >> name;
	string number = list.findNumber(name);
	if (number != "") {
		cout << " Calling to " << number << endl;
		return;
	}
	else {
		cout << "No such contact in contact list.\n";
		return;
	}
}

void MobilePhone::editContact() {

	cout << "Enter name of contact to edit: ";
	string name;
	cin >> name;
	cout << "Enter new name contact: ";
	string Name, Number;
	cin >> Name;
	cout << "Enter number of  contact: ";
	cin >> Number;
	Contact newContact(Name, Number);
	list.editNode(name, newContact);

}

void MobilePhone::removeContact() {

	cout << "enter name of contact to remove: ";
	string name;
	cin >> name;
	if (list.pop(name)) {
		cout << "deleted!\n";
	}
	else cout << "no such contact on list.\n";

}

void MobilePhone::addContact() {

	cout << "Enter name of new contact: ";
	string Name, Number;
	cin >> Name;
	cout << "Enter number of new contact: ";
	cin >> Number;
	Contact newContact(Name, Number);
	if (list.push(newContact)) {
		cout << "Contact added!\n";
	}
	else { cout << "Contact already existed!\n"; }
}

void MobilePhone::printContacts() {

	this->list.print();
}

List & MobilePhone::getList() {
	return this->list;
}