#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class Array{
private:
	static const size_t N = 5;
	T *a;
	size_t size_;
	size_t index_edge;
	size_t grow_;
public:
	Array() {
		a = new T[N];
		size_ = N;
		index_edge = 0;
		grow_ = 1;
	}

	Array(size_t size) {
		a = new T[size];
		size_ = size;
		index_edge = 0;
		grow_ = 1;
	}
	~Array() {
		delete []a;
		size_ = 0;
		index_edge = 0;
	}

	T& operator[](size_t i) {
		index_edge = i;
		return a[i];
	}

	size_t GetSize(){return size_;}

	void SetSize(size_t size, size_t grow = 1){
		if (this->size_ > size) {
			T *temp = a;
			a = new T[size];
			for (size_t i = 0; i < size; ++i)
				a[i] = temp[i];
			delete []temp;
			this->size_ = size;
			grow_ = grow;
			
		}


		while (this->size_ <= size) {
			T *temp = a;
			this->size_ += grow;
			a = new T[this->size_];
			for (size_t i = 0; i < this->size_; ++i)
				a[i] = temp[i];
			delete []temp;
			grow_ = grow;
		}
	
		

	}

	size_t GetUpperBound(){return index_edge;} ///??????????????????????

	bool IsEmpty(){return index_edge;}

	void FreeExtra() {
			T *temp = a;
			a = new T[index_edge + 1];
			this->size_ = index_edge + 1;
			for (size_t i = 0; i < this->size_; ++i)
				a[i] = temp[i];
			delete []temp;
	}

	void RemoveAll(){
		delete []a;
		size_ = 0;
		index_edge = 0;
	
	}

	T GetAt(size_t i) {
		index_edge = i;
		return a[i];
	}

	void SetAt(size_t index, T value) {
		if (index < size_) {
			a[index] = value;
		} else {
			cout << "ERROR! Indexation over the edge of array\n";
			return;
		}
	}

	void Add(T value) {
		if (index_edge >= size_) {
			SetSize(size_ + grow_, grow_);
		}
		a[index_edge++] = value;
	}

	void Append(Array<T> &source){
		SetSize(size_ + source.size_, grow_);
		size_t j = index_edge + 1;
		for (size_t i = index_edge + 1; i <= index_edge + source.GetSize(); ++i){
			a[i] = source.a[i-j];
		}
	}

	Array<T> & operator=(Array<T> &source){
		if (this == &source)
			return *this;
		if (source.size_ > size_)
			SetSize(source.size_, grow_);
		for (size_t i = 0; i < size_; ++i)
			a[i] = source.a[i];
		index_edge = source.index_edge;
		return *this;
	}

	T* GetData(){
		return a;
	}

	void InsertAt(size_t index, T value){
		if (index_edge + 1  >= size_)
			SetSize(size_);
		for (size_t i = GetSize() - 1; i > index; --i)
			a[i] = a[i-1];
		a[index] = value;
		size_++;
	}

	void RemoveAt(size_t index){
		for (size_t i = index; i < size_-1; ++i)
			a[i] = a[i+1];
		SetSize(size_- 1);
	}

};

#endif