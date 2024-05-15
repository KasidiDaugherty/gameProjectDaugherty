//Kasidi Daugherty
//CIS 1140 Game Project
//May 14 2024

#include <iostream>
#include <string>
#include "Hallway.h"

using namespace std;

Hallway::Hallway() : Room("Hallway", "You are in the long main hallway of MVCTC, but the lights are low and there are creaky noises coming from all around you") {}

void Hallway::enterRoom() {
	cout << endl << name << endl;
	cout << info << endl;
}