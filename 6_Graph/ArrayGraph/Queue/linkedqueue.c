#include "linkedqueue.h"
#include <stdlib.h>
#include <stdio.h>

QueueNode *createLQNode(int data)
{
	QueueNode *node;
	node = malloc(sizeof(QueueNode));
	if (!node)	return (NULL);
	node->data = data;
	node->pLink = NULL;
	return (node);
}

LinkedQueue* createLinkedQueque()
{
    LinkedQueue *LQ;
    LQ = (LinkedQueue *)calloc(1,sizeof(LinkedQueue));
    if (!LQ)
        return (NULL);
    return (LQ);
}
int enqueueLQ(LinkedQueue* pQueue, QueueNode element)
{
    QueueNode *new;
    if (!pQueue)
        return (FALSE);
    new = (QueueNode *)calloc(1,sizeof(QueueNode));
    if (!new)
        return (FALSE);
    new->data = element.data;
    if (isLinkedQueueEmpty(pQueue))
    {
        pQueue->pFrontNode = new; 
        pQueue->pRearNode = new;
    }
    else
    {
        pQueue->pRearNode->pLink = new;
        pQueue->pRearNode = new;
    }
    pQueue->currentElementCount++;
    return (TRUE);
}
QueueNode* dequeueLQ(LinkedQueue* pQueue)
{
	QueueNode *pReturn;
    if (!pQueue)
        return (NULL);
    if (isLinkedQueueEmpty(pQueue))
        return (NULL);
	pReturn = pQueue->pFrontNode;
    if (pQueue->currentElementCount == 1)
	{
		
		pQueue->pFrontNode = NULL;
		pQueue->pRearNode = NULL;
	}
	else
	{
		pQueue->pFrontNode = pQueue->pFrontNode->pLink;
		pReturn->pLink = NULL;
	}
	pQueue->currentElementCount--;
	return (pReturn);
}
void	displayLQ(LinkedQueue* pQueue)
{
	if (!pQueue)
		return ;
	QueueNode *temp;
	temp = pQueue->pFrontNode;
	while(temp)
	{
		printf("\033[0;35m<%d>->\033[0m",temp->data);
		temp = temp->pLink;
	}
	printf("\n");
}

QueueNode* peekLQ(LinkedQueue* pQueue)
{
	if (!pQueue)
		return NULL;
	return(pQueue->pFrontNode);
}

void deleteLinkedQueue(LinkedQueue* pQueue)
{
	QueueNode *curr;
	QueueNode *next;
	if (!pQueue)
		return ;
	curr = pQueue->pFrontNode;
	while (curr != NULL)
	{
		next = curr->pLink;
		free(curr);
		curr = next;
	}
	free (pQueue);
	pQueue = NULL;
}

int isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	if (!pQueue)
		return (FALSE);
	if (pQueue->pFrontNode == NULL && pQueue->pRearNode == NULL)
		return (TRUE);
	return (FALSE);
}