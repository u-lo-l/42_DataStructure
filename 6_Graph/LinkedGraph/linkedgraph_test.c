#include "linkedgraph.h"
#include "./MinSpanningTree/Kruskal/kruskal.h"
#include "./MinSpanningTree/Prim/prim.h"
#include <stdio.h>
#include <stdlib.h>
#define NODE_COUNT 8

void LinkedGraph_test();

void Kruskal_test();
void Kruskal_test_bad();

void Prim_test();

int main()
{
	// printf("LinkedGraph Test\n");
	// LinkedGraph_test();

	// printf("Kruskal Test\n");
	// Kruskal_test();

	// printf("\n\nKruskal Test BAD\n");
	// Kruskal_test_bad();

	printf("Prim Test\n");
	Prim_test();
}

void LinkedGraph_test()
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
	// printf("REM EDGE\n");
	// removeEdgeLG(graph, 0, 1);
	// printf("\033[0;31mREM 0->1\n\033[0m");
	// displayLinkedGraph(graph);
	// removeEdgeLG(graph, 3, 1);
	// printf("\033[0;31mREM 3->1\n\033[0m");
	// displayLinkedGraph(graph);
	// removeEdgeLG(graph, 4, 1);
	// printf("\033[0;31mREM 4->1\n\033[0m");
	// displayLinkedGraph(graph);
	// removeEdgeLG(graph, 7, 3);
	// printf("\033[0;31mREM 7->3\n\033[0m");
	// displayLinkedGraph(graph);
	deleteLinkedGraph(graph);
}

void Kruskal_test()
{
	LinkedGraph *mainGraph = createLinkedGraph(6);
	LinkedGraph *minSpanningTree;
	for (int i = 0 ; i < 6 ; i++)
		addVertexLG(mainGraph, i);
	addEdgewithWeightLG(mainGraph, 0, 1, 4);
	addEdgewithWeightLG(mainGraph, 0, 2, 3);
	addEdgewithWeightLG(mainGraph, 1, 2, 2);
	addEdgewithWeightLG(mainGraph, 2, 3, 1);
	addEdgewithWeightLG(mainGraph, 3, 4, 1);
	addEdgewithWeightLG(mainGraph, 3, 5, 5);
	addEdgewithWeightLG(mainGraph, 4, 5, 6);
	printf("\033[0;34m\nInitGraph DONE\033[0m\n");
	displayLinkedGraph(mainGraph);
	printf("\033[0;33m\nSTART KRUSKAL\033[0m\n");
	minSpanningTree = kruskal(mainGraph);
	if (minSpanningTree == NULL)
	{
		printf("NULL\n");
		deleteLinkedGraph(mainGraph);
		return ;
	}
	printf("\033[0;32mRESULT\033[0m\n\n");
	displayLinkedGraph(minSpanningTree);
	deleteLinkedGraph(mainGraph);
	deleteLinkedGraph(minSpanningTree);
}
void Kruskal_test_bad()
{
	LinkedGraph *mainGraph = createLinkedGraph(6);
	LinkedGraph *minSpanningTree;
	for (int i = 0 ; i < 6 ; i++)
		addVertexLG(mainGraph, i);
	addEdgewithWeightLG(mainGraph, 0, 1, 4);
	addEdgewithWeightLG(mainGraph, 0, 2, 3);
	addEdgewithWeightLG(mainGraph, 1, 2, 2);
	// addEdgewithWeightLG(mainGraph, 2, 3, 1);
	addEdgewithWeightLG(mainGraph, 3, 4, 1);
	addEdgewithWeightLG(mainGraph, 3, 5, 5);
	addEdgewithWeightLG(mainGraph, 4, 5, 6);
	printf("\033[0;34m\nInitGraph DONE\033[0m\n");
	displayLinkedGraph(mainGraph);
	printf("\033[0;33m\nSTART KRUSKAL\033[0m\n");
	minSpanningTree = kruskal(mainGraph);
	if (minSpanningTree == NULL)
	{
		printf("NULL\n");
		deleteLinkedGraph(mainGraph);
		return ;
	}
	printf("\033[0;32mRESULT\033[0m\n");
	displayLinkedGraph(minSpanningTree);
	deleteLinkedGraph(mainGraph);
	deleteLinkedGraph(minSpanningTree);
}


void Prim_test()
{
	LinkedGraph *mainGraph = createLinkedGraph(6);
	LinkedGraph *minSpanningTree;
	printf("\033[0;34mInitGraph\n\033[0m");
	displayLinkedGraph(mainGraph);
	for (int i = 0 ; i < 6 ; i++)
		addVertexLG(mainGraph, i);
	addEdgewithWeightLG(mainGraph, 0, 1, 4);
	addEdgewithWeightLG(mainGraph, 0, 2, 3);
	addEdgewithWeightLG(mainGraph, 1, 2, 2);
	addEdgewithWeightLG(mainGraph, 2, 3, 1);
	addEdgewithWeightLG(mainGraph, 3, 4, 1);
	addEdgewithWeightLG(mainGraph, 3, 5, 5);
	addEdgewithWeightLG(mainGraph, 4, 5, 6);
	printf("\033[0;34m\nInitGraph DONE\033[0m\n");
	displayLinkedGraph(mainGraph);
	printf("\033[0;33m\nSTART PRIM\033[0m\n");
	minSpanningTree = prim(mainGraph);
	printf("\033[0;32mRESULT\033[0m\n");
	displayLinkedGraph(minSpanningTree);
	deleteLinkedGraph(mainGraph);
	deleteLinkedGraph(minSpanningTree);
}