#include "Student.h"
Student::Student(){
	name = "noname";
	age = 0;
	speciality = "nospeciality";
	cout << "Student was created" << endl;
}
Student::Student(string name, int age, string speciality) {
	this->name = name;
	this->age = age;
	this->speciality = speciality;
	cout << "Student was created" << endl;
	
}
Student::~Student() {
	cout << "Student was destroyed" << endl;
}