#include <stdio.h>

#define SIZE 10  // size of the grid

// function prototypes
void initialize_grid(int grid[SIZE][SIZE]);
void print_grid(int grid[SIZE][SIZE]);
void update_grid(int grid[SIZE][SIZE]);
int count_neighbors(int grid[SIZE][SIZE], int x, int y);

int main(void) {
  int grid[SIZE][SIZE];  // grid representing the cells

  // initialize the grid
  initialize_grid(grid);

  // run the simulation for 10 steps
  for (int i = 0; i < 10; i++) {
    // print the current state of the grid
    print_grid(grid);

    // update the grid for the next step
    update_grid(grid);
  }

  return 0;
}

// function to initialize the grid with random values (0 or 1)
void initialize_grid(int grid[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      grid[i][j] = rand() % 2;  // assign a random value of 0 or 1
    }
  }
}

// function to print the current state of the grid
void print_grid(int grid[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// function to update the grid for the next step
void update_grid(int grid[SIZE][SIZE]) {
  int new_grid[SIZE][SIZE];  // grid to store the new state

  // compute the new state of each cell
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      int neighbors = count_neighbors(grid, i, j);  // count the number of alive neighbors

      // apply the rules of the game of life
      if (grid[i][j] == 1) {
        // if the cell is alive, it will stay alive if it has 2 or 3 alive neighbors,
        // otherwise it will die
        if (neighbors == 2 || neighbors == 3) {
          new_grid[i][j] = 1;
        } else {
          new_grid[i][j] = 0;
        }
      } else {
        // if the cell is dead, it will come to life if it has exactly 3 alive neighbors,
        // otherwise it will stay dead
        if (neighbors == 3) {
          new_grid[i][j] = 1;
        } else {
          new_grid[i][j] = 0;
        }
      }
    }
  }

  // copy the new state to the main grid
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      grid[i][j] = new_grid[i][j];
    }
  }
}

          
// function to count the number of alive neighbors of a cell
int count_neighbors(int grid[SIZE][SIZE], int x, int y) {
  int count = 0;

  // check the cells in the 3x3 grid around the given cell
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      // make sure we're not out of bounds
      if (i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
        // don't count the cell itself, only count its neighbors
        if (!(i == x && j == y)) {
          count += grid[i][j];
        }
      }
    }
  }

  return count;
}
