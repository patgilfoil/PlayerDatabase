#pragma once
class Player
{
public:
	Player();
	Player(char* pName, int pScore);
	~Player();

	char* getName() { return name; }
	int getScore() { return score; }
	char* setName(char* pName);
	int setScore(int pScore) { score = pScore; }

private:
	char name[30];
	int score;
};

