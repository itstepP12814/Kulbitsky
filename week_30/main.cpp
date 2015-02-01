#include "Book.h"
int main() {
	Book myBook;
	myBook.loadFromFile("D:\\jsonBook.json");
	
	string name;
	string owner;
	string phone;
	string address;
	string business;
	cout << "Name :";
	getline(cin, name);
	cout << "Owner: ";
	getline(cin, owner);
	cout << "Phone: ";
	getline(cin, phone);
	cout << "Address: ";
	getline(cin, address);
	cout << "Business: ";
	getline(cin, business);
	myBook.add(name, owner, phone, address, business);
	myBook.saveToFile("D:\\jsonBook.json");
	return 0;
}