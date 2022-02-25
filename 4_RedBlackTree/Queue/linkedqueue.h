#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

#include <stdlib.h>
#include <stdio.h>
#include "../RBTree/redblacktree.h"

typedef struct QueueNodeType
{
	RBTreeNode node;
	struct QueueNodeType* pLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int currentElementCount;
	QueueNode* pFrontNode;
	QueueNode* pRearNode;
} LinkedQueue;

LinkedQueue* createLinkedQueque();
int enqueueLQ(LinkedQueue* pQueue, QueueNode element);
QueueNode* dequeueLQ(LinkedQueue* pQueue);
QueueNode* peekLQ(LinkedQueue* pQueue);
void deleteLinkedQueue(LinkedQueue* pQueue);
int isLinkedQueueFull(LinkedQueue* pQueue);
int isLinkedQueueEmpty(LinkedQueue* pQueue);
void	displayLQ(LinkedQueue* pQueue);
#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif
