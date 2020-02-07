#pragma once
#include "Player.h"
class Container
{
public:
	Container();
	~Container();

	void save();
	bool load();
	void optionSelection(bool active);
	void add(Player player);
	void updatePlayer();
	void sort();

private:
	int dataSize = 0;
	Player* playerList = new Player[dataSize];
};

