#ifndef _GRAPH_TRAVERSAL_H_
#define _GRAPH_TRAVERSAL_H_

#include "Stack/linkedstack.h"
#include "Queue/linkedqueue.h"
#include "ArrayGraph/arraygraph.h"
#include "LinkedGraph/linkedgraph.h"

int traversal_DFS_iter_AG(ArrayGraph *AG, int startID);
int traversal_DFS_iter_LG(LinkedGraph *LG, int startID);

int traversal_BFS_iter_AG(ArrayGraph *AG, int startID));
int traversal_BFS_iter_LG(LinkedGraph *LG, int startID);

#endif