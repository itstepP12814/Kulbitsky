#include "ForeignPassprot.h"
ForeignPassprot::ForeignPassprot(){
	visa = "no_visa";
	number = "no_number";
	cout << "ForeignPassprot was created" << endl;
}
ForeignPassprot::ForeignPassprot(string firstName, string lastName, string address, string visa, string number):
Passport(firstName, lastName, address)
{
	this->visa = visa;
	this->number = number;
	cout << "ForeignPassprot was created" << endl;
}
ForeignPassprot::~ForeignPassprot(){
	cout << "ForeignPassprot was destoyed" << endl;
}

void ForeignPassprot::show() {
	cout << this->firstName << endl;
	cout << this->lastName << endl;
	cout << this->address << endl;
	cout << this->visa << endl;
	cout << this->number << endl;

}