#include "Aspirant.h"
Aspirant::Aspirant(){
	theme_of_work = "notheme";
	cout << "Aspirant was created" << endl;
}
Aspirant::Aspirant(string name, int age, string speciality, string theme_of_work):Student(name, age, speciality) {
	this->theme_of_work = theme_of_work;
	cout << "Aspirant was created" << endl;
}
Aspirant::~Aspirant(){
	cout << "Aspirant was destoyed" << endl;
}

void Aspirant::show() {
	cout << this->name << endl;
	cout << this->age << endl;
	cout << this->speciality << endl;
	cout << this->theme_of_work << endl;

}