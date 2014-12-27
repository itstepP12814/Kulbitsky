#pragma once
#include <iostream>
using namespace std;
class queuePassenger
{
private:
	struct Passenger{
		long enter_time;
		Passenger *next;
	};
	Passenger *begin, *tail, *current;


public:
	queuePassenger():tail(nullptr),begin(nullptr){}
	~queuePassenger();
	void addPassenger(long time_);
	void cutPassenger();
	void show();
	long& getTime(){return begin->enter_time;}
	
};

