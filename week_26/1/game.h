#ifndef GAME_H
#define GAME_H
#include <stdlib.h>
#include <time.h>

class Game{
private:
	struct Item{
		char ch;
		Item *next;
	};
	Item *begin;
	Item *current;
	int state;
public:
	
	Game():begin(NULL), current(NULL), state(0){}
	~Game();
	void add(char ch);
	char get(){return current->ch;}
	void next(){current = current->next;}
	int getState() const {return state;}
	void setState(int a) {state = a;}
	
};

#endif