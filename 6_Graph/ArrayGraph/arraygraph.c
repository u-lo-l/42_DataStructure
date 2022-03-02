#include "arraygraph.h"
#include <stdio.h>
#include <stdlib.h>

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *graph;
	if (!(graph = malloc(sizeof(ArrayGraph))))
	{
		printf("1\n");
		return (NULL);
	}
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->graphType = GRAPH_UNDIRECTED;
	
	graph->pVertex = calloc(maxVertexCount, sizeof(int));
	if ((graph->pVertex)==NULL)
	{
		printf("2\n");
		free(graph);
		return (NULL);
	}
	
	graph->ppAdjEdge = malloc(sizeof(int*) * maxVertexCount);
	if (graph->ppAdjEdge == NULL)
	{
		printf("3\n");

		free(graph->pVertex);
		free(graph);
		return (NULL);
	}
	int i = 0;
	for (; i < maxVertexCount ; i++)
	{
		graph->ppAdjEdge[i] = calloc(maxVertexCount, sizeof(int));
		if((graph->ppAdjEdge[i])==NULL)
		{
			printf("4\n");	
			for (; i>=0 ; i--)
				free(graph->ppAdjEdge[i]);
			free(graph->ppAdjEdge);
			free(graph->pVertex);
			free(graph);
			return (NULL);
		}
	}
	return (graph);
}
ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *graph;
	if (!(graph = malloc(sizeof(ArrayGraph))))
	{
		printf("1\n");
		return (NULL);
	}
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->graphType = GRAPH_DIRECTED;
	
	graph->pVertex = calloc(maxVertexCount, sizeof(int));
	if ((graph->pVertex)==NULL)
	{
		printf("2\n");
		free(graph);
		return (NULL);
	}
	
	graph->ppAdjEdge = malloc(sizeof(int*) * maxVertexCount);
	if (graph->ppAdjEdge == NULL)
	{
		printf("3\n");

		free(graph->pVertex);
		free(graph);
		return (NULL);
	}
	int i = 0;
	for (; i < maxVertexCount ; i++)
	{
		graph->ppAdjEdge[i] = calloc(maxVertexCount, sizeof(int));
		if((graph->ppAdjEdge[i])==NULL)
		{
			printf("4\n");	
			for (; i>=0 ; i--)
				free(graph->ppAdjEdge[i]);
			free(graph->ppAdjEdge);
			free(graph->pVertex);
			free(graph);
			return (NULL);
		}
	}
	return (graph);
}

void deleteArrayGraph(ArrayGraph* pGraph)
{
	if (!pGraph) return ;
	for (int i = 0; i < pGraph->maxVertexCount ; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

int isEmptyAG(ArrayGraph* pGraph)
{
	if (!pGraph)
		return (ERROR);
	if (pGraph->currentVertexCount == 0)
		return (TRUE);
	return (FALSE);
}

int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (ERROR);
	if (vertexID + 1> pGraph->maxVertexCount)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == USED)
		return (FALSE);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (TRUE);
}

int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)	return(ERROR);
	return (pGraph->pVertex[vertexID]);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!pGraph)	return (ERROR);
	if (!checkVertexValid(pGraph, fromVertexID)) return (ERROR);
	if (!checkVertexValid(pGraph, toVertexID)) return (ERROR);
	if (pGraph->ppAdjEdge[fromVertexID][toVertexID] == weight)
		return (FALSE);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType = GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (TRUE);
}
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	return (addEdgewithWeightAG(pGraph, fromVertexID,toVertexID, 1));
}
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	return (addEdgewithWeightAG(pGraph, fromVertexID,toVertexID, 0));
}


int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)								return (ERROR);
	if (!checkVertexValid(pGraph, vertexID))	return (FALSE);
	for (int i = 0 ; i < pGraph->maxVertexCount; i++)
	{
		pGraph->ppAdjEdge[i][vertexID] = 0;
		pGraph->ppAdjEdge[vertexID][i] = 0;
	}
	pGraph->pVertex[vertexID] = NOT_USED;
	return (TRUE);
}

void displayArrayGraph(ArrayGraph* pGraph)
{
	if (!pGraph)		return ;
	printf("VERT_ID :");
	for (int i = 0; i < pGraph->maxVertexCount ; i++)
		printf("% 2d|", i);
	printf("\n");
	printf("STATUS  :");
	for (int i = 0; i < pGraph->maxVertexCount ; i++)
		printf("% 2d|", pGraph->pVertex[i]);
	printf("\n");
	
	printf("/");
	for (int i = 0 ; i < pGraph->maxVertexCount; i++)
		printf("--");
	printf("-\\\n");
	for (int i = 0; i < pGraph->maxVertexCount ; i++)
	{
		printf("|");
		for (int j = 0 ; j < pGraph->maxVertexCount ; j++)
			printf("% 2d", pGraph->ppAdjEdge[i][j]);
		printf(" |\n");
	}
	printf("\\");
	for (int i = 0 ; i < pGraph->maxVertexCount; i++)
		printf("--");
	printf("-/\n");
}