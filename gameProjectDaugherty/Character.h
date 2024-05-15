//Kasidi Daugherty
//CIS 1140 Game Project
//May 14 2024

#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
using namespace std;

class Character {
private:
	string name;
	int health;
	string weapon;
	int damage;
public:
	Character(string name, int health, string weapon);

	void damage(int damage);
	bool alive();
	
};


#endif CHARACTER_H