#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <regex>
#include <string.h>
using namespace std;

struct Item {
	string name;
	string owner;
	string phone;
	string address;
	string business;
	Item *next;
	Item *previous;
};

class Book {
private:
	Item *begin;
	Item *end;
	void printCurrent(Item *current);
public:
	Book():begin(nullptr),end(nullptr){}
	void add(string name, string owner, string phone, string address, string business);
	void add(Item* source);
	void printAll();
	void loadFromFile(string source);
	void saveToFile(string destination);
	void searchByName(string name);
	void searchByOwner(string owner);
	void searchByPhone(string phone);
	void searchByBusiness(string business);
};

Item* parse(char* source);

#endif