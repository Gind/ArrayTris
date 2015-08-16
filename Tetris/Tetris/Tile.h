#pragma once

#include <SFML/Graphics/Color.hpp>

class Tile
{
public:
	Tile();
	~Tile();

	int getTileType(int p_X, int p_Y);
	void setTileType(int p_Tile, int p_Rotation);

	void rotateRight();
	void rotateLeft();

	int m_Rotation;
	int m_CurrentTileID;
	int m_Tile[5][5];

	private:
};
