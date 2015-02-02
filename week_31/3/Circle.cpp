#include "Circle.h"

Circle::Circle()
{
	cout << "Circle was created" << endl;
}

Circle::Circle(double x, double y, double r):PointXY(x, y)
{
	this->r = r;
	cout << "Circle was created" << endl;
}


Circle::~Circle()
{
	cout << "Circle was destroyed" << endl;
}
