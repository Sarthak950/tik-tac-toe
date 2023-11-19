# tik tac toe using the MinMax algorithm

## How to run
```
git clone https://github.com/Sarthak950/tik-tac-toe.git
cd tik-tac-toe
g++ -O3 -std=c++11 main.cpp -o main && ./main
```
## How to play
The game is played on a grid that's 3 squares by 3 squares.

Enter the position from 1 to 9 to place your move.

The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.

When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.

## Min Max algorithm 
The MinMax algorithm is used to find the optimal move for a player assuming that the opponent is also playing optimally.

The MinMax algorithm considers the board as a tree with each node representing a board state and each edge representing a possible move.
The MinMax algorithm recursively evaluates the nodes of the tree and returns the best move for the player.
