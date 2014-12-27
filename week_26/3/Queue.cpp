#include "Queue.h"
void Queue::add(string name, int priority){
	if (begin == nullptr) {
		begin = new User;
		begin->name = name;
		begin->priority = priority;
		begin->next = nullptr;
		begin->prev = nullptr;
		
	} else {
		User *current = begin;
		while (current) {
			if (priority > current->priority && current->prev == nullptr) {
			current->prev = new User;
			current->prev->name = name;
			current->prev->priority = priority;
			current->prev->next = current;
			current->prev->prev = nullptr;
			begin = current->prev;
			break;
		} else {
			if (priority <= current->priority && current->next == nullptr) {
				current->next = new User;
				current->next->name = name;
				current->next->priority = priority;
				current->next->prev = current;
				current->next->next = nullptr;
				break;
			
			} else {
				if (priority > current->priority && priority <= current->prev->priority) {
					User *temp = current->prev;
					current->prev = new User;
					current->prev->name = name;
					current->prev->priority = priority;
					current->prev->next = current;
					current->prev->prev = temp;
					temp->next = current->prev;
					break;
				} else {current = current->next;}
			
			}
			
			}

		}
	
	
	}
		
	
	
}

void Queue::cut(){
	if (begin->next) {
	begin = begin->next;
	delete begin->prev;
	begin->prev = nullptr;
	} else {
		delete begin;
		begin = nullptr;
	}
}

void Queue::show(){
	User *current = begin;
	while(current != nullptr) {
		cout << current->name << endl << current->priority << endl << endl;
		current = current->next;
	}
}

void Queue::clear() {
	while (begin) 
		cut();
}

void Queue::addToStat(){
	struct tm *ptr;
    time_t lt;
    lt = time(NULL);
    ptr = localtime(&lt);

	if (!stat) {
		stat = new Stat;
		stat->time = asctime(ptr);
		//stat->time = "fssdf";
		stat->name = begin->name;
		stat->next = nullptr;
		tail = stat;
	} else {
		tail->next = new Stat;
		tail = tail->next;
		tail->next = nullptr;
		tail->name = begin->name;
		tail->time = asctime(ptr);
		//tail->time = "sdgb";
	}


}

void Queue::getStat(){
	Stat *current = stat;
	while (current != nullptr){
		cout << current->name << endl << current->time << endl;
		current = current->next;
	
	}


}

void Queue::print(){
	srand(time(NULL));
	if(begin) {
		cout << "Printing " << begin->name << "..." << endl;
		Sleep(rand()%5000);
		addToStat();
		cut();
		
	}


}