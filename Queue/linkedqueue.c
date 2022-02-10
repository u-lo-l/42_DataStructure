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
	printf("<ENQUEUE>\n");
    QueueNode *new;
    if (!pQueue)
        return (FALSE);
    new = (QueueNode *)calloc(1,sizeof(QueueNode));
	printf("ptr : %p\n", new->pLink);
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
	printf("DeQ start\n");
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
		printf("[%c]->",temp->data);
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
	{
		printf("EMPTY\n");
		return (TRUE);
	}
	return (FALSE);
}

int main()
{
	LinkedQueue *test;

	test = createLinkedQueque();

	QueueNode node_arr[10];

	for (int i = 0 ; i < 6 ; i++)
	{
		node_arr[i].data = 'a' + i;
		enqueueLQ(test, node_arr[i]);
		displayLQ(test);
	}

	for (int i = 0 ; i < 6 ; i++)
	{
		QueueNode *temp = dequeueLQ(test);
		free(temp);
		displayLQ(test);
	}

	system("leaks a.out");
}