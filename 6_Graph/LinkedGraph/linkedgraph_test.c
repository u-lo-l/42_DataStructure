#include "linkedgraph.h"
#include "./MinSpanningTree/spanningTree.h"
#include "./ShortestPath/shortestPath.h"
#include <stdio.h>
#include <stdlib.h>
#define NODE_COUNT 8

void LinkedGraph_test();

void Kruskal_test();
void Kruskal_test_bad();

void Prim_test_directed();
void Prim_test_unconnected();
void Prim_test();

void Prim_test();

void Dijkstra_test();

void Floyd_test();

int main()
{
	// printf("LinkedGraph Test\n");
	// LinkedGraph_test();

	// printf("\033[1;48;5;117;38;5;16mKruskal Test\033[0m\n");
	// Kruskal_test();
	// printf("\n\n");
	// printf("\033[1;48;5;197;38;5;16mKruskal Test BAD\033[0m\n");
	// Kruskal_test_bad();
	// printf("\n\n");

	// printf("\033[1;48;5;117;38;5;16mPrim Test\033[0m\n");
	// Prim_test_unconnected();
	// printf("\n\n");
	// Prim_test_directed();
	// printf("\n\n");
	// Prim_test();
	// printf("\n\n");
	
	printf("Dijkstra test\n");
	Dijkstra_test();

	printf("FLOYD test\n");
	Floyd_test();

}

void LinkedGraph_test()
{
	LinkedGraph *graph;

	graph = createLinkedDirectedGraph(8);
	for (int i = 0 ; i < 8 ; i++)
		addVertexLG(graph, i);
	addEdgeLG(graph, 0, 2);
	addEdgeLG(graph, 0, 1);
	addEdgeLG(graph, 1, 3);
	addEdgeLG(graph, 1, 4);
	addEdgeLG(graph, 2, 5);
	addEdgeLG(graph, 2 ,6);
	addEdgeLG(graph, 3, 7);
	addEdgeLG(graph, 4, 5);
	displayLinkedGraph(graph);
	if (isGraphConnected(graph))
		printf("CONNECTED\n");
	else
		printf("NOT CONNECTED\n");
	printf("DFS\n");
	traversal_DFS_iter_LG(graph, 0);
	printf("BFS\n");
	traversal_BFS_iter_LG(graph, 0);
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
	if (minSpanningTree)
		printf("\033[0;32mRESULT\033[0m\n");
	displayLinkedGraph(minSpanningTree);
	deleteLinkedGraph(mainGraph);
	deleteLinkedGraph(minSpanningTree);
}
void Prim_test_unconnected()
{
	LinkedGraph *mainGraph = createLinkedGraph(6);
	LinkedGraph *minSpanningTree;
	printf("\033[0;34mInitGraph\n\033[0m");
	for (int i = 0 ; i < 6 ; i++)
		addVertexLG(mainGraph, i);
	addEdgewithWeightLG(mainGraph, 0, 1, 4);
	addEdgewithWeightLG(mainGraph, 0, 2, 3);
	addEdgewithWeightLG(mainGraph, 1, 2, 2);
	addEdgewithWeightLG(mainGraph, 3, 4, 1);
	addEdgewithWeightLG(mainGraph, 3, 5, 5);
	addEdgewithWeightLG(mainGraph, 4, 5, 6);
	printf("\033[0;34m\nInitGraph DONE\033[0m\n");
	displayLinkedGraph(mainGraph);
	printf("\033[0;33m\nSTART PRIM\033[0m\n");
	minSpanningTree = prim(mainGraph);
	if (minSpanningTree)
		printf("\033[0;32mRESULT\033[0m\n");
	displayLinkedGraph(minSpanningTree);
	deleteLinkedGraph(mainGraph);
	deleteLinkedGraph(minSpanningTree);
}

void Prim_test_directed()
{
	LinkedGraph *mainGraph = createLinkedDirectedGraph(6);
	LinkedGraph *minSpanningTree;
	printf("\033[0;34mInitGraph\n\033[0m");
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
	if (minSpanningTree)
		printf("\033[0;32mRESULT\033[0m\n");
	displayLinkedGraph(minSpanningTree);
	deleteLinkedGraph(mainGraph);
	deleteLinkedGraph(minSpanningTree);
}

void Dijkstra_test()
{
	LinkedGraph *mainGraph = createLinkedGraph(6);
	int			*shortestPath;
	for (int i = 0 ; i < 6 ; i++)
		addVertexLG(mainGraph, i);
	addEdgewithWeightLG(mainGraph, 0, 1, 1);
	addEdgewithWeightLG(mainGraph, 0, 2, 3);
	addEdgewithWeightLG(mainGraph, 1, 2, 2);
	addEdgewithWeightLG(mainGraph, 2, 3, 1);
	addEdgewithWeightLG(mainGraph, 3, 4, 8);
	addEdgewithWeightLG(mainGraph, 3, 5, 3);
	addEdgewithWeightLG(mainGraph, 4, 5, 4);
	printf("\033[0;34m\nInitGraph DONE\033[0m\n");
	displayLinkedGraph(mainGraph);
	for (int i = 0 ; i < 6 ; i++)
	{
		printf("\033[0;33m\nSTART Dijkstra from %d\033[0m\n", i);
		shortestPath = dijkstra(mainGraph, i);
		printIntArray(shortestPath, 6);		
		free(shortestPath);
	}
	deleteLinkedGraph(mainGraph);
}

void Floyd_test()
{
	LinkedGraph *mainGraph = createLinkedGraph(6);
	int			**distMatrix;
	for (int i = 0 ; i < 6 ; i++)
		addVertexLG(mainGraph, i);
	addEdgewithWeightLG(mainGraph, 0, 1, 1);
	addEdgewithWeightLG(mainGraph, 0, 2, 3);
	addEdgewithWeightLG(mainGraph, 1, 2, 2);
	addEdgewithWeightLG(mainGraph, 2, 3, 1);
	addEdgewithWeightLG(mainGraph, 3, 4, 8);
	addEdgewithWeightLG(mainGraph, 3, 5, 3);
	addEdgewithWeightLG(mainGraph, 4, 5, 4);
	printf("\033[0;34m\nInitGraph DONE\033[0m\n");
	displayLinkedGraph(mainGraph);

	distMatrix = floyd(mainGraph);
	printIntMatrix(distMatrix, 6, 6);
	
	deleteIntMatrix(distMatrix, 6);
	deleteLinkedGraph(mainGraph);
}
