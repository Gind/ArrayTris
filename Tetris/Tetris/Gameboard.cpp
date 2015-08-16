#include "Gameboard.h"


Gameboard::Gameboard()
{
}


Gameboard::~Gameboard()
{
}

bool Gameboard::IsFreeBlock(int p_X, int p_Y)
{
	if (m_BoardPlaced[p_X][p_Y] == POS_FREE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Gameboard::DeleteLine(int p_Y)
{
	for (int i = 0; i < BOARDWIDTH; i++)
	{
		m_BoardPlaced[p_Y][i] = 0;
	}
	int x = p_Y;
	for (int i = p_Y; i > -1; i--)
	{
		if (x>0)
		{ 
			m_BoardPlaced[i][x] = m_BoardPlaced[i][x - 1];
		}
		else
		{
			m_BoardPlaced[i][x] = 0;
		}
		x--;
	}
}

void Gameboard::DeletePossibleLines()
{
	// to do: delete possible lines using Gameboard::deleteLine
}

void Gameboard::InitBoard()
{
	for (int i = 0; i < BOARDWIDTH; i++)
	{
		for (int j = 0; j < BOARDHIGHT; j++)
		{
			m_BoardPlaced[i][j] = POS_FREE;
		}
	}
}

void Gameboard::StorePiece(int p_X, int p_Y, int p_Piece, int p_Rotation)
{

}
