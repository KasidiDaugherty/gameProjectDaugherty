//Kasidi Daugherty
//CIS 1140 Game Project
//May 14 2024
#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

class Room {
private:
public:
	string name;
	string info;

	Room(string name, string info);
	virtual void enterRoom() = 0;
};




#endif ROOM_H