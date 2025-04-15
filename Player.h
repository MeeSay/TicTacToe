#pragma once
#include"Header.h"

class Player {
private: 
	char symbol;
	string name;

public:
	Player(char sym = 'X', string n = "Player X") : symbol(sym), name(n) {};

	char getSymbol() const { return symbol; };
	string getName() const { return name; };
};


