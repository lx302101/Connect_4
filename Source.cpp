#include "Board.h"
 
int main() {
	bool isPlaying{true};
	bool isGame{false};
	int score1{}, score2{};
	std::cout << "What is the board size? Input x and y:" << std::endl;
	int x{}, y{};
	std::cout << "x: ";
	std::cin >> x;
	while (x<4) {
		std::cout << "x must be bigger than 4;" << std::endl;
		std::cout << "Please reinput integer;" << std::endl;
		std::cin >> x;
	}
	std::cout << "y: ";
	std::cin >> y;
	
	while (isPlaying) {
		Board testing(x, y);
		testing.printBoard();
		std::cout << "Player 1: You are red (R)";
		std::cout << "Player 2: You are green(G)";
		while (!isGame) {
			std::cout << "Player 1 Turn" << std::endl;
			std::cout << "What coloumn do you want to place? ";
			testing.playTurn('R');
			testing.printBoard();
			if (testing.checkWin('R')) {
				testing.endGame('R');
				++score1;
				break;
			}

			std::cout << "Player 2 Turn" << std::endl;
			std::cout << "What coloumn do you want to place? ";
			testing.playTurn('G');
			testing.printBoard();
			if (testing.checkWin('G')) {
				testing.endGame('G');
				++score2;
				break;
			}
		}
		std::cout << "The score is: " << std::endl;
		std::cout << "Player 1: " << score1 << std::endl;
		std::cout << "Player 2: " << score2 << std::endl;
		if (!testing.playAgain()) {
			isPlaying = false;
			break;
		}
	}

	return 0;
}

