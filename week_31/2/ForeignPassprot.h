#ifndef PASSPORT_H
#define PASSPROT_H

#include "Passport.h"

class ForeignPassprot: public Passport{
private:
	string visa;
	string number;
public:
	ForeignPassprot();
	ForeignPassprot(string firstName, string lastName, string address, string visa, string number);
	~ForeignPassprot();
	void show();

};


#endif