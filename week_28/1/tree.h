#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Item{
	public:
		string name;
		long number;
		Item *left_by_number, *right_by_number, *parent_by_number;
		Item *left_by_name, *right_by_name, *parent_by_name;
		Item(){
			left_by_number = right_by_number = parent_by_number = nullptr;
			left_by_name = right_by_name = parent_by_name = nullptr;
		}
		Item(string name, long number){
			this->name = name;
			this->number = number;
			left_by_number = right_by_number = parent_by_number = nullptr;
			left_by_name = right_by_name = parent_by_name = nullptr;
		}
		~Item(){
			left_by_number = nullptr;
			right_by_number = nullptr;
			left_by_name = nullptr;
			right_by_name = nullptr;
			parent_by_number = nullptr;
			parent_by_name = nullptr;
		}
	}; 

class Tree{
private:
	void PrintByName(Item *node);
	void PrintByNumber(Item *node);
	void PrintToFile(Item *node, ofstream &s);
public:
	Item *root_for_number, *root_for_name, *cur;
	Tree():root_for_number(nullptr),root_for_name(nullptr),cur(nullptr){}
	void Add(string name, long number);
	void PrintByNames(){PrintByName(root_for_name);}
	void PrintByNumbers(){PrintByNumber(root_for_number);}
	Item* SearchByName(string name);
	Item* SearchByNumber(long number);
	void Del(Item *node);
	void NextByName();
	void NextByNumber();
	void ModifyCurrent(string name) {cur->name = name;}
	void ModifyCurrent(long number) {cur->number = number;}
	void ModifyCurrent(string name, long number) {cur->name = name; cur->number = number;}
	void SearchDiapasone(string s1, string s2);
	void SearchDiapasone(long n1, long n2);
	void SaveToFile(string file);
	void ReadFromFile(string file);
	void AddCurrentToFile(ofstream &f);
};

