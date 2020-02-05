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

void Container::optionSelection(bool active) {
	std::cout << "Hello and welcome!" << std::endl;
	while (active) {
		std::cout << "1. View All Scores" << std::endl;
		std::cout << "2. Add new Profile" << std::endl;
		std::cout << "3. Save All Profiles" << std::endl;
		std::cout << "4. Load All Profiles" << std::endl;
		std::cout << "5. Quit the Program" << std::endl;

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		char option = '0';
		std::cin >> option;

		if (option == '1') {
			for (int i = 0; i < dataSize; i++) {
				std::cout << playerList[i].getName() << ": " << playerList[i].getScore() << std::endl;
			}
		}
		if (option == '2') {
			Player p;
			p.addPlayer();
			add(p);
			sort();
		}
		if (option == '3') {
			save();
		}
		if (option == '4') {
			load();
		}
		if (option == '5') {
			active = false;
		}
	}
}

void Container::save() {
	std::ofstream oStr;

	oStr.open("save.txt", std::ios::out);

	if (oStr.is_open()) {
		oStr.write((char*)&dataSize, sizeof(int));
		for (int i = 0; i < dataSize; i++) {
			playerList[i].save(oStr);
		}
	}

	oStr.close();
}

void Container::sort() {
	for (int i = 0; i < dataSize - 1; i++) {
		if (dataSize < 2) return;

		bool sorted = false;
		while (!sorted) {
			sorted = true;
			int compare = strcmp(playerList[i].getName(), playerList[i + 1].getName());
			if (compare > 0) {
				Player movedPlayer = playerList[i];
				playerList[i] = playerList[i + 1];
				playerList[i + 1] = movedPlayer;
				sorted = false;
			}
		}
	}
}

bool Container::load() {
	std::ifstream iStr;

	iStr.open("save.txt", std::ios::in);

	if (!iStr.is_open())
		return false;

	iStr.read((char*)&dataSize, sizeof(int));
	if (iStr.rdstate()) return false;

	Player* temp = new Player[dataSize];
	for (int i = 0; i < dataSize; i++) {
		if (temp[i].load(iStr) == false) {
			return false;
		}
	}
	playerList = temp;

	return true;
}

void Container::add(Player player) {
	Player* mid = new Player[dataSize + 1];

	for (int i = 0; i < dataSize; i++) {
		mid[i] = playerList[i];
	}
	playerList = mid;
	playerList[dataSize] = player;
	dataSize++;
}
