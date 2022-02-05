#include "maze_data.h"
#include "maze.h"
#include "doublylist.h"
int main()
{
	maze *map = initRandomMaze(21, 21);
	createPath(map);

	// printMaze(*map);
	deleteMaze(map);
}