#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int size = 4; // this will deterine the size of the game. in this case its 4x4
const int MAX_VALUE = 2048; // this will be the highest tile 

int board[size][size]; // making a 2d array
int score = 0;
int highScore = 0;
// functions
void printBoard() ;

void clearBoard();

void addRandomTile() ;
   

void slideTiles(int direction) ;

bool isGameOver() ;

int main() {
	cout<<"WELCOME TO 2048"<<endl;
srand(time(NULL));
clearBoard();
addRandomTile();
addRandomTile();
printBoard();
while (true) {
char input;
cout << "Enter move (W = up, A = left, S = down, D = right, Q = quit): "; // this allows user to play the game
cin >> input;
if (input == 'W' || input == 'w') { // casses for the inputs enetred by the user
slideTiles(0);
} else if (input == 'D' || input == 'd') {
slideTiles(1);
} else if (input == 'S' || input == 's') {
slideTiles(2);
} else if (input == 'A' || input == 'a') {
slideTiles(3);
} else if (input == 'Q' || input == 'q') {
	cout << "Final Score: " << score << endl;
break;
} else {
cout << "Invalid input!" << endl;
continue;
}
if (isGameOver()) { // prints the highscore and final score when the game is over
cout << "Game Over!" << endl;
if (score > highScore) {
highScore = score;
}
cout << "Final Score: " << score << endl;
cout << "High Score: " << highScore << endl;
break;
}
printBoard();
}
return 0;
}

void printBoard() { // this function print the board on which you play the game
    cout << "Score: " << score << "   High Score: " << highScore << endl;
    // formatting (i know its bad :) )
    cout << "|------|------|------|------|"<< endl;
    for (int i = 0; i < size; i++) {
        cout << "|";
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                cout << "      |";
            } else {
                printf("%6d|", board[i][j]);
            }
        }
        cout << endl << "|------|------|------|------|" << endl;
    }
}
void clearBoard() { // this sets all the elements of the array to 0 or none
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
}

void addRandomTile() { // for adding random numbers in a random tile
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                count++;
            }
        }
    }
    if (count == 0) {
        return;
    }
    int index = rand() % count;
    int value = (rand() % 2 + 1) * 2; // either 2 or 4
    count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                if (count == index) {
                    board[i][j] = value;
                    return;
                }
                count++;
            }
        }
    }
}

void slideTiles(int direction) {
	// this function not only moves the tiles but also adds the number along the way
    bool moved = false;
    int rowOffset = 0, colOffset = 0;
    switch (direction) {
    	// indexing
        case 0: // up
            rowOffset = -1;
            break;
        case 1: // right
            colOffset = 1;
            break;
        case 2: // down
            rowOffset = 1;
            break;
        case 3: // left
            colOffset = -1;
            break;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int row = i, col = j;
            if (board[row][col] == 0) {
                continue;
            }
            while (true) { // for adding the tiles if they can be added 
                int nextRow = row + rowOffset, nextCol = col + colOffset;
                if (nextRow < 0 || nextRow >= size || nextCol < 0 || nextCol >= size) {
                    break;
                }
                if (board[nextRow][nextCol] == 0) {
                    board[nextRow][nextCol] = board[row][col];
                    board[row][col] = 0;
                    row = nextRow;
                    col = nextCol;
                    moved = true;
                } else if (board[nextRow][nextCol] == board[row][col]) {
                    board[nextRow][nextCol] += board[row][col];
score += board[nextRow][nextCol];
board[row][col] = 0;
moved = true;
break;
} else {
break;
}
}
}
}
if (moved) {
addRandomTile();
}
}

bool isGameOver() { // this checks whether the game is over or not by itrating over every tile,
// this also checks for empty spaces or tiles containing same numbers
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
if (board[i][j] == 0) {
return false;
}
if (j < size - 1 && board[i][j] == board[i][j+1]) {
return false;
}
if (i < size - 1 && board[i][j] == board[i+1][j]) {
return false;
}
}
}
return true;
}

