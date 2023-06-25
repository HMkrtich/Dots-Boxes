# Dots and Boxes Game with Minimax and Alpha-Beta Pruning

This is an implementation of the Dots and Boxes game in C++, using the minimax algorithm with alpha-beta pruning to enable an AI player to play against a human player. The minimax algorithm is a decision-making algorithm commonly used in game theory and artificial intelligence, while alpha-beta pruning is an optimization technique used to reduce the search space of the minimax algorithm.

## Implementation Details

The implementation consists of four main files: Box, Board, MySet, and Game.

 - Box represents a single box on the game board, and contains information about its state (i.e. whether it has been completed by a player).
 - Board represents the game board, and consists of an array of Box objects. The Board class provides methods to draw lines between dots, check for completed boxes, and determine the available moves.
 - MySet is a custom data structure used to store the available moves.
 - Game is the main class that controls the game logic, including the minimax algorithm with alpha-beta pruning. The Game class provides methods to get the current game state, make a move, check for a winner, and determine the available moves.

The implementation uses a 3-dimensional structure to store the lines. For a square (i, j) the top line is (0, i, j) and the bottom line is (0, i+1, j), the left line is (1, j, i) and the right line is (1, j+1, i). This allows for efficient indexing and manipulation of the lines.


Sure, here's the updated gameplay instructions with the revised format:

## Gameplay

To play the game, a player can choose a move by specifying the coordinates of the box and the direction of the line they want to claim. The coordinates should be nonnegative integers, with the top-left box having coordinates (0, 0) and the bottom-right box having coordinates (n-1, n-1), where n is the size of the board. The direction can be specified using one of the following strings: "left", "top", "right", or "bottom".

For example, to claim the bottom line of the box at coordinates (2, 3), the player would enter 2 3 bottom.

The game will alternate between the human player and the AI player until all boxes have been claimed. The player with the most boxes claimed at the end of the game is declared the winner.

## Credits

This game was created by Mkrtich Hovsepyan for the class Programming in C++. The project was supervised by David Bednárek.
