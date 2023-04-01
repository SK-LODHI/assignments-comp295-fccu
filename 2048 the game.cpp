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
void printBoard();
void clearBoard();
void addRandomTile();
void moveUp();
void moveDown();
void moveLeft();
void moveRight();
bool isGameOver();

int main() {
    cout << "WELCOME TO 2048" << endl;
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
            moveUp();
        } else if (input == 'D' || input == 'd') {
            moveRight();
        } else if (input == 'S' || input == 's') {
            moveDown();
        } else if (input == 'A' || input == 'a') {
            moveLeft();
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
    cout << "|------|------|------|------|" << endl;
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
        for (int j =0; j < size; j++) {
if (board[i][j] == 0) { // checks if the tile is empty or not
count++; // if the tile is empty increment the counter
}
}
}
if (count == 0) { // if there are no empty tiles, exit the function
return;
}
int randomIndex = rand() % count; // generates a random number between 0 and count-1
count = 0; // reset the count
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
if (board[i][j] == 0) { // again checks if the tile is empty or not
if (count == randomIndex) { // if the count is equal to the random number generated before
board[i][j] = (rand() % 2 + 1) * 2; // generates either 2 or 4 randomly
return;
}
count++; // increment the count for each empty tile
}
}
}
}
void moveUp() {
    bool hasMoved = false;
    for (int j = 0; j < size; j++) {
        for (int i = 1; i < size; i++) {
            if (board[i][j] == 0) continue;
            int k = i - 1;
            while (k >= 0 && board[k][j] == 0) k--;
            if (k == -1) {
                board[0][j] = board[i][j];
                board[i][j] = 0;
                hasMoved = true;
            } else if (board[k][j] == board[i][j]) {
                board[k][j] *= 2;
                score += board[k][j];
                if (score > highScore) highScore = score;
                board[i][j] = 0;
                hasMoved = true;
            } else if (k + 1 != i) {
                board[k + 1][j] = board[i][j];
                board[i][j] = 0;
                hasMoved = true;
            }
        }
    }
    if (hasMoved) addRandomTile();
}

void moveDown() {
    bool hasMoved = false;
    for (int j = 0; j < size; j++) {
        for (int i = size - 2; i >= 0; i--) {
            if (board[i][j] == 0) continue;
            int k = i + 1;
            while (k < size && board[k][j] == 0) k++;
            if (k == size) {
                board[size - 1][j] = board[i][j];
                board[i][j] = 0;
                hasMoved = true;
            } else if (board[k][j] == board[i][j]) {
                board[k][j] *= 2;
                score += board[k][j];
                if (score > highScore) highScore = score;
                board[i][j] = 0;
                hasMoved = true;
            } else if (k - 1 != i) {
                board[k - 1][j] = board[i][j];
                board[i][j] = 0;
                hasMoved = true;
            }
        }
    }
    if (hasMoved) addRandomTile();
}

void moveLeft() {
    bool hasMoved = false;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (board[i][j] == 0) continue;
            int k = j - 1;
            while (k >= 0 && board[i][k] == 0) k--;
            if (k == -1) {
                board[i][0] = board[i][j];
                board[i][j] = 0;
                hasMoved = true;
            } else if (board[i][k] == board[i][j]) {
                board[i][k] *= 2;
                score += board[i][k];
                if (score > highScore) highScore = score;
                board[i][j] = 0;
                hasMoved = true;
            } else if (k + 1 != j) {
                board[i][k + 1] = board[i][j];
                board[i][j] = 0;
                hasMoved = true;
            }
        }
    }
    if (hasMoved) addRandomTile();
}

void moveRight() {
bool hasMoved = false;
for (int i = 0; i < size; i++) {
for (int j = size - 2; j >= 0; j--) {
if (board[i][j] == 0) continue;
int k = j + 1;
while (k < size && board[i][k] == 0) k++;
if (k == size) {
board[i][size - 1] = board[i][j];
board[i][j] = 0;
hasMoved = true;
} else if (board[i][k] == board[i][j]) {
board[i][k] *= 2;
score += board[i][k];
if (score > highScore) highScore = score;
board[i][j] = 0;
hasMoved = true;
} else if (k - 1 != j) {
board[i][k - 1] = board[i][j];
board[i][j] = 0;
hasMoved = true;
}
}
}
if (hasMoved) addRandomTile();
}


bool isGameOver() { // checks if the game is over or not
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
if (board[i][j] == 0) { // if there is an empty tile, the game is not over
return false;
}
if (j < size - 1 && board[i][j] == board[i][j + 1]) { // if there are two adjacent tiles with the same value, the game is not over
return false;
}
if (i < size - 1 && board[i][j] == board[i + 1][j]) { // if there are two adjacent tiles with the same value, the game is not over
return false;
}
}
}
return true; // if none of the above conditions are true, the game is over
}
