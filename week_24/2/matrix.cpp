#include "matrix.h"


void Matrix::resize(size_t ln, size_t col){
	for (int i = 0; i < lines; ++i)
		free(m[i]);
	free(m);
	m = (long**)malloc(ln*sizeof(long));
	for (int i = 0; i < ln; ++i)
		m[i] = (long*) malloc(col*sizeof(long));
	lines = ln;
	columns = col;

}


Matrix::Matrix(size_t a, size_t b){
	m = (long**)malloc(a*sizeof(long));
	for (int i = 0; i < a; ++i)
		m[i] = (long*)malloc(b*sizeof(long));
	lines = a;
	columns = b;
}



Matrix::Matrix(Matrix &source){
	m = (long**)malloc(source.lines*sizeof(long));
	for (int i = 0; i < source.lines; ++i)
		m[i] = (long*)malloc(source.columns*sizeof(long));
	for (int i = 0; i < source.lines; ++i) {
		for (int j = 0; j < source.columns; ++j) {
			m[i][j] = source.m[i][j];
		}
	}
	lines = source.lines;
	columns = source.columns;
}

Matrix::~Matrix(){
	for (int k = 0; k < lines; ++k)
		free(m[k]);
	free(m);

}

Matrix& Matrix::operator+=(const Matrix &source){
	if ((lines != source.lines)||(columns != source.columns)) {
	cerr << "ERROR! Different sizes of matrixes!\n";
	return *this;
	}
	for (int i = 0; i < source.lines; i++)
		for (int j = 0; j < source.columns; ++j)
			m[i][j] += source.m[i][j];
	return *this;

}

Matrix& Matrix::operator-=( Matrix &source){
	(*this) += source*(-1);
	return *this;
}

Matrix Matrix::operator+(const Matrix &source) {
	Matrix temp(*this);
	temp += source;
return temp;
}

Matrix Matrix::operator-(Matrix &source){
	Matrix temp(*this);
	temp -= source;
	return temp;
}


Matrix& Matrix::operator=( Matrix &source){
	if (this == &source)
		return *this;
	if (( lines != source.lines)||(columns != source.columns))
		this->resize(source.lines, source.columns);
	for (int i = 0; i < lines; ++i) {
		for (int j = 0; j < columns; ++j) {
			m[i][j] = source.m[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator * (const Matrix &source){
	if (columns != source.lines) {
		cerr << "ERROR! Size mismatch of the matrixes!\n";
		return *this;
	}
	Matrix temp(lines, source.columns);
	long sum;
	size_t k = 0;
	while (k < lines) {
		for (int i = 0; i < source.columns; ++i) {
			sum = 0;
			for (int j = 0; j < source.lines; ++j)
				sum += m[k][j] * source.m[j][i];
			temp.m[k][i] = sum;
		}
		++k;
	}
	return temp;
}

Matrix Matrix::operator * (long number){
	Matrix temp(*this);
	for (int i = 0; i < temp.lines; ++i)
		for (int j = 0; j < temp.columns; ++j)
			temp.m[i][j] *= number;
	return temp;
}


 Matrix operator * (long number, Matrix &source){
	 Matrix temp(source);
	for (int i = 0; i < temp.lines; ++i)
		for (int j = 0; j < temp.columns; ++j)
			temp.m[i][j] *= number;
	return temp;

}

 Matrix Matrix::T(){
	Matrix temp(columns, lines);
		for (int i = 0; i < lines; ++i)
			for (int j = 0; j  < columns; ++j)
				temp.m[j][i] = m[i][j];
		return temp;
 }