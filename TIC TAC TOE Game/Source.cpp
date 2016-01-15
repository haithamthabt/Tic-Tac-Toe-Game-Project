// Purpose: Two Tic Tac Toe players game
// Author's Name: Haitham Thab
// Creation Date: 09/26/2015
// Modification Date: 09/27/2015


#include <iostream>



using namespace std;

// global variables
int const NUM_OF_SQUARES = 10;
char mySquare[NUM_OF_SQUARES] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int numOfPlays = 1;

void printBoard();
bool gameOver();
bool showWinnter();
void askForInput();
bool isPicked(int input);

int main() {

	

	// Game loop, as long as the game is not over neither someone won keep looping
	do {


		// print the board, then modify the array and lastly print the modified board
		printBoard();
		askForInput();
		printBoard();

	} while (gameOver() != true && showWinnter() != true);





	system("PAUSE");
	return 0;
}



// Purpose of the function: To display the board
// Author's Name: Haitham Thabt
// Creation Date: 09/26/2015
// Modification Date: 09/26/2015
void printBoard() {


	cout << endl << endl << " \tTic Tac Toe" << endl << endl;
	cout << "Player 1 (X)     -     Player 2 (O)" << endl << endl;

	cout << "     |     |     " << endl;
	cout << "  " << mySquare[1] << "  |  " << mySquare[2] << "  |  " << mySquare[3] << endl;

	cout << "_____|_____|_____" << endl;

	cout << "     |     |     " << endl;
	cout << "  " << mySquare[4] << "  |  " << mySquare[5] << "  |  " << mySquare[6] << endl;

	cout << "_____|_____|_____" << endl;

	cout << "     |     |     " << endl;
	cout << "  " << mySquare[7] << "  |  " << mySquare[8] << "  |  " << mySquare[9] << endl;
	cout << "     |     |     " << endl;


}



// Purpose of the function: To check if there is a winner and display which player
// Author's Name: Haitham Thabt
// Creation Date: 09/27/2015
// Modification Date: 09/27/2015
bool showWinnter() {

	/*
	the winning patterns are:
	123
	456
	789
	147
	258
	369
	159
	357
	*/
	//if someone wins

	if ((mySquare[1] == 'X' && mySquare[2] == 'X' && mySquare[3] == 'X') ||
		(mySquare[4] == 'X' && mySquare[5] == 'X' && mySquare[6] == 'X') ||
		(mySquare[7] == 'X' && mySquare[8] == 'X' && mySquare[9] == 'X') ||
		(mySquare[1] == 'X' && mySquare[4] == 'X' && mySquare[7] == 'X') ||
		(mySquare[2] == 'X' && mySquare[5] == 'X' && mySquare[8] == 'X') ||
		(mySquare[3] == 'X' && mySquare[6] == 'X' && mySquare[9] == 'X') ||
		(mySquare[1] == 'X' && mySquare[5] == 'X' && mySquare[9] == 'X') ||
		(mySquare[3] == 'X' && mySquare[5] == 'X' && mySquare[7] == 'X')) {

		cout << endl << "Player 1 Won" << endl;
		return true;

	} else if ((mySquare[1] == 'O' && mySquare[2] == 'O' && mySquare[3] == 'O') ||
		(mySquare[4] == 'O' && mySquare[5] == 'O' && mySquare[6] == 'O') ||
		(mySquare[7] == 'O' && mySquare[8] == 'O' && mySquare[9] == 'O') ||
		(mySquare[1] == 'O' && mySquare[4] == 'O' && mySquare[7] == 'O') ||
		(mySquare[2] == 'O' && mySquare[5] == 'O' && mySquare[8] == 'O') ||
		(mySquare[3] == 'O' && mySquare[6] == 'O' && mySquare[9] == 'O') ||
		(mySquare[1] == 'O' && mySquare[5] == 'O' && mySquare[9] == 'O') ||
		(mySquare[3] == 'O' && mySquare[5] == 'O' && mySquare[7] == 'O')) {

		cout << endl << "Player 2 Won" << endl;
		return true;

	} else {

		// otherwise let the gameloop coninue
		return false;

	}


} // end of the function




// Purpose of the function: To ask the player where to put the X or the O
// Author's Name: Haitham Thabt
// Creation Date: 09/26/2015
// Modification Date: 09/27/2015
void askForInput() {


	int userInput;

	if (numOfPlays == 1 || numOfPlays == 3 || numOfPlays == 5 || numOfPlays == 7 || numOfPlays == 9) {


		// check if the box has been picked or not
		do {

			cout << endl << "Player 1, enter the position number of your X: ";
			cin >> userInput;

		} while (isPicked(userInput) == true);

		// once player inputs appropriate positon, replace it with X
		mySquare[userInput] = 'X';
		numOfPlays++;

	} else {

		do {
			
			cout << endl << "Player 2, enter the position number of your O: ";
			cin >> userInput;
		} while (isPicked(userInput) == true);

		// once player inputs appropriate positon, replace it with O
		mySquare[userInput] = 'O';
		numOfPlays++;
	}

	

}



// Purpose of the function: To check if the box is already picked or not
// Author's Name: Haitham Thabt
// Creation Date: 09/27/2015
// Modification Date: 09/27/2015
bool isPicked(int input) {

	if( mySquare[input] == 'X' || mySquare[input] == 'O' ) {

		return true;

	} else {

		return false;
	}

}



// Purpose of the function: To check if all boxes are picked and display gameOver
// Author's Name: Haitham Thabt
// Creation Date: 09/27/2015
// Modification Date: 09/27/2015
bool gameOver() {

	if (numOfPlays > 9) {

		cout << "Game Over" << endl;
		return true;
	} else {

		return false;
	}

}