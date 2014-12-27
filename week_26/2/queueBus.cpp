#include "queueBus.h"




queueBus::~queueBus(void)
{
}


void queueBus::addBus(long time_){
	//	srand(time(NULL));
	if (!begin) {
		begin = new Bus;
		begin->arrive_time = time_;
		begin->next = nullptr;
		begin->free_seats = rand()%25;
		tail = begin;
		current = begin;
	} else {
		tail->next = new Bus;
		tail = tail->next;
		tail->arrive_time = time_;
		tail->free_seats = rand()%25;
		tail->next = nullptr;
	}


}

void queueBus::show(){
	Bus *current = begin;

	while (current != tail) {
		cout << current->arrive_time << " " << 
			current->free_seats << endl;
		current = current->next;
	}
		cout << current->arrive_time << " " << 
			current->free_seats << endl;
}