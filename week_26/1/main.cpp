#include "game.h"
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	srand(time(NULL));
	Game drum[3];
	for (int i = 0; i < 3; ++i){
		drum[i].add(11);
		drum[i].add(2);
		drum[i].add(3);
		drum[i].add(4);
		drum[i].add(5);
		drum[i].add(6);
	}
	char c;
	//c = getc(stdin);
	do {
	drum[0].setState(1);
	drum[1].setState(1);
	drum[2].setState(1);
	int count = 3;
	while (count)
	{

		for (int j = 0; j < 3; ++j) {
			if(drum[j].getState()) {
				if (drum[j].getState() == rand()%2000) {
					drum[j].setState(0);
					count--;
				} else {
					drum[j].next();
				}
			
			}
		}

		printf("\r%c|%c|%c",drum[0].get(),drum[1].get(),drum[2].get());
		
		
	}
	//printf("\n");
	if (drum[0].get() == drum[1].get() && drum[0].get()== drum[2].get() && drum[1].get()==drum[2].get())
		printf("\nYOU WIN!\nPress any key to play again\nPress 1 to exit\n");
	c = getch();
	} while (c != '1');
	return 0;
}