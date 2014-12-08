#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;
class Time{
private:
	int minutes;
	int hours;
public:
	Time();
	Time(unsigned hours, unsigned minutes);
	Time operator+(const Time& source) const;
	Time operator-(const Time& source) const;
	bool operator>(const Time& source) const;
	bool operator<(const Time& source) const;
	bool operator==(const Time& source) const;
	bool operator!=(const Time& source) const;
	bool operator>=(const Time& source) const;
	bool operator<=(const Time& source) const;
	friend ostream& operator<< (ostream& s, Time& t);
	void setTime();
	void print(/*American format*/);
};

#endif