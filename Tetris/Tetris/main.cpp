/*
Playfield is 10 cells wide and at least 22 cells tall, where rows above 20 are hidden or obstructed by the field frame
Tetromino colors:
Cyan I
Yellow O
Purple T
Green S
Red Z
Blue J
Orange L

Tetromino start locations
The I and O spawn in the middle columns
The rest spawn in the left-middle columns
The tetrominoes spawn horizontally and with their flat side pointed down.

Super Rotation System (SRS) specifies tetromino rotation

Standard mappings for console and handheld gamepads:
Up, Down, Left, Right on joystick perform locking hard drop, non-locking soft drop (except first frame locking in some games), left shift, and right shift respectively.
Left fire button rotates 90 degrees counterclockwise, and right fire button rotates 90 degrees clockwise.
Standard mappings different from console/handheld gamepads for computer keyboards

So-called Random Generator (also called "random bag" or "7 system")

"Hold piece": The player can press a button to send the falling tetromino to the hold box, and any tetromino that had been in the hold box moves to the top of the screen and begins falling. Hold cannot be used again until after the piece locks down. Games on platforms with fewer than eight usable buttons (such as the version on iPod) may skip this feature. The combination of hold piece and Random Generator would appear to allow the player to play forever.

Game must have ghost piece function.

Terms used in the user manual: "Tetriminos" not "tetrominoes" nor "tetrads" nor "pieces", letter names not "square" nor "stick", etc.

Designated soft drop speed. Details vary between guideline versions.

Player may only level up by clearing lines or performing T-Spin. Required lines depends in the game.

The player tops out when a piece is spawned overlapping at least one block, or a piece locks completely above the visible portion of the playfield.

Display of next-coming tetrominoes. Most games show at least three, though there are no hard rules.[1
*/
#include <fstream>
#include <iostream>
#include "Scoreboard.h"
#include "Game.h"

int main()
{
	Game Game;

	return 0;
}