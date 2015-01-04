#include <iostream>

using namespace std;


template <class T> 
class Queue {
private:
	T junk;
	struct Item {
		T data;
		Item *next;
		Item *prev;
	
	};
	Item *begin, *tail;
public:
	Queue():begin(nullptr), tail(nullptr){}
	

	void Add(T data){
		if (begin == nullptr) {
			begin = new Item;
			begin->data = data;
			begin->next = nullptr;
			begin->prev = nullptr;
			tail = begin;
		} else {
			tail->next = new Item;
			tail->next->data = data;
			tail->next->next = nullptr;
			tail->next->prev = tail;
			tail = tail->next;
		}
	
	}

	T Get(){
		if (begin)
		return begin->data;
		else return junk;
	}
	void Dell(){ 
		if (begin->next) {
		begin = begin->next;
		delete begin->prev;
		begin->prev = nullptr;
		}
	}
	void DellAll() {
		while(begin)
			Dell();
	}
	~Queue(){DellAll();}
};


int main() {
	Queue<int> q;
	for (int i = 0; i < 10; i ++)
		q.Add(i);
	for (int i = 0; i < 10; i ++) {
		cout << q.Get();
		q.Dell();
	}
	return 0;
}
