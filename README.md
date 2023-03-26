# assignments-comp295-fccu
for the assignments in comp295
# explaination
The program uses a '2D' integer array board to represent the game board. The constant size defines the size of the board (in this case, 4x4), and the constant MAX_VALUE defines the maximum value of a tile on the board (in this case, 2048). The score variable keeps track of the player's current score, and the highScore variable keeps track of the highest score achieved in the game so far.

# The program provides the following functions:

clearBoard(): sets all elements of the board array to 0.
printBoard(): prints the current state of the board and the player's score.
addRandomTile(): adds a new tile with a value of either 2 or 4 to a randomly chosen empty space on the board.
slideTiles(int direction): slides all tiles on the board in the specified direction (up, down, left, or right), merging tiles with the same value along the way.
isGameOver(): checks if the game is over by iterating over all tiles on the board and checking if there are any empty spaces or adjacent tiles with the same value.
In the main() function, the program initializes the random number generator, clears the board, adds two random tiles, and enters a loop where it repeatedly asks the player for input until the game is over or the player quits. If the game is over, the program prints the final score and the highest score achieved so far.
