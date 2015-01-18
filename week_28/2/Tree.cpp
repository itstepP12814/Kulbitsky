#include "Tree.h"


void Tree::Add(string number, string value){
	if (!root) {
		root = new Item;
		root->key = number;
		root->value[root->current++] = value;
		current = root;
	} else {
		Item *current = root;
		Item *par = nullptr;
		while(current) {
			par = current;
			if(current->key == number){
				current->value[current->current++] = value;
				return;
			}
			if(number < current->key)
				current = current->left;
			else
				current = current->right;
		}
		
		if (number < par->key){
			par->left = new Item;
			par->left->parent = par;
			par->left->key = number;
			par->left->value[par->left->current++] = value;
		} else {
			par->right = new Item;
			par->right->parent = par;
			par->right->key = number;
			par->right->value[par->right->current++] = value;
		}
	
	}

}

void Add(Item *node, string value){
	node->value[node->current++] = value;
}

void Tree::Print(Item *root){
	Item *current = root;
	if (current) {
		Print(current->left);
		cout << current->key << endl;
		for (size_t i = 0; i < current->current; ++i)
			cout << current->value[i] << endl;
		cout << endl;
		Print(current->right);
	}

}

void Tree::Print(string n1, string n2){
	SetCurrentPosition(Search(n1));
	Item *end = Search(n2);
	while(current != end){
		PrintCurrentPosition();
		Next();
	}
	PrintCurrentPosition();

}

Item* Tree::Search(string number){
	Item *current = this->root;
	while(current && current->key != number){
		if(number < current->key) {
			if (!current->left) {
				return current;
				}
			current = current->left;
		}
		else {
			if (!current->right) {
				return current;
			}
			current = current->right;
		}
	}
	if (current) {
		return current;
	} /*else {
		cout << "The number was not found" << endl;
		return nullptr;
	}*/
	
}




void Tree::Next(){
	if (current->right) {
		current = current->right;
		while(current->left)
			current = current->left;
	} else {
		while(current != current->parent->left)
		current = current->parent;
		current = current->parent;
	}
}

void Tree::PrintCurrentPosition(){
	cout << current->key << endl;
		for (size_t i = 0; i < current->current; ++i)
			cout << current->value[i] << endl;
		cout << endl;
}
//???????????????????
