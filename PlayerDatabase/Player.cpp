#include "pch.h"
#include "Player.h"
#include <iostream>

Player::Player()
{
	strcpy_s(name, 30, "unexist");
	score = 0;
}

Player::Player(char pName[30], int pScore) {
	strcpy_s(name, 30, pName);
	score = pScore;
}


Player::~Player()
{
}

void Player::setName(char newName[30]) {
	strcpy_s(name, 30, newName);
}

void Player::addPlayer() {
	std::cout << "Enter a name: ";

	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cin >> name;

	std::cout << std::endl;
	std::cout << "Enter a score for " << name << ": ";

	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cin >> score;
	std::cout << std::endl;

	std::cout << "Player data created successfully" << std::endl;
}

void Player::save(std::ofstream& o) {
	if (o.is_open()) {
		o.write(name, sizeof(char[30]));
		o.write((char*)&score, sizeof(int));
	}
}

bool Player::load(std::ifstream& i) {
	if (!i.is_open())
		return false;

	i.read(name, sizeof(char[30]));
	if (i.rdstate()) return false;

	i.read((char*) &score, sizeof(int));
	if (i.rdstate()) return false;

	return true;
}