#ifndef SHORTESTPATH_H
# define SHORTESTPATH_H
# define INF 2147483647
# include "../linkedgraph.h"

/*Dijkstra*/

int		*dijkstra(LinkedGraph *pGraph, int startVertex);

/*Floyd*/

int		**initDistArray(LinkedGraph *pGraph);

void	floyd(int **distArray, LinkedGraph);

#endif
