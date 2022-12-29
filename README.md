# Game of Life

The Game of Life is a cellular automaton created by mathematician John Horton Conway in 1970. It is a zero-player game, meaning that once it is set up, it runs on its own, with no further input from the user.
## Rules

The Game of Life is played on a grid of cells, where each cell can be either alive or dead. At each step of the game, the state of each cell is updated based on the following rules:

If a cell is alive and has exactly 2 or 3 alive neighbors, it stays alive.
If a cell is alive and has fewer than 2 or more than 3 alive neighbors, it dies.
If a cell is dead and has exactly 3 alive neighbors, it comes to life.

## Usage

To run the game, compile and run the main.c file using a C compiler. The game will run for 10 steps, printing the state of the grid at each step. The size of the grid can be changed by modifying the SIZE constant in the code.

#### I hope you enjoy playing the Game of Life!
