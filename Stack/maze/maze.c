#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "doublylist.h"

point *initPoint(int row, int col)
{
	point *P = malloc(sizeof(point));
	if (!P)
		return (NULL);
	P->row = row;
	P->col = col;
	return (P);
}

maze *initRandomMaze(int rows, int cols)
{
	srand(time(NULL));

	maze *M;
	M = malloc(sizeof(maze));

	M->total_rows = rows;
	M->total_cols = cols;

	M->s_point.row = rand()%(rows - 2) + 1;
	M->s_point.col = 0;

	M->e_point.row = rand()%(rows - 2) + 1;
	M->e_point.col = cols - 1;

	M->map = malloc(sizeof(char*) * rows);
	for (int i = 0 ; i < rows ; i++)
		M->map[i] = calloc(1, sizeof(char) * cols);
	
	M->map[M->s_point.row][M->s_point.col] = 2;
	M->map[M->e_point.row][M->e_point.col] = 3;
	return (M);
}

void deleteMaze(maze *M)
{
	free(M->map);
	free(M);
}

/*
 * check four nearby blocks by clockwise from North(N->E->S->W)
 * And append to list if it is proper.
*/
static void getCandidates(maze *M, DoublyList *L, point curr_pos);
static void linkAvailablePath(maze *M, point curr_pos);
void createPath(maze *M)
{
	DoublyList		*exploreList;
	point			currPos;
	DoublyListNode	*currPosNode;

	exploreList = createDoublyList();
	M->map[M->s_point.row][M->s_point.col + 1] = 1;
	currPos.row = M->s_point.row;
	currPos.col = 1;
	getCandidates(M, exploreList, currPos);

	displayDoublyList(exploreList);
		
	while (!isDoublyListEmpty(exploreList))
	// for (int i = 0 ; i < 30 ; i ++)
	{
		srand(time(NULL));
		int random = rand();
		int listSize = getDoublyListLength(exploreList);
		printf("FOR_S\n");
		printf("INDEX = %d\n", random % (listSize/2 + 1));
		currPosNode = getDLElement(exploreList, random % (listSize/2 + 1));
		currPos.col = currPosNode->data.col;
		currPos.row = currPosNode->data.row;
		removeDLElement(exploreList, random % (listSize/2 + 1));
		printMaze(*M);
		printf("target_pos = (%d,%d)\n", currPos.row , currPos.col);
		printf("One candidate selected\n");
		displayDoublyList(exploreList);
		linkAvailablePath(M, currPos);
		printf("Path linked\n");
		printMaze(*M);
		getCandidates(M, exploreList, currPos);
		printf("Add new candidates\n");
		displayDoublyList(exploreList);
		printf("FOR_N\n\n");
		// free(currPosNode);
	}
	M->map[M->e_point.row][M->e_point.col - 1] = 1;
	displayDoublyList(exploreList);
	deleteDoublyList(exploreList);
}

static void printMazeChar(char map_status);
void printMaze(maze M)
{
	int r,c;

	for (r = 0 ; r < M.total_rows ; r++)
	{
		for (c = 0 ; c < M.total_cols ; c++)
			printMazeChar(M.map[r][c]);
		printf("\n");
	}
}

static void printMazeChar(char map_status)
{
	if (map_status == 0)		// wall : empty square
		printf("\u25A2 ");
	else if (map_status == 1)	// path : filled square
		printf("\u25A0 ");
	else if (map_status == 2)	// start_point : circle
		printf("\u25C9 ");
	else if (map_status == 3)	// end_point : diamond
		printf("\u25C8 ");
	else if (map_status == 4)	// cadidate : dotted circle
		printf("\u25CF ");
	else if (map_status == -1)	// visited
		printf("\u25A6 ");
	return ;
}

static void getCandidates(maze *M, DoublyList *L, point curr_pos)
{
	printf("<getCandidates>\n");
	srand(time(NULL));
	int random = rand();
	int r, c;
	int direction[4][2] = {{-2, 0}, {0, 2}, {2, 0},{0, -2}};
	DoublyListNode candidateNode;

	for (int i = 0 ; i < 4 ; i++)
	{
		printf("%d\n", (random + i) % 4);
		r = curr_pos.row + direction[(random + i) % 4][0];
		c = curr_pos.col + direction[(random + i) % 4][1];
		if (r > 0 && c > 0 && r < M->total_rows - 1 && c < M->total_cols - 1)
			if (M->map[r][c] == 0)
			{
				candidateNode.data.row = r;
				candidateNode.data.col = c;
				printf("cord -> (%d, %d)\n", r, c);
				addDLElement(L, 0, candidateNode);
				M->map[r][c] = 4;
			}
	}
}

static void linkAvailablePath(maze *M, point curr_pos)
{
	printf("<LinkAvaiablePath>\n");
	srand(time(NULL));
	int random = rand();
	int r, c;
	int direction[4][2] = {{-2, 0}, {0, 2}, {2, 0},{0, -2}};

	for (int i = 0 ; i < 4 ; i++)
	{
		printf("%d\n", (random + i) % 4);
		r = curr_pos.row - direction[(random + i) % 4][0];
		c = curr_pos.col - direction[(random + i) % 4][1];
		if (r > 0 && c > 0 && r < M->total_rows - 1 && M->total_cols - 1)
			if (M->map[r][c] == 1) // 1 : path, 2 : start point, 3 : end point
			{
				printf("cord -> (%d, %d)\n", r, c);
				M->map[curr_pos.row][curr_pos.col] = 1;
				r = curr_pos.row - direction[(random + i) % 4][0] / 2;
				c = curr_pos.col - direction[(random + i) % 4][1] / 2;
				M->map[r][c] = 1;
				break ;
			}
	}
}
