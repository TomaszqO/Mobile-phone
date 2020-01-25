#pragma once
#ifndef  MOBILE_H
#define MOBILE_H
#include <iostream>
#include "List.h"
using std::string;

class MobilePhone {

	string number;
	List list;

public:

	MobilePhone(string number);
	MobilePhone();
	~MobilePhone();
	void addContact();
	void removeContact();
	void editContact();
	void chooseContact();
	void printContacts();
	List & getList();

};

#endif // ! MOBILE

