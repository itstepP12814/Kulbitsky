#pragma once
#include "PointXY.h"
class Square: public PointXY
{
protected:
	double dx;
	double dy;
public:
	Square();
	Square(double x, double y, double dx, double dy);
	~Square();
};

