#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;
class Student {
protected:
	string name;
	int age;
	string speciality;
public:
	Student();
	Student(string name, int age, string speciality);
	~Student();
};

#endif