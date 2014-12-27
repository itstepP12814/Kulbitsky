#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;
class Queue{
private:

	struct User{
		string name;
		int priority;
		User *next;
		User *prev;
	};
	struct Stat{
	string time;
	string name;
	Stat *next;
	};
	User *begin;
	Stat *stat;
	Stat *tail;
	void addToStat();
public:
	Queue():begin(nullptr),stat(nullptr),tail(nullptr){}
	void add(string name, int priority);
	void cut();
	void show();
	void clear();
	void getStat();
	void print();
};

#endif