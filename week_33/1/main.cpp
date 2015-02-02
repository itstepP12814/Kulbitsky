#include <string>
#include <iostream>
#include "Parse.h"
using namespace std;


int main()
{	
	try 
	{
		int a;
		string s;
		cout << "Enter the string:" << endl;
		cin >> s;
		a = parse(s);
		cout << a << endl;
	}
	catch (char *s)
	{
		cout << s << endl;
	}
	catch (char c)
	{
		cout << "Unexpected symbol: " << c << endl;
	}
	
	return 0;
}