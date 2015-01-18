#include "tree.h"

void Tree::Add(string name, long number){
	Item *temp = new Item(name, number);

	if (!root_for_number) {
		root_for_number = temp;
		cur = root_for_number;
	} else {

		/// Adding to the tree by NUMBER
		Item *current = root_for_number;
		Item *par = nullptr;
		while(current) {
			par = current;
			
			if(number < current->number)
				current = current->left_by_number;
			else
				current = current->right_by_number;
		}
		
		if (number < par->number){
			par->left_by_number = temp;
			temp->parent_by_number = par;
		} else {
			par->right_by_number = temp;
			temp->parent_by_number = par;
		}
	
	}
	/// End of edding to the tree by NUMBER
	//-----------------------------
	/// Adding to the tree by NAME
	if (!root_for_name) {
		root_for_name = temp;
		
	} else {
		Item *current = root_for_name;
		Item *par = nullptr;
		while(current) {
			par = current;
			
			if(name < current->name)
				current = current->left_by_name;
			else
				current = current->right_by_name;
		}
		
		if (name < par->name){
			par->left_by_name = temp;
			temp->parent_by_name = par;
		} else {
			par->right_by_name = temp;
			temp->parent_by_name = par;
		}
	}
		/// End of edding to the tree by NAME

}


void Tree::PrintByName(Item *node){
	Item *current = node;
	if (current) {
		PrintByName(current->left_by_name);
		cout << current->name << endl;
		cout << current->number << endl << endl;
		PrintByName(current->right_by_name);
	}
}


void Tree::PrintByNumber(Item *node){
	Item *current = node;
	if (current) {
		PrintByNumber(current->left_by_number);
		cout << current->number << endl;
		cout << current->name << endl << endl;
		PrintByNumber(current->right_by_number);
	}
}

void Tree::PrintToFile(Item *node, ofstream &s){
	Item *current = node;
	if (current) {
		PrintToFile(current->left_by_number, s);
		s << current->number << endl;
		s << current->name << endl << endl;
		PrintToFile(current->right_by_number, s);
	}
}




Item* Tree::SearchByName(string name) {
	Item *current = this->root_for_name;
	while(current && current->name != name){
		if(name < current->name) {
			if (!current->left_by_name) {
				if (current->name != name)
					cout << "The name was not found." << endl;
					cur = current;
					return current;
				}
			current = current->left_by_name;
		}
		else {
			if (!current->right_by_name) {
				if (current->name != name)
					cout << "The name was not found." << endl;
					cur = current;
					return current;
			}
			current = current->right_by_name;
		}
	}
	if (current) {
		cur = current;
		return current;
	} 
}


Item* Tree::SearchByNumber(long number) {
	Item *current = this->root_for_number;
	while(current && current->number != number){
		if(number < current->number) {
			if (!current->left_by_number) {
				if (current->number != number) {
					cout << "The number was not found." << endl;
					cur = current;
					return current;
				}
				}
			current = current->left_by_number;
		}
		else {
			if (!current->right_by_number) {
				if (current->number != number) {
					cout << "The number was not found." << endl;
					cur = current;
					return current;
				}
			}
			current = current->right_by_number;
		}
	}
	if (current) {
		cur = current;
		return current;
	} 
}

void Tree::Del(Item *node){
	Item *parent = node->parent_by_number;
	Item *left = node->left_by_number;
	Item *right = node->right_by_number;
	Item *adder = nullptr;
	if (right) {
		if (left) {
			Item *current = right;
			while (current->left_by_number){
				current = current->left_by_number;
			}
			current->left_by_number = left;
			left->parent_by_number = current;
		}
		adder = right;
	} else {
		if (left) {
			adder = left;
		} 
	}
	if (node != root_for_number) {
		if (node == parent->left_by_number) 
			parent->left_by_number = adder;
		else 
			parent->right_by_number = adder;
		if (adder)
			adder->parent_by_number = parent;
	} else {
		root_for_number = adder;
		root_for_number->parent_by_number = nullptr;
	}
	
	
	////////////////////
	parent = node->parent_by_name;
	left = node->left_by_name;
	right = node->right_by_name;
	adder = nullptr;
	if (right) {
		if (left) {
			Item *current = right;
			while (current->left_by_name){
				current = current->left_by_name;
			}
			current->left_by_name = left;
			left->parent_by_name = current;
		}
		adder = right;
	} else {
		if (left) {
			adder = left;
		} 
	}
	if (node != root_for_name) {
		if (node == parent->left_by_name) 
			parent->left_by_name = adder;
		else 
			parent->right_by_name = adder;
		if (adder)
			adder->parent_by_name = parent;
	} else {
			
			root_for_name = adder;
			root_for_name->parent_by_name = nullptr;
		
	}
	delete node;
}

void Tree::NextByName(){
	if (cur->right_by_name) {
		cur = cur->right_by_name;
		while(cur->left_by_name)
			cur = cur->left_by_name;
	} else {
		while(cur != cur->parent_by_name->left_by_name)
			cur = cur->parent_by_name;
		cur = cur->parent_by_name;
	}
}

void Tree::NextByNumber(){
	if (cur->right_by_number) {
		cur = cur->right_by_number;
		while(cur->left_by_number)
			cur = cur->left_by_number;
	} else {
		while(cur != cur->parent_by_number->left_by_number)
			cur = cur->parent_by_number;
		cur = cur->parent_by_number;
	}

}

void Tree::SearchDiapasone(string s1, string s2){
	SearchByName(s1);
	do {
		cout << cur->name << endl;
		cout << cur->number << endl;
		this->NextByName();
	}	while(cur->name < s2);

}


void Tree::SearchDiapasone(long n1, long n2){
	SearchByNumber(n1);
	do {
		cout << cur->number << endl;
		cout << cur->name << endl;
		this->NextByNumber();
	}	while(cur->number < n2);


}


void Tree::SaveToFile(string file){
	ofstream f(file);
	PrintToFile(this->root_for_number, f);
	f.close();
}

void Tree::ReadFromFile(string file){
	ifstream f(file);
	string name;
	long number;
	while(!f.eof()){
		f >> number;
		f >> name;
		this->Add(name, number);
	}
	f.close();
}

void Tree::AddCurrentToFile(ofstream &f){
	f << cur->number << endl;
	f << cur->name << endl;
}