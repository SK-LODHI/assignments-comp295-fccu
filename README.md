# assignments-comp295-fccu
for the assignments in comp295
# explaination
The program uses a '2D' integer array board to represent the game board. The constant size defines the size of the board (in this case, 4x4), and the constant MAX_VALUE defines the maximum value of a tile on the board (in this case, 2048). The score variable keeps track of the player's current score, and the highScore variable keeps track of the highest score achieved in the game so far.

# The program provides the following functions:

This is a C++ program for the popular game "2048". The program uses a 2D array to represent the game board and includes functions to perform the game's main operations, such as moving the tiles and adding random tiles. The program uses a loop to continuously prompt the user for input and update the game board accordingly.

The main() function starts by calling clearBoard() to initialize the board with all zeros and then adds two random tiles by calling addRandomTile() twice. The game board is then printed to the console by calling printBoard(). The loop in main() continuously prompts the user for input, calling the appropriate function (such as moveUp()) based on the user's choice. The loop continues until the game is over, which is determined by the isGameOver() function.

The printBoard() function prints the game board to the console in a formatted way, with the score and high score displayed at the top.

The clearBoard() function sets all elements of the board array to 0.

The addRandomTile() function adds a random tile (either a 2 or a 4) to a random empty space on the game board.

The moveUp(), moveDown(), moveLeft(), and moveRight() functions are responsible for moving the tiles in the specified direction. They iterate over the board and move each tile as far as possible in the given direction. If two adjacent tiles have the same value, they are merged together into one tile with twice the value.

The isGameOver() function checks if the game is over by iterating over the board and checking if there are any empty spaces or adjacent tiles with the same value. If there are no empty spaces and no adjacent tiles with the same value, the game is over.

The program keeps track of the score and high score using the score and highScore variables, respectively.
