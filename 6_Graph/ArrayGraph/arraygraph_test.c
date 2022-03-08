#include "arraygraph.h"
#include <stdlib.h>
#include <stdio.h>
#define NODE_COUNT 8
int main()
{
	ArrayGraph *graph;
	graph = createArrayGraph(NODE_COUNT);
	printf("%p\n", graph);
	displayArrayGraph(graph);
	printf("ADD Vertex\n");
	for (int i = 0 ; i < NODE_COUNT ; i++)
		addVertexAG(graph, i);
	displayArrayGraph(graph);
	printf("ADD EDGE\n");
	addEdgeAG(graph, 0, 1);
	addEdgeAG(graph, 0, 2);
	addEdgeAG(graph, 1, 3);
	addEdgeAG(graph, 1, 4);
	addEdgeAG(graph, 2, 5);
	addEdgeAG(graph, 2, 6);
	addEdgeAG(graph, 3, 7);
	addEdgeAG(graph, 4, 5);
	displayArrayGraph(graph);
	/*
	printf("REM Vertex\n");
	removeVertexAG(graph, 2);
	removeVertexAG(graph, 5);
	displayArrayGraph(graph);
	printf("REM EDGE\n");
	removeEdgeAG(graph, 0, 1);
	removeEdgeAG(graph, 3, 1);
	removeEdgeAG(graph, 4, 1);
	removeEdgeAG(graph, 7, 3);
	displayArrayGraph(graph);
	*/
	printf("=======TRAVERSAL========\n");
	traversal_DFS_iter_AG(graph, 0);
	printf("========================\n");

	printf("=======TRAVERSAL========\n");
	traversal_BFS_iter_AG(graph, 0);
	printf("========================\n");
	deleteArrayGraph(graph);
	return 0;
}
