#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../../linkedgraph.h"
#include "../../MinHeap/heap.h"

/* sort Edges by min heap*/
heap  *sortEdge(LinkedGraph *LG);

/* check some edge makes circular graph*/
int	getUnionParent(int *circularTable, int a);
void unionParent(int *circularTable, int a, int b);
int	findParent(int *circularTable, int a, int b);

/* kruskal*/
LinkedGraph	*kruskal(LinkedGraph *LG);

#endif