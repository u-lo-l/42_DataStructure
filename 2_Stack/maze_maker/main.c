#include "maze_create.h"
#include <unistd.h>
int main(int argc, char **argv)
{
	int total_rows, total_cols;
	switch (argc)
	{
		case 1 :
			srand(time(NULL));
			total_rows = rand() % 50;
			total_cols = rand() % 50;
			break;
		case 2 :
			if (atoi(argv[1]) > 2)
				total_rows = total_cols = atoi(argv[1]);
			else
				return (EXIT_FAILURE);
			break ;
		case 3 :
			if (atoi(argv[1]) > 2 && atoi(argv[2]) > 2)
			{
				total_rows = atoi(argv[1]);
				total_cols = atoi(argv[2]);
			}
			else
				return (EXIT_FAILURE);
			break ;
		default :
			printf("WRONG NUMBER OF ARGS\n");
			return (EXIT_FAILURE);
	}
	maze *random_maze;
	printf("CREATE NEW RANDOM MAZE\n");
	sleep(1);
	system("clear");
	random_maze = initRandomMaze(total_rows, total_cols);
	printMaze(*random_maze);
	deleteMaze(random_maze);	
}
