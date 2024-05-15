//Kasidi Daugherty
//CIS 1140 Game Project
//May 14 2024

#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

Character ::Character(string name, int health, string weapon) : name(name), health(health), weapon(weapon) {}

void Character::takeDamage(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}

bool Character::alive() {
	return health > 0;
}