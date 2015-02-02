#include "Passport.h"
Passport::Passport(){
	firstName = "no_first_name";
	lastName = "no_last_name";
	address = "no_address";
	cout << "Passport was created" << endl;
}
Passport::Passport(string firstName, string lastName, string address) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->address = address;
	cout << "Passport was created" << endl;
	
}
Passport::~Passport() {
	cout << "Passport was destroyed" << endl;
}