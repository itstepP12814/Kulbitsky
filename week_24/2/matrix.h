#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>
#include <iostream>
using namespace std;
using namespace std;
class Matrix{
private:
	long **m;
	int lines;
	int columns;
	
public:
	Matrix(): m(NULL), lines(0), columns(0){}
	Matrix(size_t a, size_t b);
	Matrix(Matrix &source);
	~Matrix();
	size_t getLines() const {return lines;}
	size_t getColumns() const {return columns;}
	long& operator()(size_t i, size_t j) {return m[i][j];}
	Matrix& operator+=(const Matrix &source);
	Matrix& operator-=( Matrix &source);
	Matrix operator+(const Matrix &source);
	Matrix operator-( Matrix &source);
	Matrix& operator=(Matrix &source);
	Matrix operator * (const Matrix &source);
	Matrix operator * (long number);
	friend Matrix operator * (long number, Matrix &source);
	Matrix T();
	void resize(size_t ln, size_t col);
};

#endif