#pragma once
class Stack
{
	
	enum {EMPTY = -1, FULL = 20};

	
	char st[FULL + 1];

	
	int top;

public:
	
	Stack();

	
	void Push(char c); 

	
	char Pop();        

	
	void Clear();    

	
	bool IsEmpty();    

	bool IsFull();     

	
	int GetCount();    
};