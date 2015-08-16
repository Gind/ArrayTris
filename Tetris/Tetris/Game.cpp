#include "Game.h"
#include "Defines.h"
#include <iostream>

Game::Game()
{ 
	/*
	* Init Window, Bag, BoardBlock, Block
	*/
	initWindow();
	initBag();
	initBoardBlock();
	initBlock();
	
	/*
	* Starts the main Gameloop
	*/
	Gameloop();
}


Game::~Game()
{
}

/*
* Main Gameloop
*/
void Game::Gameloop()
{
	while (m_RenderWindow.isOpen())
	{
		m_RenderWindow.clear(sf::Color(40,40,40)); // clears window in dark grey

		sf::Event event; // event used below for closing and other input
		while (m_RenderWindow.pollEvent(event))
		{
			switch (event.type)
			{
				// Window closed
			case sf::Event::Closed:
			{
				m_RenderWindow.close();
				break;
			}
				// key pressed
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					m_RenderWindow.close();
					break;
				}
				/*
				* For Testing
				*/
				if (event.key.code == sf::Keyboard::Space)
				{ 
					giveNextRandomTileID();	
					std::cout << m_NextTile << std::endl;
					break;
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					if (checkIfPossibleMovement(1,0) == true)
					{
						moveTile(1, 0);
						break;
					}
				}
				if (event.key.code == sf::Keyboard::Left)
				{
					if (checkIfPossibleMovement(-1,0) == true)
					{
						moveTile(-1, 0);
						break;
					}
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					if (checkIfPossibleMovement(0, 1) == true)
					{
						moveTile(0, 1);
						break;
					}
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					if (checkIfPossibleMovement(0, -1) == true)
					{
						moveTile(0, -1);
						break;
					}
				}
				if (event.key.code == sf::Keyboard::R)
				{
					Tile.rotateRight();
					break;
				}
				if (event.key.code == sf::Keyboard::E)
				{
					Tile.rotateLeft();
					break;
				}

			default:
				break;
			}
		}

		displayScene();
		drawTile(m_PosX, m_PosY);
		
		m_RenderWindow.display();

		
	}
}

/*
* Displays the current Scene
*/
void Game::displayScene()
{
	drawBoard();
}

/*
* Init Window with size and TITLE
*/
void Game::initWindow()
{
	m_RenderWindow.create(sf::VideoMode(640, 800), TITLE);
}

/*
* Draws Board out of BoardBlocks
*/
void Game::drawBoard()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			drawBoardBlock(BOARD_POSITION + i*BLOCK_SIZE, 0 + j*BLOCK_SIZE);
		}
	}
}

/*
* Init BoardBlock, set Size, Outline, Colors
*/
void Game::initBoardBlock()
{
	BoardBlock.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
	BoardBlock.setOutlineThickness(-3);
	BoardBlock.setFillColor(sf::Color(160, 160, 160));
	BoardBlock.setOutlineColor(sf::Color(170, 170, 170));
}

/*
* Init Block, set Size, Outline, Colors
*/
void Game::initBlock()
{
	Block.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
	Block.setFillColor(sf::Color(255,255,0));
	Block.setOutlineThickness(-3);
	Block.setOutlineColor(sf::Color(238, 238, 0));
}

/*
* Draws Block at X/Y pixel
*/
void Game::drawBlock(int p_X, int p_Y)
{
	Block.setPosition(sf::Vector2f(p_X, p_Y));
	m_RenderWindow.draw(Block);
}

/*
* Draws BoardBlock at X/Y pixel
*/
void Game::drawBoardBlock(int p_X, int p_Y)
{
	BoardBlock.setPosition(sf::Vector2f(p_X, p_Y));
	m_RenderWindow.draw(BoardBlock);
}

/*
* x and y and tile id get changed to the new tile
*/
void Game::createNewTile()
{
	m_PosX = m_NextPosX;
	m_PosY = m_NextPosY;

	m_Tile = giveNextRandomTileID();
}

void Game::drawTile(int p_X, int p_Y) // now how to print that shit
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Tile.getTileType(i,j) == 1)
			{
				drawBlock(BOARD_POSITION + p_X*BLOCK_SIZE + i*BLOCK_SIZE, p_Y*BLOCK_SIZE + j*BLOCK_SIZE);
			}
		}
	}
}

void Game::moveTile(int p_X,int p_Y)
{
	m_PosX = m_PosX + p_X;
	m_PosY = m_PosY + p_Y;
}

/*
* Init Bag with 0 - 6 and shuffles it once
*/
void Game::initBag()
{
	for (int i = 0; i < 7; i++)
	{
		m_BagOfSeven[i] = i;
	}
	shuffleBag();
}

/*
* shuffles bag
*/
void Game::shuffleBag()
{
	std::random_shuffle(std::begin(m_BagOfSeven), std::end(m_BagOfSeven));
}

/*
* returns next random tile id
*/
int Game::giveNextRandomTileID()
{
	if (m_BagPos > 7)
	{
		shuffleBag();
		m_BagPos = 0;
		giveNextRandomTileID();
		return 0;
	}
	else
	{
		m_NextTile = m_BagOfSeven[m_BagPos];
		m_BagPos++;
		return m_NextTile;
	}
}

int Game::ceckCollision(int p_X, int p_Y)
{
	// pos x und y sind gegeben
	// gucken ob die einsen aus dem array innerhalb boardpos + 10*blocksize liegen
	// collision der seitenwände wäre das
	// 0 = no collison
	// 1 = collision

	enum {NO_COLLISION, COLLISION};

	sf::Vector2i BoardPos;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Tile.getTileType(i, j) == 1)
			{
				BoardPos.x = BOARD_POSITION + i*BLOCK_SIZE + p_X*BLOCK_SIZE;
				BoardPos.y =				  j*BLOCK_SIZE + p_Y*BLOCK_SIZE;

				if (BoardPos.x <= BOARD_POSITION - BLOCK_SIZE)
				{
					return COLLISION;
				}
				if (BoardPos.x >= BOARD_POSITION + BLOCK_SIZE*BOARDWIDTH)
				{
					return COLLISION;
				}

				if (BoardPos.y <= -2 * BLOCK_SIZE)
				{
					return COLLISION;
				}
				if (BoardPos.y >= (BOARDHIGHT-2) * BLOCK_SIZE)
				{
					return COLLISION;
				}
			}
		}
	}
	return NO_COLLISION;
}

int Game::checkIfPossibleMovement(int p_X, int p_Y)
{
	enum { MOVEMENT_IMPOSSIBLE, MOVEMENT_POSSIBLE };

	if (!ceckCollision(m_PosX + p_X, m_PosY + p_Y))
	{
		return MOVEMENT_POSSIBLE;
	}
	else
	{
		return MOVEMENT_IMPOSSIBLE;
	}
}