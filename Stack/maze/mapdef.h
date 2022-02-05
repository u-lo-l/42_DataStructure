#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

// offset: x, y

static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// S
	{1, 0},			// W
	{0, 1},			// E
	{-1, 0}			// N
};

enum PosStatus 
{ 
	VISITED = -1,
	WALL = 0,
	PATH = 1,
	S_POINT = 2,
	E_POINT = 3
};

typedef struct MapPositionType
{
	int x;				// 현재 위치 x좌표.
	int y;				// 현재 위치 y좌표.
	int dir;		// 다음 위치로 이동 방향.
} MapPosition;

#endif
