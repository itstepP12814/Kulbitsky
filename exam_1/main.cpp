#include <iostream>
#include "Figure.h"
using namespace std;

int main(){
	
	Figure *a = new Circle(3.5);
	Figure *b = new Square(4.7);
	Angle an(30.0);
	Figure *d = new Triangle(5.0, 2.0, an);
	Composition *c = new Composition;
	c->add(a);
	c->add(b);
	c->add(d);
	cout << c->square() << endl;
	return 0;
}