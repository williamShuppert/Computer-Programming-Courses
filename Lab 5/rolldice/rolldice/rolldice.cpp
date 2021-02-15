
// Author:		William Shuppert
// Filename:	logtable.cpp
// Description:	a dice game

#include <iostream>
#include <ctime>
using namespace std;

// min is inclusive max is exclusive
int randint(int min, int max) {
	return rand() % (max - min) + min;
}

// returns 1-6 inclusive
int rollDice() {
	return randint(1, 7);
}

int main() {
	// init variables
	int dice1, dice2, sum;

	// init random seed based on time
	srand(time(0));

	while (true) {
		// roll dice and get sum
		dice1 = rollDice();
		dice2 = rollDice();
		sum = dice1 + dice2;

		// output data
		cout << "Dice 1: " << dice1 << "\tDice 2: " << dice2 << "\tSum: " << sum << endl;

		// determine what to do based on sum
		switch (sum) {
			case 7:
			case 9:
			case 11:
				cout << "You're a WINNER!" << endl << "Game over." << endl;
				return 0; // ends program
			case 2:
			case 3:
			case 5:
				cout << "You Lost!!" << endl << "Game over." << endl;
				return 0; // ends program
			default:
				cout << "Let's roll again..." << endl;
				break; // breaks switch and runs again
		}
	}


}