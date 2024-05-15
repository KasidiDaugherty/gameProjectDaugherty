//Kasidi Daugherty
//CIS 1140 Game Project
//May 14 2024

#include <iostream>
#include <string>
#include "Mac.h"

using namespace std;

Mac ::Mac() : Room("Mac", "You are in the Mac, The room smells like buring chicken and the tables are all scattered") {}

void Mac::enterRoom() {
	cout << endl << name << endl;
	cout << info << endl;
}