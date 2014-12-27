#include "queuePassenger.h"
#include "queueBus.h"
#include <time.h>
#include <stdlib.h>
int main() {

	srand(time(NULL));
	const int N = 24;

	int periodicity[N];
	int BusPer[N];
	long wait[10000];
	long count = 0;
	for (int i = 0; i < N; ++i) {
		periodicity[i] = rand()%10 + 1;
		BusPer[i] = rand()%20+1;
	}
	queuePassenger queue;
	queueBus bus;
	int time_ = 0; // time in minutes since the begin of the day

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < int (60/BusPer[i]); ++j) {
			bus.addBus(time_);
			time_ += BusPer[i];
		}
	
	}
	int time = 0;
	queue.addPassenger(time);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < int (60/periodicity[i]); ++j) {
			if (bus.getTime() <= time) {
				for (int k = 0; k < bus.getSeats(); ++k) {
					//passenger seats in the bus
					wait[count++] = bus.getTime()- queue.getTime();
					queue.cutPassenger();
					
				}
				bus.next();
			} else { 
			queue.addPassenger(time);
			time += periodicity[i];
			}
		}
	
	}


	
	//queue.show();
	//bus.show();
	int sum = 0;
	for (int i = 0; i < count; ++i)
		sum += wait[i];
	cout << "The average passenger's waiting time is " << sum/count << " min" << endl;
	return 0;
}