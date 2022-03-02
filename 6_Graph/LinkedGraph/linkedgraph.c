#include "linkedgraph.h"
#include <stdlib.h>
#include <stdio.h>

LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *graph;

	graph = calloc(1, sizeof(LinkedGraph));
	if (!graph)	return(NULL);
	graph->maxVertexCount = maxVertexCount;
	graph->graphType = GRAPH_UNDIRECTED;
	graph->pVertex = calloc(maxVertexCount, sizeof(int));
	if (!graph->pVertex)
	{
		free(graph);
		return (NULL);
	}
	graph->ppAdjEdge = calloc(maxVertexCount, sizeof(LinkedList *));
	if (!graph->ppAdjEdge)
	{
		free(graph->pVertex);
		free(graph);
		return (NULL);
	}
	return (graph);
}
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *graph;

	graph = calloc(1, sizeof(LinkedGraph));
	if (!graph)	return(NULL);
	graph->maxVertexCount = maxVertexCount;
	graph->graphType = GRAPH_DIRECTED;
	graph->pVertex = calloc(maxVertexCount, sizeof(int));
	if (!graph->pVertex)
	{
		free(graph);
		return (NULL);
	}
	graph->ppAdjEdge = calloc(maxVertexCount, sizeof(LinkedList *));
	if (!graph->ppAdjEdge)
	{
		free(graph->pVertex);
		free(graph);
		return (NULL);
	}
	for (int i = 0 ; i < maxVertexCount ; i++)
	{
		graph->ppAdjEdge[i] = createLinkedList();
		if (!graph->ppAdjEdge[i])
		{
			for (; i >= 0 ; i--)
				deleteLinkedList(graph->ppAdjEdge[i]);
			free(graph->ppAdjEdge);
			free(graph->pVertex);
			free(graph);
			return (NULL);
		}
	}
	return (graph);
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	if (!pGraph)	 return ;
	for (int i = 0 ; i < pGraph->maxVertexCount ; i++)
		deleteLinkedList(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

int isEmptyLG(LinkedGraph* pGraph)
{
	if (!pGraph)	return (ERROR);
	if (pGraph->currentVertexCount)
		return (TRUE);
	return (FALSE);
}

int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph) return (ERROR);
	if (vertexID + 1 > pGraph->maxVertexCount) return (FALSE);
	if (pGraph->pVertex[vertexID] == USED) return (FALSE);
	pGraph->pVertex[vertexID] = USED;
	pGraph->ppAdjEdge[vertexID] = createLinkedList();
	if (!pGraph->ppAdjEdge[vertexID]) return (FALSE);
	pGraph->currentVertexCount++;
	return (TRUE);
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, WEIGHT_DEFAULT);
}
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	ListNode	newNode;
	int			result;
	if (!pGraph)	return (ERROR);
	if (!checkVertexValid(pGraph, fromVertexID)) return (FALSE);
	if (!checkVertexValid(pGraph, fromVertexID)) return (FALSE);
	newNode.ID = toVertexID;
	newNode.weight = weight;
	result = addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, newNode);
	if (result == EXIT_FAILURE)	return (FALSE);
	pGraph->currentEdgeCount++;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		newNode.ID = fromVertexID;
		newNode.weight = weight;
		result = addLLElement(pGraph->ppAdjEdge[toVertexID], 0, newNode);
		if (result == EXIT_FAILURE)	return (FALSE);
		pGraph->currentEdgeCount++;
	}
	return (TRUE);
}
int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph) return (ERROR);
	if (pGraph->pVertex[vertexID] == USED) return (TRUE);
	return (FALSE);
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	int pos;
	if (!pGraph)	return (ERROR);
	deleteLinkedList(pGraph->ppAdjEdge[vertexID]);
	pGraph->ppAdjEdge[vertexID] = NULL;
	for (int i = 0 ; i < pGraph->maxVertexCount ; i++)
		removeEdgeLG(pGraph, i, vertexID);
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (TRUE);
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	int target_pos;
	if (!pGraph) return (ERROR);

	if (pGraph->ppAdjEdge[fromVertexID] == NULL)
		return (FALSE);
	target_pos = findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID);
	removeLLElement(pGraph->ppAdjEdge[fromVertexID], target_pos);
	pGraph->currentEdgeCount--;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		target_pos = findGraphNodePosition(pGraph->ppAdjEdge[toVertexID], fromVertexID);
		removeLLElement(pGraph->ppAdjEdge[toVertexID], target_pos);
		pGraph->currentEdgeCount--;
	}
	return (TRUE);
}
void deleteGraphNode(LinkedList* pList, int delVertexID);
int findGraphNodePosition(LinkedList* pList, int vertexID)
{
	int pos;
	ListNode *node;

	if (!pList)	return (ERROR);
	
	for (pos = 0, node = pList->headerNode.pLink ; node != NULL  ; pos++, node = node->pLink)
	{
		if (node->ID == vertexID)
			return (pos);
	}
	return (ERROR);
}

int getEdgeCountLG(LinkedGraph* pGraph)
{
	if (!pGraph) return(ERROR);
	return (pGraph->currentEdgeCount);
}

int getVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph) return(ERROR);
	return (pGraph->currentVertexCount);
}

int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph) return(ERROR);
	return (pGraph->maxVertexCount);
}

int getGraphTypeLG(LinkedGraph* pGraph)
{
	if (!pGraph) return(ERROR);
	return (pGraph->graphType);
}

void displayLinkedGraph(LinkedGraph* pGraph)
{
	if (!pGraph)	return;
	if (pGraph->graphType == GRAPH_DIRECTED)
		printf("DIRECTED_GRAPH\n");
	else
		printf("UNDIRECTED_GRAPH\n");
	printf("|");
	for (int i = 0 ; i < pGraph->maxVertexCount; i++)
		printf("% 2d|", i);
	printf("\n");
	printf("|");
	for (int i = 0 ; i < pGraph->maxVertexCount; i++)
		printf("% 2d|", pGraph->pVertex[i]);
	printf("\n\n");
	for (int i = 0 ; i < pGraph->maxVertexCount; i++)
	{
		printf("%d) ", i);
		if (pGraph->ppAdjEdge[i] == NULL)
			printf("[NIL]\n");
		else
		{
			printf("     ");
			display(pGraph->ppAdjEdge[i]);
		}
	}	
}