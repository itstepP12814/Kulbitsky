#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>
#include <iostream>
using namespace std;
class Array {
private:
	long *arr;
	size_t _size;
public:
	Array();
	Array(size_t size);
	Array(const Array& source);
	~Array();
	long& operator[](int index);
	Array& operator=(const Array &source);
	Array operator+(const Array &source);
	void pushback(long value);// adds the value to the end of array
	void push(int index, long value);// adds the value to the INDEX's position
	void cut(int index);// cuts the index's element
	void resize(size_t size);// sets the new size of array
	size_t size();// returns the size of array
};

#endif