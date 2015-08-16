#pragma once
#include "Defines.h"
#include "Tile.h"

class Gameboard
{
public:
	Gameboard();

	bool IsFreeBlock(int p_X, int p_Y);
	bool IsPossibleMovement(int p_X, int p_Y, int p_Piece, int p_Rotation);
	void StorePiece(int p_X, int p_Y, int p_Piece, int p_Rotation);
	void DeletePossibleLines();
	bool IsGameOver();

	~Gameboard();
private:
	int m_BoardPlaced[BOARDHIGHT][BOARDWIDTH];
	int m_BoardTile[BOARDHIGHT][BOARDWIDTH];
	enum { POS_FREE /* Position is free = 0*/, POS_FILLED /* Postition is filled = 1*/};
	Tile m_Tile;
	int m_ScreenHeight;

	void InitBoard();
	void DeleteLine(int p_Y);
};