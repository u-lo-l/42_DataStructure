#include "kruskal.h"
#include <stdio.h>

LinkedGraph *initGraph(void);

int main()
{
	LinkedGraph *mainGraph;
	LinkedGraph *minSpanningTree;
	mainGraph = initGraph();

	printf("\033[0;33m\nSTART KRUSKAL\033[0m\n");
	minSpanningTree = kruskal(mainGraph);
	printf("\033[0;32mRESULT\033[0m\n");
	displayLinkedGraph(minSpanningTree);

	deleteLinkedGraph(mainGraph);
	deleteLinkedGraph(minSpanningTree);
}


LinkedGraph *initGraph(void)
{
	LinkedGraph *graph = createLinkedGraph(6);
	printf("\033[0;34mInitGraph\n\033[0m");
	displayLinkedGraph(graph);
	for (int i = 0 ; i < 6 ; i++)
		addVertexLG(graph, i);
	addEdgewithWeightLG(graph, 0, 1, 4);
	addEdgewithWeightLG(graph, 0, 2, 3);
	addEdgewithWeightLG(graph, 1, 2, 2);
	addEdgewithWeightLG(graph, 2, 3, 1);
	addEdgewithWeightLG(graph, 3, 4, 1);
	addEdgewithWeightLG(graph, 3, 5, 5);
	addEdgewithWeightLG(graph, 4, 5, 6);
	printf("\033[0;34m\nInitGraph DONE\033[0m\n");
	displayLinkedGraph(graph);
	return (graph);
}