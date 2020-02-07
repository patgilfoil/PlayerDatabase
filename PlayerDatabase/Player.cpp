#include "pch.h"
#include "Player.h"
#include <iostream>

Player::Player()
{
	//defaults for players with nothing associated
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

//set the name of the player to the one that's being input through the function
void Player::setName(char newName[30]) {
	strcpy_s(name, 30, newName);
}

//player creation sequence
void Player::addPlayer() {
	//get a name
	std::cout << "Enter a name: ";

	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cin >> name;

	std::cout << std::endl;
	//get a score
	std::cout << "Enter a score for " << name << ": ";

	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cin >> score;
	std::cout << std::endl;
	//bada bing bada boom and done
	std::cout << "Player data created successfully" << std::endl;
}

void Player::save(std::ofstream& o) {
	//use the out stream sent through the function to write the name and score
	if (o.is_open()) {
		o.write(name, sizeof(char[30]));
		o.write((char*)&score, sizeof(int));
	}
}
//load the function using the in stream being sent through
bool Player::load(std::ifstream& i) {
	//if something weird happens
	if (!i.is_open())
		return false;
	//read the name
	i.read(name, sizeof(char[30]));
	if (i.rdstate()) return false;
	//read the score
	i.read((char*) &score, sizeof(int));
	if (i.rdstate()) return false;
	//load success
	return true;
}