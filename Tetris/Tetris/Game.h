#pragma once

#include <SFML\Graphics.hpp>
#include "Gameboard.h"
#include "Tile.h"

class Game
{
public:
	Game();
	~Game();
private:
	sf::RenderWindow m_RenderWindow; // Displaywindow
	sf::RectangleShape Block; // Used for drawing the tiles
	sf::RectangleShape BoardBlock; // Boardblock for creating the Board

	Gameboard Gameboard; // the Gameboard
	Tile Tile; // the tile

	int m_PosX = 2, m_PosY = -2; //pos x/y of the tile that is falling
	int m_Tile, m_Rotation; // what block and what rotation

	int m_NextPosX = 4, m_NextPosY = 0; //pos of the NEXT tile x and y
 	int m_NextTile; // what  NEXT block ID

	int m_BagOfSeven[7]; // bag of seven for random new tiles
	int m_BagPos = 0; // bag pos used for returning the random numbers in giveNextRandomTileID()

	void initWindow(); // Init Window 600,800 Title
	void initBlock(); // Init Block
	void initBoardBlock(); // Init Block for Background

	void drawBoard(); // Draw Board out of BoardBlocks
	void drawBoardBlock(int p_x, int p_Y); // Draw Board block at pos x/y
	void drawBlock(int p_X, int p_Y); //sf::Color Color1, sf::Color Color2); has to be implemented
	void drawTile(int p_X, int p_Y); // draw Tile out of Blocks at pos x/y given in blocks not pixel

	void displayScene(); // displays the play scene
	
	void initBag(); // init the bag with numbers 0 - 6 and shuffle it once
	void shuffleBag(); // shuffles the bag
	int giveNextRandomTileID(); // returns post 0 - 6 of the bag which consits of random numbers

	void moveTile(int p_X, int p_Y);

	void Gameloop(); // main gameloop

	int ceckCollision(int p_X, int p_Y);
	int checkIfPossibleMovement(int p_X, int p_Y);

	void createNewTile(); // creates new tile
};

