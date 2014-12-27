#include "game.h"
Game::~Game(){}

void Game::add(char ch) {
	if (!begin) {
		begin = new Item;
		begin->next = begin;
		begin->ch = ch;
		current = begin;
	} else {
		current->next = new Item;
		current->next->next = begin;
		current->next->ch = ch;
		current = current->next;
	}

}
