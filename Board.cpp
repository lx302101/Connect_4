#include "Board.h"

Board::Board(int x1, int y1) {
	xBoard = y1;
	yBoard = x1;
	for (int i = 0; i < yBoard; ++i) {
		std::vector<char> temp;
		for (int j = 0; j < xBoard; ++j) {
			temp.push_back('*');
		}
		playBoard.push_back(temp);
	}
	x = 0;
	y = 0;
}

void Board::printBoard() {
	for (int i=0; i<yBoard; ++i) {
		for (int j=0; j<xBoard; ++j) {
			std::cout << playBoard[i][j];
		}
		std::cout << std::endl;
	}
}

bool Board::checkWin(char color) {
	//horizontal
	int count{0};
	for (int i=1; i<5; ++i) {
		if (x-i<0) break;
		else {
			if (playBoard[y][x-i] == color) {
				++count;
				if (count==3) return true;
			} else {
				break;
			}
		}
	}
	for (int i=1; i<5; ++i) {
		if (x+i > xBoard-1) break;
		else {
			if (playBoard[y][x+i] == color) {
				++count;
				if (count==3) return true;
			}
			else {
				break;
			}
		}
	}
	count = 0;

	//vertical
	if (y+3 < yBoard) {
		if (playBoard[y+1][x] == color && playBoard[y+2][x] == color && playBoard[y+3][x] == color) {
			return true;
		}
	}

	//diagonal
	for (int i=1; i<5; ++i) {
		if (x-i < 0 || y-i < 0) break;
		else {
			if (playBoard[y-i][x-i] == color) {
				++count;
				if (count == 3) return true;
			}
			else {
				break;
			}
		}
	}
	
	for (int i=1; i<5; ++i) {
		if (x+i > xBoard-1 || y+i > yBoard-1) break;
		else {
			if (playBoard[y+i][x+i] == color) {
				++count;
				if (count == 3) return true;
			}
			else {
				break;
			}
		}
	}
	count = 0;
	
	for (int i=1; i<5; ++i) {
		if (x-i < 0 || y+i > yBoard-1) break;
		else {
			if (playBoard[y+i][x-i] == color) {
				++count;
				if (count == 3) return true;
			}
			else {
				break;
			}
		}
	}
	for (int i=1; i<5; ++i) {
		if (x+i > xBoard-1 || y-i < 0) break;
		else {
			if (playBoard[y-i][x+i] == color) {
				++count;
				if (count == 3) return true;
			}
			else {
				break;
			}
		}
	}
	
	return false;
}

void Board::playTurn(char color) {
	int x1;
	std::cin >> x1;
	while (x1>xBoard-1 || x1<0 ) {
		std::cout << "Coloumn is outside boundries. Please input another coloumn:";
		std::cin >> x1;
	}
	x = x1-1;
	if (playBoard[0][x] != '*') {
		std::cout << "Coloumn full. Reinput another coloumn: ";
		std::cin >> x1;
		x = x1-1;
	}
	int temp = playBoard.size() - 1;
	while (playBoard[temp][x] != '*') {
		--temp;
	}

	y = temp;
	playBoard[y][x] = color;
}

void Board::endGame(char color) {
	std::cout << color << " wins!" << std::endl;
}

bool Board::playAgain() {
	int t{};
	std::cout << "Play Again?" << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;
	std::cin >> t;
	if (t == 1) return true;
	return false;
}