#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Item{
	public:
		string key;
		string value[10];
		size_t current;
		Item *left, *right, *parent;
		Item(){
			left = right = parent = nullptr;
			current = 0;
		}
		~Item(){
			delete left;
			delete right;
		}
	}; 
class Tree
{
private:
	
	
public:
	Item *root, *current;
	Tree():root(nullptr),current(root){}
	void Add(string number, string value);
	void Add(Item *node, string value);
	void Print(Item *node);
	void Print(string n1, string n2);
	void PrintAll(){Print(root);}
	Item* Search(string number);
	void Search(string number1, string number2);
	void Next();
	void PrintCurrentPosition();
	void SetCurrentPosition(Item *node){current = node;}
	
};

