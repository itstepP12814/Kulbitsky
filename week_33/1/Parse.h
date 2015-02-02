#pragma once
#include <string>
#include <limits>
using namespace std;
int parse(string s)
{
	const int factor = 10;
	int result = 0;
	int i = 0;
	int temp = 0;
	bool minus = false;
	if (s[i] == '-') 
	{
		minus = true;
		++i;
	}
	for (; i < s.length(); ++i) 
	{	
		if (s[i] < '0' || s[i] > '9')
			throw s[i];
		
		if (minus) 
		{	
			temp = result;
			result = result*factor - ((int)s[i] - 48);
			if (temp < result)
				throw "The value is under the MIN Integer value!";

		} else {
			temp = result;
			result = result*factor + ((int)s[i] - 48);
			if (temp > result)
				throw "The value is over the MAX Integer value!";
		}
	}
	
	return result;
}