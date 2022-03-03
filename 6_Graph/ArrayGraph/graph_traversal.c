#include "arraygraph.h"
#include "Stack/linkedstack.h"
#include "Queue/linkedqueue.h"

int traversal_DFS_iter_AG(ArrayGraph *AG, int startID)
{
	if (!AG || startID + 1 > AG->maxVertexCount)
		return (ERROR);
	if (startID < 0 || startID >= AG->maxVertexCount)
		return (ERROR);
	if (AG->pVertex[startID] == NOT_USED)
		return (FALSE);
	int	*visited_info = calloc(AG->maxVertexCount, sizeof(int));
	LinkedStack	*S = createLinkedStack();
	StackNode	*vertex;
	StackNode	temp;
	if (!visited_info || !S)
	{
		free(visited_info);
		deleteLinkedStack(S);
		return (ERROR);
	}
	temp.data = startID;
	pushLS(S, temp);
	visited_info[startID] = 1;
	while (!isLinkedStackEmpty(S))
	{
		vertex = popLS(S);
		printf("\033[0;33m[%d] \033[0m", vertex->data);
		int id = 0;
		while (id < AG->maxVertexCount)
		{
			if (AG->ppAdjEdge[vertex->data][id] == 1)
				if (!visited_info[id])
				{
					temp.data = id;
					pushLS(S, temp);
					visited_info[id] = 1;
				}
			id++;
		}
		free(vertex);
	}
	printf("\n");
	free(visited_info);
	deleteLinkedStack(S);
}

int traversal_BFS_iter_AG(ArrayGraph *AG, int startID)
{
	if (!AG || startID + 1 > AG->maxVertexCount)
		return (ERROR);
	if (startID < 0 || startID >= AG->maxVertexCount)
		return (ERROR);
	if (AG->pVertex[startID] == NOT_USED)
		return (FALSE);
	int	*visited_info = calloc(AG->maxVertexCount, sizeof(int));
	LinkedQueue	*Q = createLinkedQueque();
	QueueNode	*vertex;
	QueueNode	temp;
	if (!visited_info || !Q)
	{
		free(visited_info);
		deleteLinkedQueue(Q);
		return (ERROR);
	}
	temp.data = startID;
	enqueueLQ(Q, temp);
	visited_info[startID] = 1;
	while (!isLinkedQueueEmpty(Q))
	{
		vertex = dequeueLQ(Q);
		printf("\033[0;33m[%d] \033[0m", vertex->data);
		int id = 0;
		while (id < AG->maxVertexCount)
		{
			if (AG->ppAdjEdge[vertex->data][id] == 1)
				if (!visited_info[id])
				{
					temp.data = id;
					enqueueLQ(Q, temp);
					visited_info[id] = 1;
				}
			id++;
		}
		free(vertex);
	}
	printf("\n");
	deleteLinkedQueue(Q);
}
