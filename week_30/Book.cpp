#include "Book.h"

void Book::add(string name, string owner, string phone, string address, string business){
	if (!begin) {
		begin = new Item;
		begin->name = name;
		begin->owner = owner;
		begin->phone = phone;
		begin->address = address;
		begin->business = business;
		begin->next = nullptr;
		begin->previous = nullptr;
		end = begin;
	} else {
		end->next = new Item;
		end->next->previous = end;
		end = end->next;
		end->next = nullptr;
		end->name = name;
		end->owner = owner;
		end->phone = phone;
		end->address = address;
		end->business = business;
	}
}

void Book::add(Item *source){
	if (!begin) {
		begin = source;
		end = begin;
	} else {
		end->next = source;
		source->previous = end;
		end = source;
	}

}


void Book::printAll(){
	Item *current = begin;
	while (current){
		printCurrent(current);
		current = current->next;
	}
}

void Book::loadFromFile(string source){
	ifstream inputFile(source);
	if (!inputFile)
   {
      cout << "Cannot open file!" << endl;
      return;
   }

	char BUFER[1024];
	while (!inputFile.eof()){
		inputFile.getline(BUFER,1023,'}');
		if (strlen(BUFER) > 5)
			add(parse(BUFER));
	}
	inputFile.close();
}

void Book::saveToFile(string destination){
	ofstream out(destination);
	if (!out) {
		cout << "Cannot open file!" << endl;
		return;
	}
	Item *current = begin;
	out << "[ \n";
	while (current->next) {
		out << "\t{\n\t\tname: \"" << current->name << "\", \n\t\towner: \"" << current->owner 
			<<"\", \n\t\tphone: \"" << current->phone << "\", \n\t\taddress: \"" << current->address
			<<"\", \n\t\tbusiness: \"" << current->business << "\" \n\t},\n ";
		current = current->next;
	}
	out << "\t{\n\t\tname: \"" << current->name << "\", \n\t\towner: \"" << current->owner 
			<<"\", \n\t\tphone: \"" << current->phone << "\", \n\t\taddress: \"" << current->address
			<<"\", \n\t\tbusiness: \"" << current->business << "\" \n\t}\n ";
	out << "]";
	out.close();
}


Item* parse(char* source) {
	string name;
	vector<string> res;
	Item* temp = new Item;
	int k = 0;
	while (k < strlen(source)) {
		if (source[k] == '\"') {
			k++;
			while (source[k] != '\"') {
				name.push_back(source[k]);
				k++;
			}
			
			res.push_back(name);
			name.clear();
		} 
		k++;
	
	}
	temp->name = res[0];
	temp->owner = res[1];
	temp->phone = res[2];
	temp->address = res[3];
	temp->business = res[4];
	temp->next = temp->previous = nullptr;
	return temp;

}

void Book::printCurrent(Item *current){
	cout << "Name: " << current->name << endl
			<< "Owner: " << current->owner << endl
			<< "Phone: " << current->phone << endl
			<< "Address: " << current->address << endl
			<< "Business: " << current->business << endl
			<< endl;

}

void Book::searchByName(string name) {
	Item *current = begin;
	while (current) {
		if (current->name == name)
			printCurrent(current);
		current = current->next;
	}
}

void Book::searchByOwner(string owner) {
	Item *current = begin;
	while (current) {
		if (current->owner == owner)
			printCurrent(current);
		current = current->next;
	}

}

void Book::searchByPhone(string phone) {
	Item *current = begin;
	while (current) {
		if (current->phone == phone)
			printCurrent(current);
		current = current->next;
	}

}

void Book::searchByBusiness(string business) {
	Item *current = begin;
	while (current) {
		if (current->business == business)
			printCurrent(current);
		current = current->next;
	}
}