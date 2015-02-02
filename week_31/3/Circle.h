#pragma once
#include "PointXY.h"
class Circle: public PointXY
{
protected:
	double r;
public:
	Circle();
	Circle(double x, double y, double r);
	~Circle();
};

