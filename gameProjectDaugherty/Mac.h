//Kasidi Daugherty
//CIS 1140 Game Project
//May 14 2024
#pragma once
#ifndef MAC_H
#define MAC_H

#include "Room.h"
#include <iostream>
#include <string>

using namespace std;

class Mac : public Room {
private:
public:
	Library();
	void enterRoom() override;
};

#endif MAC_H
