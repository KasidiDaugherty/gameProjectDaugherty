//Kasidi Daugherty
//CIS 1140 Game Project
//May 14 2024
#pragma once
#ifndef TEACHER_H
#define TEACHER_H

#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

class Teacher : public Character {
private:
public:
	Teacher(string name, int health, string weapon);
};


#endif TEACHER_H