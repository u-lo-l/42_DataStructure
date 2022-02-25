#include "linkedqueue.h"
#include <stdlib.h>
#include <stdio.h>


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
	// printf("<ENQUEUE>\n");
	// printf("curr_Q_status : ");
	// displayLQ(pQueue);
    QueueNode *new;
    if (!pQueue)
        return (FALSE);
    new = (QueueNode *)calloc(1,sizeof(QueueNode));
    if (!new)
        return (FALSE);
    new->node = element.node;
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
	// printf("<Enqueue Succeed>\n");
	// printf("new_Q_status : ");
	// displayLQ(pQueue);
	// printf("\n");
    return (TRUE);
}
QueueNode* dequeueLQ(LinkedQueue* pQueue)
{
	// printf("<DEQUEUE>\n");
	// printf ("curr_Q_status :");
	// displayLQ(pQueue);
	QueueNode *pReturn;
    if (!pQueue)
        return (NULL);
    if (isLinkedQueueEmpty(pQueue))
    {
        printf("Queue is already empty\n");
        return (NULL);
    }
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
	// printf("<DEQUEUE SUCCEED>\nQueue: ");
	// printf("new_Q_status : ");
	// displayLQ(pQueue);
	return (pReturn);
}
void	displayLQ(LinkedQueue* pQueue)
{
	if (!pQueue)
		return ;
	if (isLinkedQueueEmpty(pQueue))
	{
		printf("Queue is empty\n");
		return ;
	}
	QueueNode *temp;
	temp = pQueue->pFrontNode;
	while(temp)
	{
		printf("[%d]->",temp->node.data);
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