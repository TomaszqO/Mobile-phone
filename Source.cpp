#include <iostream>
#include "List.h"
#include "MobilePhone.h"

using std::cin;
using std::cout;
using std::endl;
void Menu(MobilePhone & mobile);
void print();

struct wezel {
	int liczba;
	wezel * next;
} w0{ 90,nullptr };

int main() {
	
		MobilePhone mobile("+4898812341");
		Menu(mobile);
	
	cin.get();
	return 0;
}

void Menu(MobilePhone & mobile) {
	cout << "Choose option: \n";
	print();
	bool process = true;
	while (process) {

		int choice;
		while (!(cin>>choice)) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		switch (choice) {
		case 0:
			print();
			break;
		case 1:
			mobile.printContacts();
			break;
		case 2:
			mobile.addContact();
			break;
		case 3:
			mobile.removeContact();
			break;
		case 4:
			mobile.editContact();
			break;
		case 5:
			mobile.chooseContact();
			break;
		default:
			process = false;
		}
	}
}

void print() {
	cout << "0. Print menu.\n1. Print contacts \n2. Add contact\n3. Remove contact\n"
		"4. Edit contact \n5. Choose number\n6. Exit.\n";
}