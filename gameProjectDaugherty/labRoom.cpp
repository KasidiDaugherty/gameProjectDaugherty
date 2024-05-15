//Kasidi Daugherty
//CIS 1140 Game Project
//May 14 2024

#include <iostream>
#include <string>
#include "labRoom.h"

using namespace std;

LabRoom::LabRoom() : Room("Lab Room", "You are locked in the lab room, the computers are flashing and the chairs are all knocked over") {}

void LabRoom::enterRoom() {
	cout << endl << name << endl;
	cout << info << " ";
}
