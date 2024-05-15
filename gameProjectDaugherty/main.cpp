//Kasidi Daugherty
//CIS 1140 Game Project
//May 14 2024

#include <iostream>
#include <cstdlib>
#include "LabRoom.h"
#include "Hallway.h"
#include "Mac.h"
#include "Student.h"
#include "Teacher.h"

void intro();
void showRoomInfo(Room& room);
void battle(Character& user, Character& enemy);
int getDamage(string& weapon);

int main() {
	LabRoom lab;
	Hallway hallway;
	Mac mac;

	Room* rooms[3] = { &lab, &hallway, &mac };

	Student student;
	Teacher goodall("Evil teacher, named Mrs. Goodall", 50, "Chocolate Bar");
	Teacher underwood("Evil teacher, named Mr. Underwood", 50, "Ruler");

}

void intro()
{
}

void showRoomInfo(Room& room)
{
}

void battle(Character& user, Character& enemy)
{
}

int getDamage(string& weapon)
{
	return 0;
}
