#include "PointXY.h"


PointXY::PointXY()
{
	x = 0.0;
	y = 0.0;
	cout << "Point was created" << endl;
}

PointXY::PointXY(double x, double y)
{
	this->x = x;
	this->y = y;
	cout << "Point was created" << endl;
}


PointXY::~PointXY()
{
	cout << "Point was destroyed" << endl;
}
