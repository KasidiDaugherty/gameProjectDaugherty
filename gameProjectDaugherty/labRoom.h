//Kasidi Daugherty
//CIS 1140 Game Project
//May 14 2024
#pragma once
#ifndef LAB_H
#define LAB_H
#include "Room.h"
#include <iostream>
#include <string>
using namespace std;

class LabRoom : public Room {
private:
public:
	LabRoom();
	void enterRoom() override;
};



#endif LAB_H