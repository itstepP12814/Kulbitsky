#include "CircleInSquare.h"

CircleInSquare::CircleInSquare()
{
	cout << "Circle in square was created" << endl;
}

CircleInSquare::CircleInSquare(double x, double y, double dx, double dy, double r):
Square(x, y, dx, dy), Circle((x + dx)/2.0, (y - dy)/2.0, r)
{
	cout << "Circle in square was created" << endl;
}


CircleInSquare::~CircleInSquare()
{
	cout << "Circle in square was destroyed" << endl;
}
