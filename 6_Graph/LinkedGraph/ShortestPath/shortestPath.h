#ifndef SHORTESTPATH_H
# define SHORTESTPATH_H
# define INF 2147483647
# include "../linkedgraph.h"

/*Dijkstra*/

int	*dijkstra(LinkedGraph *pGraph, int startVertex);
void printIntArray(int *arr, int size);

/*Floyd*/

int **initMatrix(int sizeOfVertex);
void    initWeightMatix(LinkedGraph *pGraph, int **distMatrix);
int	**floyd(LinkedGraph *pGraph);
void printIntMatrix(int **Matrix, int rows, int cols);
void deleteIntMatrix(int **Matrix, int rows);

#endif
