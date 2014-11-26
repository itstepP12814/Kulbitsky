#include <iostream>
#include "array.h"
using namespace std;

int main() {
	Array c(1);
	c[4] = 1;
	c[5] = 2;
	c.push(5,3);
	c.pushback(123);
	c.cut(c.size()-1);
	for  (int i = 0; i < c.size(); ++i)
		cout << c[i] << endl;
	Array a(c);
		for  (int i = 0; i < c.size(); ++i)
		cout << a[i] << endl;
	return 0;
}

