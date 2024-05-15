//Kasidi Daugherty
//CIS 1140 Game Project
//May 14 2024

#include <iostream>
#include <random>
#include "LabRoom.h"
#include "Hallway.h"
#include "Mac.h"
#include "Student.h"
#include "Teacher.h"

void intro();
void battle(Character& user, Character& enemy);
int getDamage(string& weapon);
void displayOptions();
void displayBattleOptions();

int main() {
	LabRoom lab;
	Hallway hallway;
	Mac mac;

	Room* rooms[3] = { &lab, &hallway, &mac };

	Student student;
	Teacher goodall("Evil teacher, named Mrs. Goodall", 50, "Chocolate Bar");
	Teacher underwood("Evil teacher, named Mr. Underwood", 50, "Ruler");

	intro();


	int currentRoomIndex = 0;

	while (student.alive() && currentRoomIndex < 3) {
		currentRoomIndex++;
		Room& currentRoom = *rooms[currentRoomIndex];
		currentRoom.enterRoom();

		displayOptions();
		int choice;
		cin >> choice;

		switch (choice) {
			case 1: {
				cout << "You decided to stay in the room." << endl;
				cout << "Uh Oh! " << goodall.name << " was hiding in this room!" << endl;
				battle(student, goodall);
				break;
			}
			case 2: {
				cout << "You chose to go to the next room" << endl;
				currentRoomIndex++;
				break;
			}
			case 3: {
				if (currentRoomIndex == 0) {
					cout << "Oh No! " << underwood.name << " is heading towards you!" << endl;
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
				break;
			}
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

	displayBattleOptions();

	int potion = 1;
	int choice;
	cin >> choice;

	switch (choice) {
		case 1: {
			cout << user.name << " attacks " << enemy.name << " with a " << user.weapon << "!" << endl;
			enemy.takeDamage(user.damage);
			cout << enemy.name << "'s health is now " << enemy.health << endl;
			break;
		}
		case 2: {
			cout << user.name << " is defending the next attack" << endl;
			user.takeDamage(enemy.damage / 2);
			cout << user.name << "'s health is now " << user.health << endl;
			break;
		}
		case 3: {
			if (potion > 0) {
				cout << user.name << " decides to use the secret potion!" << endl;
				const int MIN = 1;
				const int MAX = 25;
				random_device engine;
				std::random_device rand_dev;
				std::mt19937 generator(rand_dev());
				std::uniform_int_distribution<int> random(MIN, MAX);
				int potionHealth = random(generator); //fix 
				cout << "The potion restored " << potionHealth << "health!" << endl;
				potion--;
			}

			else {
				cout << "You already used your potion.. you lose a turn" << endl;
			}
			break;
		}
	}

	while (user.alive() && enemy.alive()) {
		

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

void displayOptions()
{
	cout << "Now its time for you to make a choice... What will you do?" << endl;
	cout << "1. Stay in the room" << endl << "2. Go to the next room" << endl << "3. Confront the teacher" << endl << "Choice: ";
}

void displayBattleOptions() {
	cout << "Now it is your turn in the battle.." << endl;
	cout << "Choose your next move: " << endl;
	cout << "1. Attack the Teacher " << endl << "2. Defend against the enemies attack" << endl << "3. Use a secret ONE time use potion" << endl;
	cout << "Choice: ";
}

