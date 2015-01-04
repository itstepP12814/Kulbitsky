#include <iostream>
using namespace std;
 

struct Element
{
   char data;
   Element * Next;
};


class List
{
   Element * Head;
   Element * Tail;
   int Count;

public:
   List();
   ~List();
	
   void Add(char data);
   void Add(int index, char data);
   void Del();
   void Del(int index);
   void DelAll();
   void Print();
   int GetCount();
   int Find(char data);
};

List::List()
{
   Head = Tail = NULL;   
   Count = 0;
}

List::~List()
{
   DelAll();
}

int List::GetCount()
{
   return Count;
}

void List::Add(char data)
{
   Element * temp = new Element;
   temp->data = data;
   temp->Next = NULL;
   if(Head!=NULL){
		Tail->Next=temp;
		Tail = temp;
   }
   else{
	   Head=Tail=temp;
   }
   Count++;
}

void List::Add(int index, char data)
{
   if (0 == Count || index >= Count) {
	   Add(data);
	   Count++;
	   return;
   }
   if (0 == index) {
	   Element *temp = new Element;
	   temp->data = data;
	   temp->Next = Head;
	   Head = temp;
	   Count++;
	   return;
   } else {
	   Element *current = Head;
	   for (int i = 0; i < index - 1; ++i)
		   current = current->Next;
	   Element *temp = current->Next;
	   current->Next = new Element;
	   current->Next->data = data;
	   current->Next->Next = temp;
	   Count++;
	   return;
   }

}

void List::Del()
{
   Element * temp = Head;
   Head = Head->Next;
   delete temp;
   Count--;
}

void List::Del(int index)
{
	if (index >= Count) {
		Element *current = Head;
		while (current->Next->Next != Tail)
		   current = current->Next;
		delete current->Next;
		current->Next = NULL;
		Count--;
		return;
	}
	if (1 == Count || 0 == index) {
		Del();
		Count--;
		return;
	} else {
		Element *current = Head;
		for (int i = 0; i < index - 1; ++i)
		   current = current->Next;
		Element *temp = current->Next->Next;
		delete current->Next;
		current->Next = temp;
		Count--;
		return;
	}
	

}

void List::DelAll()
{
   while(Head != 0)
      Del();
   Count = 0;
}

void List::Print()
{
   Element * temp = Head;
   while(temp != 0)
   {
      cout << temp->data << " ";
      temp = temp->Next;
   }
   cout << "\n\n";
}

int List::Find(char data) {
	Element *temp = Head;
	int index = 0;
	while (temp != Tail->Next){
		if (temp->data == data) {
			return index;
		} else {
			index++;
			temp = temp->Next;
		}
	}
	return 0;

}

void main()
{
   List lst;
   char s[] = "Hello, World !!!\n";
   cout << s << "\n\n";
   int len = strlen(s);
   for(int i = 0; i < len; i++)
      lst.Add(s[i]);
  // lst.Print();
  // lst.Del();
   //lst.Del();
   //lst.Del();
   //lst.Add(1,'G');
   lst.Del(100);
   lst.Print();
   cout << lst.Find('H') << endl;
}

