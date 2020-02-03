#include "pch.h"
#include "Container.h"
#include <iostream>
#include <fstream>


Container::Container()
{
}


Container::~Container()
{
}

void Container::addPlayer(char* newName, int newScore) {
	std::cout << "Enter a name: ";

	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cin >> newName;

	std::cout << std::endl;
	std::cout << "Enter a score for " << newName;

	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cin >> newScore;
	std::cout << std::endl;

	Player* p = new Player(newName, newScore);
	dataSize++;
	playerList[dataSize - 1] = p;
}

void Container::optionSelection() {
	std::cout << "Hello and welcome!" << std::endl;
	std::cout << "1. View All Scores" << std::endl;
	std::cout << "2. Add new Profile" << std::endl;
	std::cout << "3. Save All Profiles" << std::endl;
	std::cout << "4. Load All Profiles" << std::endl;
}

void Container::save() {
	std::ofstream oStr;

	oStr.open("save.txt");

	if (oStr.is_open()) {
		oStr.write((char*)dataSize, sizeof(int));
		for (int i = 0; i < dataSize; i++) {
			oStr.write(playerList[i]->getName(), sizeof(char[30]));
			oStr.write((char*)playerList[i]->getScore(), sizeof(int));
		}
	}

	oStr.flush();
	oStr.close();
}
