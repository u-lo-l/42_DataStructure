#include "maze_create.h"
#include "linkedlist.h"

static void createPath(maze *M);
maze *initRandomMaze(int rows, int cols)
{
	maze *M;
	M = malloc(sizeof(maze));

	M->total_rows = rows;
	M->total_cols = cols;

	M->s_point.row = rand()%(rows - 2) + 1;
	M->s_point.col = 0;

	M->map = malloc(sizeof(char*) * rows);
	for (int i = 0 ; i < rows ; i++)
		M->map[i] = calloc(1, sizeof(char) * cols);
	
	M->map[M->s_point.row][M->s_point.col] = S_POINT;

	createPath(M);
	return (M);
}

void deleteMaze(maze *M)
{
	for (int i = 0 ; i < M->total_rows; i++)
		free(M->map[i]);
	free(M->map);
	free(M);
}

/*
 * createPath()
 * check four nearby blocks by clockwise from North(N->E->S->W)
 * And append to list if it is proper.
 * 초기상태는 모든 block들이 다 wall인 상태이고
 * start_point를 기점으로 길을 뚫어 나간다.
*/
static void getCandidates(maze *M, LinkedList *L, point curr_pos);
static void linkAvailablePath(maze *M, point curr_pos);
static void createPath(maze *M)
{
	LinkedList	*candidates;
	ListNode	*currPosNode;
	point		posFromStart;
	
	candidates = createLinkedList();

	M->map[M->s_point.row][M->s_point.col + 1] = PATH;
	posFromStart.row = M->s_point.row;
	posFromStart.col = M->s_point.col + 1;
	getCandidates(M, candidates, posFromStart);
	
	while (!isLinkedListEmpty(candidates))
	{
		srand(time(NULL));
		int index = rand() % (getLinkedListLength(candidates) / 2 + 1);
		currPosNode = getLLElement(candidates, index);
		posFromStart.col = currPosNode->data.col;
		posFromStart.row = currPosNode->data.row;
		removeLLElement(candidates, index);
		linkAvailablePath(M, posFromStart);
		getCandidates(M, candidates, posFromStart);
	}
	deleteLinkedList(candidates);

	while(1)
	{
		int r = rand();
		int exit_row = 1 + (r % (M->total_rows - 2));
		if (M->total_cols % 2 == 0)
		{
			if (M->map[exit_row][M->total_cols - 3])
			{
				M->map[exit_row][M->total_cols - 2] = PATH;
				M->map[exit_row][M->total_cols - 1] = E_POINT;
				break;
			}
		}
		else
			if (M->map[exit_row][M->total_cols - 2])
			{
				M->map[exit_row][M->total_cols - 1] = E_POINT;
				break;
			}
	}
}

static void printMazeChar(int map_status);
void printMaze(maze M)
{
	int r,c;

	for (r = 0 ; r < M.total_rows ; r++)
	{
		for (c = 0 ; c < M.total_cols ; c++)
			printMazeChar(M.map[r][c]);
		printf("\n");
	}
	printf("\n");
}

/*
 * 정수 데이터로 구성된 미로를 터미널에 출력하기 위한 부분이다.
 * 2, 3, 4번의 경우 출려과 디버깅을 위해 만들어 놓았다. 굳이 필요 없다.
*/
static void printMazeChar(int map_status)
{
	if (map_status == WALL )	// wall : filed square
		printf("\033[0;33m\u25A2\033[0m ");
	else if (map_status == PATH)	// path : empty square
		printf("\033[1;30m\u25A0\033[0m ");
	else if (map_status == S_POINT)	// start_point : circle
		printf("\033[1;36m\u25C9\033[0m ");
	else if (map_status == E_POINT)	// end_point : diamond
		printf("\033[1;36m\u25C8\033[0m ");
	else if (map_status == CANDIDATE)	// cadidate : filled circle
		printf("\033[1;33m\u25CF\033[0m ");
	else if (map_status == VISITED)	// visited
		printf("\033[1;32m\u25C9\033[0m ");
	else if (map_status == VISITED_BUT_BAD)	// vistied but wrong path;
		printf("\033[1;31m\u2297\033[0m ");
	return ;
}

/* curr_pos 주변의 block들 중에서 뚫을 수 있는 블럭을 선택한다. */
static void getCandidates(maze *M, LinkedList *L, point curr_pos)
{
	int random = rand();
	int r, c;
	int direction[4][2] = {{-2, 0}, {0, 2}, {2, 0},{0, -2}};
	ListNode candidateNode;

	for (int i = 0 ; i < 4 ; i++)
	{
		r = curr_pos.row + direction[(random + i) % 4][0];
		c = curr_pos.col + direction[(random + i) % 4][1];
		if (r > 0 && c > 0 && r < M->total_rows - 1 && c < M->total_cols - 1)
			if (M->map[r][c] == 0)
			{
				candidateNode.data.row = r;
				candidateNode.data.col = c;
				addLLElement(L, 0, candidateNode);
				M->map[r][c] = CANDIDATE;
			}
	}
}

/* 뚫기로 선택한 curr_pos의 주번의 path와 연결한다. */
static void linkAvailablePath(maze *M, point curr_pos)
{
	int random = rand();
	int r, c;
	int direction[4][2] = {{-2, 0}, {0, 2}, {2, 0},{0, -2}};
	for (int i = 0 ; i < 4 ; i++)
	{
		r = curr_pos.row - direction[(random + i) % 4][0];
		c = curr_pos.col - direction[(random + i) % 4][1];
		if (r > 0 && c > 0 && r < M->total_rows - 1 && M->total_cols - 1)
			if (M->map[r][c] == PATH)
			{
				M->map[curr_pos.row][curr_pos.col] = PATH;
				r = curr_pos.row - direction[(random + i) % 4][0] / 2;
				c = curr_pos.col - direction[(random + i) % 4][1] / 2;
				M->map[r][c] = PATH;
				break ;
			}
	}
}