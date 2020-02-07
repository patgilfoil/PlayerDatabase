#pragma once
#include <fstream>

class Player
{
public:
	Player();
	Player(char* pName, int pScore);
	~Player();

	char* getName() { return name; }
	int getScore() { return score; }
	void setName(char pName[30]);
	void setScore(int pScore) { score = pScore; }
	void save(std::ofstream& o);
	bool load(std::ifstream& i);
	void addPlayer();

private:
	char name[30];
	int score;
};

