#pragma once
#ifndef LIST_H
#define LIST_H
#include<iostream>
#include<string>

using std::string;

class Contact {
	string name;
	string number;
public:
	Contact() : name(""), number("") {}
	Contact(string name, string number) { (*this).name = name; (*this).number = number; }
	~Contact() {}
	void setName(const Contact & it) { name = it.getName();}
	void setNumber(const Contact & it) { number =  it.getNumber();}
	string getName() const { return (*this).name; }
	string getNumber()  const { return this->number; }
};

typedef  Contact Item;

//template <typename Item>
struct Node {
	Item item;
	Node * next;
	Node * previous;

	//Node() {
	//	this->item = Item();
	//}
};


class List {

	Node * front;
	Node * rear;
	int sizeOfList;

public:
	List();
	List(const List & list);
	~List();
	List operator=(const List & list);
	/*template<typename T>
	int findNode(T & s);
	*/
	int findNode(string &s);
	int findNode(const Item & c);
	bool empty() const { return front == nullptr; }
	bool push(const Item & c);

	bool pop(string & s);

	void print();
	string findNumber(string &s);
	bool editNode(string & s, const Item & c);
	//Node & getNode(int number);
	int size() const { return sizeOfList; }
	//List getList() { return *this; }
};

#endif