#include "linkedgraph.h"
#include "./Queue/linkedqueue.h"
#include "./Stack/linkedstack.h"

int traversal_DFS_iter_LG(LinkedGraph *LG, int startID)
{
	LinkedStack	*stack;
	ListNode	*curr;
	StackNode	*vertex;
	StackNode	temp;
	int			*visited;

	if (!LG)
		return (ERROR);
	if (startID < 0 || startID >= LG->maxVertexCount)
		return (ERROR);
	if (!(stack = createLinkedStack()))
		return (ERROR);
	if(!(visited = calloc(LG->maxVertexCount, sizeof(int))))
	{
		deleteLinkedStack(stack);
		return (ERROR);
	}
	temp.data = startID;
	pushLS(stack, temp);
	visited[startID] = 1;
	while (!isLinkedStackEmpty(stack))
	{
		vertex = popLS(stack);
		printf("\033[0;33m[%d] \033[0m", vertex->data);
		curr = LG->ppAdjEdge[vertex->data]->headerNode.pLink;
		while (curr)
		{
			if (visited[curr->ID] != 1)
			{
				temp.data = curr->ID;
				pushLS(stack, temp);
				visited[curr->ID] = 1;
			}
			curr = curr->pLink;
		}
		free(vertex);
	}
	printf("\n");
	free(visited);
	deleteLinkedStack(stack);
	return (TRUE);
}

int traversal_BFS_iter_LG(LinkedGraph *LG, int startID)
{
	LinkedQueue	*queue;
	ListNode	*curr;
	QueueNode	*vertex;
	QueueNode	temp;
	int			*visited;

	if (!LG)
		return (ERROR);
	if (startID < 0 || startID >= LG->maxVertexCount)
		return (ERROR);
	if (!(queue = createLinkedQueque()))
		return (ERROR);
	if (!(visited = calloc(LG->maxVertexCount, sizeof(int))))
	{
		deleteLinkedQueue(queue);
		return (ERROR);
	}
	temp.data = startID;
	enqueueLQ(queue, temp);
	visited[startID] = 1;
	while (!isLinkedQueueEmpty(queue))
	{
		vertex = dequeueLQ(queue);
		printf("\033[0;33m[%d] \033[0m", vertex->data);
		curr = LG->ppAdjEdge[vertex->data]->headerNode.pLink;
		while (curr)
		{
			if (!visited[curr->ID])
			{
				temp.data = curr->ID;
				enqueueLQ(queue, temp);
				visited[curr->ID] = 1;
			}
			curr = curr->pLink;
		}
		free(vertex);
	}
	free(visited);
	deleteLinkedQueue(queue);
	printf("\n");
	return (TRUE);
}