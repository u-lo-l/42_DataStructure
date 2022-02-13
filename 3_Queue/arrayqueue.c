#include "arrayqueue.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
    int rear;
    
    rear = pQueue->rear;
    if (!pQueue)
        return (FALSE);
    if (isArrayQueueFull(pQueue))
        return (FALSE);
    
    pQueue->pElement[rear].data = element.data;
    pQueue->currentElementCount++;
    pQueue->rear++;

    return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    int front;
    ArrayQueueNode *front_node;
    if (!pQueue || isArrayQueueEmpty(pQueue))
        return (NULL);
    front = pQueue->front;
    front_node = createNode(pQueue->pElement[front].data);
    pQueue->pElement[front].data = 0;
    pQueue->front++;
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
    int rear;

    max = pQueue->maxElementCount;
    rear = pQueue->rear;
    if (rear + 1 == max)
    {
        printf("FULL\n");
        return (TRUE);
    }
    return (FALSE);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    int front;
    int rear;

    front = pQueue->front;
    rear = pQueue->rear;

    if (front == rear)
    {
        printf("EMPTY\n");
        return (TRUE);
    }
    return(FALSE);
}

void printArrayQueue(ArrayQueue* pQueue)
{
    for (int i = pQueue->front ; i < pQueue->rear ; printf("%c->",pQueue->pElement[i++].data));
    printf("\n");
}
/*
int main()
{
    ArrayQueue* Q = createArrayQueue(10);
    ArrayQueueNode *n1 = createNode('a');
    ArrayQueueNode *n2 = createNode('b');
    ArrayQueueNode *n3 = createNode('c');
    ArrayQueueNode *n4 = createNode('d');
    enqueueAQ(Q,*n1);
    printArrayQueue(Q);
    enqueueAQ(Q,*n2);
    printArrayQueue(Q);
    enqueueAQ(Q,*n3);
    printArrayQueue(Q);
    enqueueAQ(Q,*n4);
    printArrayQueue(Q);
    dequeueAQ(Q);
    printArrayQueue(Q);
    dequeueAQ(Q);
    printArrayQueue(Q);
    dequeueAQ(Q);
    printArrayQueue(Q);
    dequeueAQ(Q);
    printArrayQueue(Q);
    dequeueAQ(Q);
    printArrayQueue(Q);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    deleteArrayQueue(Q);
    system("leaks a.out");
    return (0);
}
*/