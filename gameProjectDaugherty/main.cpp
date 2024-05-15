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

	intro();

	for (int i = 0; i < 3; i++) {
		Room& currentRoom = *rooms[i];
		currentRoom.enterRoom();

		if (i == 0) {
			cout << "Uh Oh! " << goodall.name << " is coming!" << endl;
			battle(student, goodall);
		}
		else if (i == 1) {
			cout << "Oh No! " << underwood.name << "is heading towards you!" << endl;
			battle(student, underwood);
		}
		else {
			cout << "Not Again! " << goodall.name << " is running right at you!" << endl;
			battle(student, goodall);
		}

		if (!student.alive()) {
			
			cout << "You have been defeated by the evil teachers... " << "Game over!";
			cin.get();
			cin.ignore();
			return 0;
		}

	}

	cout << "Congratulations! You have escaped the school safely!" << endl;
	return 0;
}

void intro()
{
	cout << "Welcome to the game!" << endl << "----------------------------------------------------------" << endl;
	cout << "You got stuck in the school after school hours, when things start to get weird" << endl;
	cout << "The lights all start flashing.. and the TEACHERS TURN EVIL" << endl;
	cout << "Your goal is to get through each room and make it out of the school safely, without loosing all of your health by the evil teachers damage" << endl; 
	cout << "Good Luck!" << endl;
}

void battle(Character& user, Character& enemy)
{
	while (user.alive() && enemy.alive()) {
		cout << user.name << " attacks " << enemy.name << " with a " << user.weapon << "!" << endl;
		enemy.takeDamage(user.damage);
		cout << enemy.name << "'s health is now " << enemy.health << endl;

		if (enemy.alive()) {
			cout << enemy.name << " attacks " << user.name << " with a " << enemy.weapon << "!" << endl;
			user.takeDamage(enemy.damage);
			cout << user.name << "'s health is now " << user.health << endl;
		}
	}

	cout << endl;

	if (!enemy.alive()) {
		cout << enemy.name << " has been defeated!" << endl;
	}
	if (!user.alive()) {
		cout << user.name << " has been defeated!" << endl;
	}
}

int getDamage(string& weapon)
{
	if (weapon == "Chocolate Bar") {
		return 5;
	}
	else if (weapon == "Ruler") {
		return 10;
	}
	else if (weapon == "Laptop") {
		return 15;
	}

	return 1;
}
