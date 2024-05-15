//Kasidi Daugherty
//CIS 1140 Game Project
//May 14 2024
#pragma once
#ifndef HALLWAY_H
#define HALLWAY_H

#include "Room.h"
#include <iostream>
#include <string>

using namespace std;

class Hallway : public Room {
private:
public:
	Hallway();
	void enterRoom() override;
};

#endif HALLWAY_H
