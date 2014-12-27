#pragma once
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class queueBus

{
private:
	struct Bus {
		long arrive_time;
		int free_seats;
		Bus *next;
	};
	Bus *begin, *tail, *current;

	

public:
	queueBus():tail(nullptr),begin(nullptr), current(nullptr){}
	~queueBus(void);
	void addBus(long time_);
	void show();
	void next(){
		if (current != tail)
		current = current->next;
	}
	int& getSeats(){return current->free_seats;}
	long& getTime(){return current->arrive_time;}
};

