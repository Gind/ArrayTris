#pragma once
#include <iostream>
#include <fstream>
#include <String>

class Scoreboard
{
public:
	Scoreboard();
	~Scoreboard();
	
private:
	int Scores[11];
	int Score = 0;

	std::ofstream writer;
	std::ifstream reader;

	bool saveScoreboard();
	bool loadScoreboard();

	void sortScoreboard();
	void addNewScoreToScoreboard();

	void scoreAdd(int p_lvl, int p_lines);
	
};

