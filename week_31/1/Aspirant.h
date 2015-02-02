#ifndef ASPIRANT_H
#define ASPIRANT_H

#include "Student.h"

class Aspirant: public Student{
private:
	string theme_of_work;
public:
	Aspirant();
	Aspirant(string name, int age, string speciality, string theme_of_work);
	~Aspirant();
	void show();

};

#endif