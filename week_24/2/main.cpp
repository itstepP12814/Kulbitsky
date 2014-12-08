#include "matrix.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;


int main() {
	srand(time(NULL));
	Matrix A(3,3);
	for (int i = 0; i < A.getLines(); ++i){
		for (int j = 0; j < A.getColumns(); ++j) {
			A(i,j) = rand()%3;
			cout << A(i,j) << " ";
		}
	cout << endl;
	}
	cout << endl;
	Matrix B(7,3);
	for (int i = 0; i < B.getLines(); ++i){
		for (int j = 0; j < B.getColumns(); ++j) {
			B(i,j) = rand()%3;
			cout << B(i,j) << " ";
		}
	cout << endl;
	}
cout << endl;
	Matrix C;
	C = B.T();
	for (int i = 0; i < C.getLines(); ++i){
	for (int j = 0; j < C.getColumns(); ++j) {
		cout << C(i,j) << " ";
		}
	cout << endl;
	}
	return 0;
}