#include "array.h"

Array::Array() {
	_size = 2;
	arr = (long*)malloc(_size*sizeof(long));
	for (int i = 0; i < _size; ++i)
		arr[i] = 0;
}

Array::Array(size_t size){
	_size = size;
	arr = (long*)malloc(_size*sizeof(long));
	for (int i = 0; i < _size; ++i)
		arr[i] = 0;
}

Array::Array(const Array& source){
	_size = 0;
	arr = (long*)malloc(_size*sizeof(long));
	this->operator=(source);
}

Array::~Array() {
	_size = 0;
	free(arr);
}

long& Array::operator[](int index){
	size_t temp = _size;
	if (index+1 > _size) {
		_size = index+1;
	arr = (long*)realloc(arr, _size*sizeof(long));
	for(int i = temp; i < _size; ++i)
		arr[i] = 0;
	}
	return arr[index];
	
}
Array& Array::operator=(const Array &source){
	if (_size < source._size) {
		arr = (long*)realloc(arr, (source._size)*sizeof(long));
		_size = source._size;
	}
	for (int i = 0; i < _size; ++i)
		arr[i] = source.arr[i];
	return *this;
}

Array Array::operator+(const Array &source){
	Array temp;
	temp._size = _size + source._size;
	temp.arr = (long*) realloc(temp.arr,(temp._size)*sizeof(long));
	for (int i = 0; i < _size; ++i)
		temp.arr[i] = arr[i];
	for (int i = _size; i < temp._size; ++i)
		temp.arr[i] = source.arr[i-_size];
	return temp;
}

void Array::pushback(long value){
	this->operator[](_size) = value;
}

void Array::push(int index, long value){
for(int i = _size; i > index; --i)
	this->operator[](i) = this->operator[](i-1);
arr[index] = value;

}

void Array::cut(int index){
	for(int i = index; i < _size-1; ++i)
		arr[i] = arr[i+1];
	--_size;
	arr = (long*)realloc(arr,_size*sizeof(long));
}

void Array::resize(size_t size){
	_size = size;
	arr = (long*)realloc(arr, _size*sizeof(long));

}
size_t Array::size(){
	return _size;
}