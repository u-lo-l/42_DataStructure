#include "arrayqueue.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int getCircularIndex(int max_size, int value)
{
    if (max_size > 0)
        return (value % max_size);
    return (-1);
}

static ArrayQueueNode *createNode(char d)
{
    ArrayQueueNode *node = malloc(sizeof(ArrayQueueNode));
    if (!node)
        return (NULL);
    node->data = d;
    return (node);
}

ArrayQueue* createArrayQueue(int maxElementCount)
{
    ArrayQueue *que;

    que = (ArrayQueue *)calloc(1, sizeof(ArrayQueue));
    if (!que)
        return (NULL);
    que->pElement = calloc(1, sizeof(ArrayQueueNode));
    if (!que->pElement)
    {
        free (que);
        return (NULL);
    }
    que->maxElementCount = maxElementCount;
    return (que);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	printf("Enque\n");
    int rear;
    int max;

    max = pQueue->maxElementCount;
    if (!pQueue)
        return (FALSE);
    if (isArrayQueueFull(pQueue))
        return (FALSE);
    
    rear = getCircularIndex(max ,pQueue->rear++);
    pQueue->pElement[rear].data = element.data;
    pQueue->currentElementCount++;

    return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	printf("Deque\n");
	int max;
    int front;
    ArrayQueueNode *front_node;
    if (!pQueue || isArrayQueueEmpty(pQueue))
        return (NULL);
	max = pQueue->maxElementCount;
    front = getCircularIndex(max, pQueue->front++);
	printf("before[%d] after[%d]\n", front, pQueue->front);
    front_node = createNode(pQueue->pElement[front].data);
    pQueue->pElement[front].data = 0;
    pQueue->currentElementCount--;
    return (front_node);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
    int front;
    ArrayQueueNode *front_node;
    if (!pQueue || isArrayQueueEmpty(pQueue))
        return (NULL);
    front = pQueue->front;
    front_node = createNode(pQueue->pElement[front].data);
    return (front_node);
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
    if (!pQueue)
        return ;
    free(pQueue->pElement);
    free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
    int max;
    int curr;

    max = pQueue->maxElementCount;
    curr = pQueue->currentElementCount;
    if (curr == max)
    {
        printf("FULL\n");
        return (TRUE);
    }
    return (FALSE);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	int curr;

	curr = pQueue->currentElementCount;
	if (curr == 0)
	{
		printf("EMPTY\n");
		return (TRUE);
	}
	return(FALSE);
}

void printArrayQueue(ArrayQueue* pQueue)
{
	printf("=======Queue=======\n");
    if (isArrayQueueEmpty(pQueue))
    {
        printf("EMPTY QUEUE\n");
        return ;
    }
	int max = pQueue->maxElementCount;
	int front = getCircularIndex(max, pQueue->front);
	int rear = getCircularIndex(max, pQueue->rear);
	int index;
	if (front >= rear)
		rear += max;
	printf("front : [%d] rear : [%d]\n", front, rear);
	for (int i = front ; i < rear ; i++)
	{
		index = getCircularIndex(max, i);
		printf("%c->",pQueue->pElement[index].data);
	}
	printf("\n");
}

int main()
{
    ArrayQueue* Q = createArrayQueue(10);

	ArrayQueueNode node_arr[10];

	for (int i = 0 ; i < 6 ; i++)
	{
		node_arr[i].data = 'a' + i;
		enqueueAQ(Q, node_arr[i]);
		printArrayQueue(Q);
	}

	for (int i = 0 ; i < 6 ; i++)
	{
		ArrayQueueNode *temp = dequeueAQ(Q);
		free(temp);
		printArrayQueue(Q);
	}
    deleteArrayQueue(Q);
    system("leaks a.out");
    return (0);
}