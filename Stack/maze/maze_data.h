#ifndef MAZE_DATA_H
# define MAZE_DATA_H

#define NUM_DIRECTIONS 4

enum PosStatus 
{ 
	VISITED = -1,
	WALL = 0,
	PATH = 1,
	S_POINT = 2,
	E_POINT = 3
};

typedef struct positionType
{
	int row;
	int col;
} point;

typedef struct mazeType
{
	int 	total_rows;
	int 	total_cols;
	point	s_point;
	point	e_point;
	char	**map;
} maze;

#endif