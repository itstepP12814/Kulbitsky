#include <iostream>
#include <string.h>
#include <time.h>
#include "MyStack.h"
using namespace std;

int main()
{
	try {
		srand(time(0));
		Stack ST;
		char c;
	
		while(!ST.IsFull()){
			c=rand()%4+2;
			ST.Push(c);
		}

		c=rand()%4+2;
		ST.Push(c);

		while(c=ST.Pop()){
       			cout<<c<<" ";
		}
		cout<<"\n\n";
	}
	catch (char *s) {
		cout << s << endl;
	}
	return 0;

}

