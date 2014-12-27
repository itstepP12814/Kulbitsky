#include "queuePassenger.h"

queuePassenger::~queuePassenger(void)
{
}

void queuePassenger::addPassenger(long time_){
	if (!begin) {
		begin = new Passenger;
		begin->enter_time = time_;
		begin->next = nullptr;
		tail = begin;
		
	} else {
		tail->next = new Passenger;
		tail = tail->next;
		tail->enter_time = time_;
		tail->next = nullptr;
	}
}


void queuePassenger::cutPassenger(){
	if (begin!=tail) {
		Passenger *temp = begin;
		begin = begin->next;
		delete temp;
	}

}

void queuePassenger::show(){
	Passenger *current = begin;
	while (current != tail) {
		cout << current->enter_time << endl;
		current = current->next;
	}
	cout << current->enter_time << endl;

}