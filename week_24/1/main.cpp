#include "time.h"

int main() {
	Time a(10,15);
	Time b(10,15);
	Time c,d;
	if (a==b) cout << "GOOD\n";
	c.setTime();
	cout << c << endl << d << endl;
	c.print();
	return 0;
}