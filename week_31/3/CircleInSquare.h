#pragma once
#include "Square.h"
#include "Circle.h"

class CircleInSquare:public Square, public Circle
{
protected:

public:
	CircleInSquare();
	CircleInSquare(double x, double y, double dx, double dy, double r);
	~CircleInSquare();
};

