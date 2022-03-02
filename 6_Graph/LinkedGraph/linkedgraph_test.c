#include "linkedgraph.h"
#include <stdio.h>
#include <stdlib.h>
#define NODE_COUNT 8
int main()
{
	LinkedGraph *graph;

	graph = createLinkedGraph(NODE_COUNT);
	displayLinkedGraph(graph);
	printf("ADD Vertex\n");
	for (int i = 0 ; i < NODE_COUNT ; i++)
		addVertexLG(graph, i);
	displayLinkedGraph(graph);
	printf("ADD EDGE\n");
	addEdgeLG(graph, 0, 1);
	printf("\033[0;31mADD 0->1\n\033[0m");
	displayLinkedGraph(graph);
	addEdgeLG(graph, 0, 2);
	printf("\033[0;31mADD 0->2\n\033[0m");
	displayLinkedGraph(graph);
	addEdgeLG(graph, 1, 3);
	printf("\033[0;31mADD 1->3\n\033[0m");
	displayLinkedGraph(graph);
	addEdgeLG(graph, 1, 4);
	printf("\033[0;31mADD 1->4\n\033[0m");
	displayLinkedGraph(graph);
	addEdgeLG(graph, 2, 5);
	printf("\033[0;31mADD 2->5\n\033[0m");
	displayLinkedGraph(graph);
	addEdgeLG(graph, 2, 6);
	printf("\033[0;31mADD 2->6\n\033[0m");
	displayLinkedGraph(graph);
	addEdgeLG(graph, 3, 7);
	printf("\033[0;31mADD 3->7\n\033[0m");
	displayLinkedGraph(graph);
	addEdgeLG(graph, 4, 5);
	printf("\033[0;31mADD 4->5\n\033[0m");
	displayLinkedGraph(graph);
	printf("REM Vertex\n");
	removeVertexLG(graph, 2);
	printf("\033[0;31mREM 2\n\033[0m");
	displayLinkedGraph(graph);
	removeVertexLG(graph, 5);
	printf("\033[0;31mREM 5\n\033[0m");
	displayLinkedGraph(graph);
	printf("REM EDGE\n");
	removeEdgeLG(graph, 0, 1);
	printf("\033[0;31mREM 0->1\n\033[0m");
	displayLinkedGraph(graph);
	removeEdgeLG(graph, 3, 1);
	printf("\033[0;31mREM 3->1\n\033[0m");
	displayLinkedGraph(graph);
	removeEdgeLG(graph, 4, 1);
	printf("\033[0;31mREM 4->1\n\033[0m");
	displayLinkedGraph(graph);
	removeEdgeLG(graph, 7, 3);
	printf("\033[0;31mREM 7->3\n\033[0m");
	displayLinkedGraph(graph);
	deleteLinkedGraph(graph);
	return 0;
}
