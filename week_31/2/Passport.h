#ifndef PASSPORT_H
#define PASSPROT_H

#include <string>
#include <iostream>
using namespace std;

class Passport {
protected:
	string firstName;
	string lastName;
	string address;
	
public:
	Passport();
	Passport(string firstName, string lastName, string address);
	~Passport();
};


#endif