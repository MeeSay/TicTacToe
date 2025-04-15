#pragma once
#include"Header.h"
#include"Board.h"
#include"Player.h"

class TicTacToe {
private:
	Board board;
	Player player[2];
	int currentPlayIndex;
public:
	TicTacToe() :currentPlayIndex(0) {
		player[0] = Player('X', "Player X");
		player[1] = Player('O', "Player O");
	}

	Player& getCurrentPlayer() {
		return player[currentPlayIndex];
	}

	void switchTurn() {
		currentPlayIndex = (currentPlayIndex + 1) % 2;
	}

	void play() {
		int row, col;
		cout << "Welcome to TicTacToe!!!" << endl;
		while (!board.isFull()) {
			board.drawBoard();
			
			Player& currentPlayer = getCurrentPlayer();
			
			while (true) {
				cout << currentPlayer.getName() << "(" << currentPlayer.getSymbol() << "), enter row (1-3) and col (1-3): ";
				cin >> row >> col;
				row--; col--;

				if (!board.isValidMove(row, col)) {
					cout << "Invalid move!!! Try again." << endl;
				}
				else
					break;
				
			}

			board.makeMove(row, col, currentPlayer.getSymbol());

			if (board.checkWin(currentPlayer.getSymbol())) {
				board.drawBoard();
				cout << currentPlayer.getName() << " wins!" << endl;
				return;
			}

			switchTurn();
		}

		board.drawBoard();
		cout << "It's a draw." << endl;
	}
};