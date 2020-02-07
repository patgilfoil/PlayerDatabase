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
		//show all options
		std::cout << "1. View All Scores" << std::endl;
		std::cout << "2. Add new Profile" << std::endl;
		std::cout << "3. Update Profile Score" << std::endl;
		std::cout << "4. Save All Profiles" << std::endl;
		std::cout << "5. Load All Profiles" << std::endl;
		std::cout << "6. Quit the Program" << std::endl;
		
		//clear cin input
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		//get new input
		char option = '0';
		std::cin >> option;

		//go through each option and see if it matches user input
		if (option == '1') {
			//show all scores in the player list
			for (int i = 0; i < dataSize; i++) {
				std::cout << playerList[i].getName() << ": " << playerList[i].getScore() << std::endl;
			}
		}
		if (option == '2') {
			//create new player
			Player p;
			p.addPlayer();
			//add player to the array
			add(p);
			//then sort array by alphabetical names
			sort();
		}
		if (option == '3') {
			updatePlayer();
		}
		if (option == '4') {
			save();
			std::cout << "Player scores have been saved" << std::endl;
		}
		if (option == '5') {
			load();
		}
		if (option == '6') {
			//set active to false and end the loop
			active = false;
		}
	}
}

void Container::save() {
	std::ofstream oStr;

	oStr.open("save.dat", std::ofstream::out | std::ofstream::out | std::ofstream::binary);

	if (oStr.is_open()) {
		oStr.write((char*)&dataSize, sizeof(int));
		//for each player in the player list
		for (int i = 0; i < dataSize; i++) {
			//call the save function from player
			playerList[i].save(oStr);
		}
	}

	oStr.close();
}

void Container::updatePlayer() {
	char searchTerm[30];

	//get a name form the user
	std::cout << "Which score are you trying to update?" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin >> searchTerm;

	//search through the array and find the name through a binary search
	int startIndex = 0;
	int endIndex = dataSize - 1;

	while (startIndex <= endIndex) {
		//pivot is our midpoint for the search
		int pivot = ((startIndex + endIndex) / 2);
		//if the pivot matches
		if (strcmp(playerList[pivot].getName(), searchTerm) == 0) {
			//get a new score
			std::cout << "Enter a new score for this profile: ";
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());

			int newScore;
			std::cin >> newScore;
			//update the score with the new score
			playerList[pivot].setScore(newScore);
			std::cout << std::endl;
			std::cout << "Player score has been updated." << std::endl;
			//stop the loop
			break;
		}
		//if the pivot is incorrect to the search term, smaller value than term
		else if (strcmp(searchTerm, playerList[pivot].getName()) < 0) {
			//move the starting index close to the pivot's location
			startIndex = pivot + 1;
		}
		//if the pivot is incorrect to the search term, larger value than term
		else if (strcmp(searchTerm, playerList[pivot].getName()) > 0)
			//move the ending index close to the pivot's location
			endIndex = pivot - 1;
	}
}

void Container::sort() {
	//do some of these variables seem familiar?
	int startLength = 0;
	int endLength = dataSize - 1;
	bool sorted = false;
	
	//while not sorted
	while (!sorted) {
		//set sorted to true
		sorted = true;
		//go to the start of the array and compare names
		for (int i = startLength; i < endLength; i++) {
			int compare = strcmp(playerList[i].getName(), playerList[i + 1].getName());
			if (compare > 0) {
				//they didn't match, swap em
				Player movedPlayer = playerList[i];
				playerList[i] = playerList[i + 1];
				playerList[i + 1] = movedPlayer;
				sorted = false;
			}
		}
		//set the end index further down
		endLength--;
		//go to the end of the array and compare names
		for (int e = endLength; e > startLength; e--) {
			int compare2 = strcmp(playerList[e-1].getName(), playerList[e].getName());
			if (compare2 > 0) {
				//they didn't match, swap em
				Player movedPlayer2 = playerList[e-1];
				playerList[e-1] = playerList[e];
				playerList[e] = movedPlayer2;
				sorted = false;
			}
		}
		//set the start index further up
		startLength++;
	}
}

bool Container::load() {
	//open up the in stream to read the save file
	std::ifstream iStr;

	iStr.open("save.dat", std::ifstream::in | std::ifstream::binary);

	if (!iStr.is_open())
		return false;
	//read the size of the player array
	iStr.read((char*)&dataSize, sizeof(int));
	if (iStr.rdstate()) return false;
	//create a temp arrat of all players and load in the players from the save
	Player* temp = new Player[dataSize];
	for (int i = 0; i < dataSize; i++) {
		if (temp[i].load(iStr) == false) {
			return false;
		}
	}
	//set the default player list array to the loaded one
	playerList = temp;
	std::cout << "All player scores have been updated" << std::endl;

	return true;
}

void Container::add(Player player) {
	Player* mid = new Player[dataSize + 1];
	//create a temp array to load in the default player list
	for (int i = 0; i < dataSize; i++) {
		mid[i] = playerList[i];
	}
	playerList = mid;
	//the new last player will be the one we created
	playerList[dataSize] = player;
	dataSize++;
}
