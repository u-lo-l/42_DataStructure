#ifndef MAZE_H
# define MAZE_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "maze_data.h"

point *initPoint(int row, int col);

maze *initRandomMaze(int rows, int cols);

void deleteMaze(maze *M);

void printMaze(maze M);

#endif