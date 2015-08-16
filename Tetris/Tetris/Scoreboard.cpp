#include "Scoreboard.h"
#include <algorithm>
#include <functional>


Scoreboard::Scoreboard()
{
	loadScoreboard();
	saveScoreboard();
}


Scoreboard::~Scoreboard()
{
}

bool Scoreboard::loadScoreboard()
{
	reader.open("Scoreboard.txt");
	
	if (reader.is_open())
	{ 
		int i=0;
		int x;
		while (reader >> x)
		{
			Scores[i] = x;
			i++;
		}
		sortScoreboard();
		for (int i = 0; i < 10; i++)
		{
			std::cout << Scores[i] << std::endl;
		}
		reader.close();
		return true;
	}

	else
	{
		std::cout << "Error" << std::endl;
		reader.close();
		return false;
	}

}

bool Scoreboard::saveScoreboard()
{
	return true;
}

void Scoreboard::sortScoreboard()
{
	std::sort(Scores, Scores+10, std::greater<int>());
}


void Scoreboard::scoreAdd(int p_lvl, int p_lines)
{
	Score = p_lvl*(p_lines * 100) ;
}

void Scoreboard::addNewScoreToScoreboard()
{
	sortScoreboard();
	Scores[11] = Score;
	sortScoreboard();
}