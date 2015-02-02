#pragma once

#include "Figura.h"

class Object 
{
private:
	Figura *obj;
	int count;
public:
	Object()
	{
		obj = nullptr;
		count = 0;
	}

	void CreateObject(int ct)
	{
		if(0 == ct) exit(0);
		count = ct;
		obj = new Figura[count];
		if (!obj) exit(0);
		int count_of_angels;
		int color;
		for (int i = 0; i < count; ++i)
		{	
			cout << "Enter the number of angels: ";
			cin >> count_of_angels;
			cout << "Enter the color of figure: ";
			cin >> color;
			obj[i].CreateFigura(color, count_of_angels);
		}
	}

	void ShowObject()
	{
		for(int i = 0; i < count; ++i)
			obj[i].ShowFigura();
	}

	~Object()
	{
		if (obj != nullptr)
			delete []obj;
	}

};