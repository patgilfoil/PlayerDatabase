#include "pch.h"
#include "Player.h"
#include <iostream>
#include <string>

Player::Player()
{
}

Player::Player(char* pName, int pScore) {
	strcpy_s(name, 30, pName);
	score = pScore;
}


Player::~Player()
{
}

char* Player::setName(char* pName) {
	strcpy_s(name, 30, pName);
}