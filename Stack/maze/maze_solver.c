#include "maze_create.h"
#include "linkedstack.h"

void checkPath(maze *M, StackNode *pos, LinkedStack *path)
{
	srand(time(NULL));

	StackNode *temp_node;
	int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0},{0, -1}}; // 북->동->남->서 방향으로 탐색하기 위한 벡터(?)
	int r, c;
	int index = rand();
	
	M->map[pos->data.row][pos->data.col] = -1; // -1 : visited block
	for (int i = 0 ; i < 4 ; i++)
	{
		index = (index + i) % 4;
		r = pos->data.row + direction[index][0];
		c = pos->data.col + direction[index][1];

		if (M->map[r][c] > 0) // 1 : 갈 수 있는 길 2: 시작점 3: 출구
		{
			temp_node = createLSNode(r,c);
			pushLS(path, *temp_node);
			free(temp_node);
			return ;
		}
	}
	M->map[pos->data.row][pos->data.col] = -2; // -2 : visitied but wrong path
	temp_node = popLS(path);
	free(temp_node);
	return ;
}

LinkedStack	*solveMaze(maze *M)
{
	StackNode 	*curr_position;
	LinkedStack	*path_stack = createLinkedStack();		// 탈출 경로를 위한 스택

	curr_position = createLSNode(M->s_point.row, M->s_point.col);
	pushLS(path_stack, *curr_position);
	printf("START\n");
	while (1)
	{
		checkPath(M, curr_position, path_stack);

		if (curr_position->data.col == (M->total_cols - 1))
		{
			M->map[curr_position->data.row][curr_position->data.col] = -1;
			break ;
		}
		if (isLinkedStackEmpty(path_stack))
		{
			deleteLinkedStack(path_stack);
			path_stack = 0;
			break ;
		}
		free(curr_position);
		curr_position = peekLS(path_stack);
	}
	printf("FINISHED\n");
	free(curr_position);
	return (path_stack);
}

int main()
{
	maze *map = initRandomMaze(25, 45);
	LinkedStack *maze_escape_root;
	printf("!MAP CREATED!\n");
	printMaze(*map);
	maze_escape_root = solveMaze(map);
	if(!maze_escape_root)
		printf("FAILED\n");
	else
	{
		printf("SUCCEED\n");
		maze_escape_root = reverseStack(maze_escape_root);
		printMaze(*map);
		printLinkedStack(maze_escape_root);
	}
	deleteLinkedStack(maze_escape_root);
	deleteMaze(map);
}