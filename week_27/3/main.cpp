#include "array.h"
#include <iostream>

using namespace std;

int main() {
	Array<int> a;
	Array<int> b;
	//cout << a.GetSize() << endl;
	for (int i = 0; i < a.GetSize(); ++i)
		a[i] = 100 + i;
	cout << a.GetSize() << endl;
	a.RemoveAt(2);
	//for (int i = 0; i < 4; ++i)
	//	b[i] = 10 + i;
	//b = a;
	for (int i = 0; i < a.GetSize(); ++i)
		cout << a[i] << endl;
	//cout << a[100] << endl;
	return 0;
}