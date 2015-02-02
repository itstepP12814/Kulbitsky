#include "Square.h"

Square::Square()
{
	cout << "Square was created" << endl;
}

Square::Square(double x, double y, double dx, double dy):PointXY(x, y)
{
	this->dx = dx;
	this->dy = dy;
	cout << "Square was created" << endl;
}


Square::~Square(void)
{
	cout << "Square was destroyed" << endl;
}
