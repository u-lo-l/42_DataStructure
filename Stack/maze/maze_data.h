#ifndef MAZE_DATA_H
# define MAZE_DATA_H

# define WALL				0
# define PATH 				1
# define S_POINT			2
# define E_POINT			3
# define CANDIDATE			4
# define VISITED			5
# define VISITED_BUT_BAD	6

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