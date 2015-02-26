#ifndef FIGURE_H
#define FIGURE_H
#include <math.h>
#include <list>
#define PI 3.14159265358979323846
using namespace std;

class Figure{
public:
	virtual double square(){ return 0.0; }
	virtual void add(Figure*){}
	virtual ~Figure(){}
};

class Composition : public Figure{
protected:
	list<Figure*> components;
public:
	double square(){
		double temp = 0.0;
		for (auto x : components){
			temp += x->square();
		}
		return temp;
	}

	virtual void add(Figure *f){ components.push_back(f); }

};

class Angle{
private:
	double degree;
	double minutes;
	double seconds;
public:
	Angle() :degree(0.0), minutes(0.0), seconds(0.0){}
	Angle(double _degree) :degree(_degree), minutes(0.0), seconds(0.0){}
	Angle(double _degree, double _minutes) : degree(_degree), minutes(_minutes), seconds(0.0){}
	Angle(double _degree, double _minutes, double _seconds) : degree(_degree), minutes(_minutes), seconds(_seconds){}
	Angle(Angle &source){
		degree = source.degree;
		minutes = source.minutes;
		seconds = source.seconds;
	}
	double getAngle(){ return degree + minutes / 60.0 + seconds / 3600.0; }
};

class Circle : public Figure{
protected:
	double radius;
public:
	Circle() :radius(0.0){}
	Circle(double _radius) :radius(_radius){}
	Circle(Circle &source){ radius = source.radius; }
	double square(){ return PI * radius * radius; }
};



class Square : public Figure{
protected:
	double side;
public:
	Square() :side(0.0){}
	Square(double _side) :side(_side){}
	Square(Square &source){ side = source.side; }
	double square(){ return side * side; }
};

class Triangle : public Figure{
protected:
	double a, b, c;
public:
	Triangle() :a(0.0), b(0.0), c(0.0){}
	Triangle(double _a, double _b, Angle &angle):a(_a), b(_b){
		c = sqrt(a * a + b * b - 2.0 * a * b * cos(angle.getAngle() * PI / 180.0));
	}
	Triangle(double _a, double _b, double _c) :a(_a), b(_b), c(_c){}
	Triangle(Triangle &source){
		a = source.a;
		b = source.b;
		c = source.c;
	}
	double  square(){
		double p = (a + b + c) / 2.0;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
};

class Parallelogram : public Figure{
protected:
	double a;
	double b;
	Angle *angle;
public:
	Parallelogram() :a(0.0), b(0.0), angle(nullptr){}
	Parallelogram(double _a, double _b, Angle &_angle) :a(_a), b(_b){
		angle = new Angle(_angle);
	}
	Parallelogram(Parallelogram &source){
		a = source.a;
		b = source.b;
		angle = new Angle(*source.angle);
	}
	~Parallelogram(){
		if (angle) {
			delete angle;
			angle = nullptr;
		}
	}
	double square(){
		return a * b * sin(angle->getAngle());
	}
};

class Rectangle : public Figure{
protected:
	double a, b;
public:
	Rectangle() :a(0.0), b(0.0){}
	Rectangle(double _a, double _b) :a(_a), b(_b){}
	Rectangle(Rectangle &source){
		a = source.a;
		b = source.b;
	}
	double square(){ return a * b; }
};



#endif