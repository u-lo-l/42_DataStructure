#include "maze.h"

int main()
{
	maze *map = initRandomMaze(31, 57);
	printMaze(*map);
	deleteMaze(map);
}