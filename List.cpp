#include "List.h"

using std::cout;
using std::endl;
using std::cin;

List::List() {
	sizeOfList = 0;
	front = nullptr;
	rear = nullptr;
}
//
List::List(const List & list) {
	front = nullptr;
	rear = nullptr;
	sizeOfList = 0;
	if (! list.empty()) {
		Node * temp = list.rear;
		while (temp) {
			this->push(temp->item);
			temp = temp->next;
		}
	}
}
//
List List::operator=(const List & list) {
	if (this->empty()) {
		front = nullptr;
		rear = nullptr;
		sizeOfList = 0;
		if (!list.empty()) {
			Node * temp = list.rear;
			while (temp) {
				this->push(temp->item);
				temp = temp->next;
			}
		}
	}
	else {
		Node *temp = this->rear;
		while (temp) {
			rear = rear->next;
			delete temp;
			temp = this->rear;
		}
		front = nullptr;
		rear = nullptr;
		sizeOfList = 0;
		if (!list.empty()) {
			Node * temp = list.rear;
			while (temp) {
				this->push(temp->item);
				temp = temp->next;
			}
		}
	}
	return *this;
}
//
List::~List() {
	Node * temp = rear;
	while (temp) {
		cout << temp->item.getName();
		rear = rear->next;
		delete temp;
		cout <<  " Usunieto kontakt\n";
		sizeOfList--;
		temp = rear;
	}
}
///
string List::findNumber(string &s) {
	int it = 1;
	Node * temp = rear;
	while (temp) {
		if (temp->item.getName() == s)
		{
			return temp->item.getNumber();
		}
		temp = temp->next;
		it++;
	}
	return "";
}
///
bool List::editNode(string & s, const Item & c) {
	int n = findNode(s);
	if (n >= 0) {
		int i = 1;
		Node * temp = rear;
		while (i != n) {
			temp = temp->next;
			i++;
		}
		temp->item.setName(c);
		temp->item.setNumber(c);
		cout << "Successfully edited! \n";
		return true;
	}
	else {
		cout << "No such contact! \n";
		return false;
	}
}
///
//template<typename T>
//int findNode(T & s)
int List::findNode(string &s) //sprobwac template zrobic na to i specjalizacje dla obiektu
{
	int it = 1;
	Node * temp = rear;
	while (temp) {
		if (temp->item.getName() == s)
		{
			return it;
		}
		temp = temp->next;
		it++;
	}
	return -1;
}
///
int List::findNode(const Item & c) {
	int it = 1;
	Node * temp = rear;
	while (temp) {
		if (temp->item.getName() == c.getName())
		{
			return it;
		}
		temp = temp->next;
		it++;
	}
	return -1;
}
///
bool List::pop(string & s){
	Node * temp = rear;
	while (temp) {
		if (temp->item.getName() == s) {
			if (temp == rear) {
				rear = rear->next;
				rear->previous = nullptr;//co jesli to byl 1. wezel? -> null-> null?
				delete temp;
				sizeOfList--;
				return true;
			}
			else if (temp == front) {
				front = front->previous;
				front->next = nullptr;
				delete temp;
				sizeOfList--;
				return true;
			}
			else {
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
				delete temp;
				sizeOfList--;
				return true;
			}
		}
		temp = temp->next;
	}
	return false;	
}
///
bool List::push(const Item & c) {
	if (empty()) {
		//create list
		Node * temp = new Node;
		temp->item = c;
		temp->previous = nullptr;
		temp->next = nullptr;
		front = temp;
		rear = temp;
		sizeOfList++;
		return true;
	}
	else {
		if (findNode(c) >= 0) {
			return false;
		}
		else {
			Node * temp = new Node;
			temp->item = c;
			temp->next = nullptr;
			temp->previous = front;
			front->next = temp;
			front = temp;
			sizeOfList++;
			return true;
		}
	}
}
///
void List::print() {
	Node * temp = rear;
	int i = 1;
	while (temp) {
		cout << i << ". " << temp->item.getName() << " " << temp->item.getNumber() << endl;
		i++;
		temp = temp->next;
	}
}