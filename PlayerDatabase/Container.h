#pragma once
#include "Player.h"
class Container
{
public:
	Container();
	~Container();

	void save();
	void addPlayer(char* newName, int newScore);
	void load();
	void optionSelection();
	void showScores();

private:
	int dataSize = 0;
	Player* playerList[0];
};

