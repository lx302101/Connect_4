#pragma once
#include <iostream>
#include <vector>


class Board
{
public:
	Board(int x1, int y1);
	void printBoard();
	bool checkWin(char color);
	void playTurn(char color);
	void endGame(char color);
	bool playAgain();
	


private:
	std::vector<std::vector<char>> playBoard;
	int xBoard, yBoard;
	int x, y;

};

