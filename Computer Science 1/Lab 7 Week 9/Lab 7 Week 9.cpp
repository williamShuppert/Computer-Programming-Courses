#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

bool AI_VS_AI = false;

bool validMove(char[][3], int &, int &);
char gameState(char[][3]);
void printBoard(char[][3]);
void bestMove(char[][3], char, int &, int &);
int minimax(char[][3], char);

bool validMove(char board[][3], int & row, int & col) {
	if (row < 0 || row > 2 || col < 0 || col > 2) return false;
	if (board[row][col] == '-') return true;
	return false;
}

char gameState(char board[][3]) {
	// return:
	// O = O wins
	// X = X wins
	// - = continue
	// T = tie

	// check horizontal
	for (int row = 0; row < 3; row++)
		if (board[row][0] != '-' && board[row][1] == board[row][0] && board[row][2] == board[row][1]) return board[row][0];
	// check vertical
	for (int col = 0; col < 3; col++)
		if (board[0][col] != '-' && board[1][col] == board[0][col] && board[2][col] == board[1][col]) return board[0][col];
	// check diagonals
	if (board[0][0] != '-' && board[1][1] == board[0][0] && board[2][2] == board[1][1]) return board[0][0];
	if (board[0][2] != '-' && board[1][1] == board[0][2] && board[2][0] == board[1][1]) return board[0][2];
	// check for tie
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (board[row][col] == '-') return '-';
	return 'T';
}

void printBoard(char board[][3]) {
	for (int i = 0; i < 3; i++)
		cout << board[i][0] << board[i][1] << board[i][2] << endl;
}

void bestMove(char board[][3], char currentPlayer, int & bestRow, int & bestCol) {
	// output what options are possible
	cout << "Possible moves for " << currentPlayer << ":" << endl;
	if (currentPlayer == 'X') cout << "(Smaller eval is better)" << endl;
	else cout << "(Larger eval is better)" << endl;

	char nextPlayer = currentPlayer == 'O' ? 'X' : 'O';
	int bestEval = currentPlayer == 'O' ? -2 : 2;
	// keep track of best moves
	vector<int> movesRow;
	vector<int> movesCol;

	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++) {
			// skip position if move is invalid
			if (!validMove(board, row, col)) continue;
			// create a copy of the board
			char newBoard[3][3];
			for (int newRow = 0; newRow < 3; newRow++)
				for (int newCol = 0; newCol < 3; newCol++)
					newBoard[newRow][newCol] = board[newRow][newCol];
			// play on new board
			newBoard[row][col] = currentPlayer;
			// determain evaluation of move
			int eval = minimax(newBoard, nextPlayer);
			// output possible move that can be made
			cout << "at " << row << ", " << col << " eval is: " <<  eval << endl;
			// check to see if outcome is more desirable or same as the best
			if (bestEval == eval) { // outcome is same add to list of possible good moves
				movesRow.push_back(row);
				movesCol.push_back(col);
			} else if ((currentPlayer == 'O' && eval > bestEval) || (currentPlayer == 'X' && eval < bestEval)) { // outcom is better, create new list
				bestEval = eval;
				bestRow = row;
				bestCol = col;
				movesRow.clear();
				movesCol.clear();
				movesRow.push_back(row);
				movesCol.push_back(col);
			}
		}
	// pick one of the best moves randomly
	int index = rand() % movesRow.size();
	bestRow = movesRow.at(index);
	bestCol = movesCol.at(index);
}

int minimax(char board[][3], char currentPlayer) {
	char outcome = gameState(board);
	if (outcome == 'X') return -1; // minimizing player
	else if (outcome == 'O') return 1; // maximizing player
	else if (outcome == 'T') return 0;

	int bestEval = currentPlayer == 'O' ? -2 : 2;

	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++) {
			// skip position if move is invalid
			if (!validMove(board, row, col)) continue;

			// create a copy of the board
			char newBoard[3][3];
			for (int newRow = 0; newRow < 3; newRow++)
				for (int newCol = 0; newCol < 3; newCol++)
					newBoard[newRow][newCol] = board[newRow][newCol];

			// play move on new board
			newBoard[row][col] = currentPlayer;

			// record best eval for current player
			if (currentPlayer == 'X') bestEval = min(bestEval, minimax(newBoard, 'O'));
			else bestEval = max(bestEval, minimax(newBoard, 'X'));

		}

	return bestEval;
}

int main() {
	// initialize random
	srand(time(NULL));

	while (true) { // keep playing loop

		// reset board
		char board[3][3] = { {'-','-','-'},{'-','-','-'},{'-','-','-'} };

		do { // game loop

			// computer plays
			int row, col;
			bestMove(board, 'X', row, col);
			board[row][col] = 'X';

			cout << "After the computer played:" << endl;
			printBoard(board);

			// end game if computer wins or if tie
			if (gameState(board) != '-') break;

			// get user input and play
			if (!AI_VS_AI) {
				do {
					cout << "What row? (0,1,or 2): "; cin >> row;
					cout << "What col? (0,1,or 2): "; cin >> col;
				} while (!validMove(board, row, col));
				board[row][col] = 'O';
			} else {
				bestMove(board, 'O', row, col);
				board[row][col] = 'O';
			}

			cout << "After you played:" << endl;
			printBoard(board);

		} while (gameState(board) == '-');

		// display outcome of game
		char outcome = gameState(board);
		if (outcome == 'T') cout << "Tie!" << endl;
		else cout << outcome << " Wins!" << endl;

		// ask user to play again
		char playAgain;
		cout << "Do you want to play again? (y/n): ";
		cin >> playAgain;
		if (playAgain != 'y') break;
	}

	return 0;
}
