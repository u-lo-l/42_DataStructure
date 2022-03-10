#include "heap.h"

heap *createHeap(int maxElementCount)
{
	heap *pHeap;
	
	pHeap = (heap *)malloc(sizeof(heap));
	if (!pHeap)
		return (NULL);
	pHeap->maxElementCount = maxElementCount;
	pHeap->currentElementCount = 0;
	pHeap->rootNode = (heapNode *)malloc(sizeof(heapNode) * maxElementCount);
	if (!pHeap->rootNode)
		return (NULL);
	return (pHeap);
}
	
void deleteHeap(heap *pHeap)
{
	if (!pHeap)
		return ;
	for (int i = 0 ; i < pHeap->currentElementCount ; i++)
	{
		pHeap->rootNode[i].weight = 0;
		pHeap->currentElementCount--;
	}
	pHeap->maxElementCount = 0;
	free(pHeap->rootNode);
	free(pHeap);
}

int isHeapFull(heap *pHeap)
{
	if (!pHeap)
		return (-1);
	return (pHeap->currentElementCount >= pHeap->maxElementCount - 1);
}

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap_element(heapNode *h1, heapNode *h2)
{
	heapNode tmp;
	tmp = *h1;
	*h1 = *h2;
	*h2 = tmp;
}

void insertMaxHeapNode(heap *pHeap, heapNode element)
{
	if (!pHeap || isHeapFull(pHeap))
		return ;
	pHeap->currentElementCount++;
	int i = pHeap->currentElementCount;
	pHeap->rootNode[pHeap->currentElementCount] = element;
	while ((i != 1) && pHeap->rootNode[i / 2].weight < element.weight)
	{
		swap_element(&pHeap->rootNode[i / 2], &pHeap->rootNode[i]);
		i /= 2;
	}
}

int isHeapEmpty(heap *pHeap)
{
	if (!pHeap || pHeap->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

heapNode deleteMaxHeapNode(heap *pHeap)
{ 
	heapNode result;

	if (!pHeap || isHeapEmpty(pHeap))
		return (result);
	swap_element(&pHeap->rootNode[1], &pHeap->rootNode[pHeap->currentElementCount]);
	result = pHeap->rootNode[pHeap->currentElementCount];
	pHeap->rootNode[pHeap->currentElementCount].weight = 0;
	pHeap->currentElementCount--;
	int parent = 1;
	int child = 2;
	while (child <= pHeap->currentElementCount)
	{
		if (child <= pHeap->currentElementCount)
		{
			if (child + 1 <= pHeap->currentElementCount && pHeap->rootNode[child].weight < pHeap->rootNode[child + 1].weight)
				child++;
		}
		if (pHeap->rootNode[parent].weight < pHeap->rootNode[child].weight)
			swap_element(&pHeap->rootNode[parent], &pHeap->rootNode[child]);
		parent = child;
		child = parent * 2;
	}
	return (result);
}

heapNode deleteMinHeapNode(heap *pHeap)
{
	heapNode result;

	if (!pHeap || isHeapEmpty(pHeap))
		return (result);
	swap_element(&pHeap->rootNode[1], &pHeap->rootNode[pHeap->currentElementCount]);
	result = pHeap->rootNode[pHeap->currentElementCount];
	pHeap->rootNode[pHeap->currentElementCount].weight = 0;
	pHeap->currentElementCount--;
	int parent = 1;
	int child = 2;
	while (child <= pHeap->currentElementCount)
	{
		if (child <= pHeap->currentElementCount)
		{
			if (child + 1 <= pHeap->currentElementCount && pHeap->rootNode[child].weight > pHeap->rootNode[child + 1].weight)
				child++;
		}
		if (pHeap->rootNode[parent].weight > pHeap->rootNode[child].weight)
			swap_element(&pHeap->rootNode[parent], &pHeap->rootNode[child]);
		parent = child;
		child = parent * 2;
	}
	return (result);
}

void insertMinHeapNode(heap *pHeap, heapNode element)
{
	if (!pHeap || isHeapFull(pHeap))
		return ;
	pHeap->currentElementCount++;
	int i = pHeap->currentElementCount;
	pHeap->rootNode[pHeap->currentElementCount] = element;
	while ((i != 1) && pHeap->rootNode[i / 2].weight > element.weight)
	{
		swap_element(&pHeap->rootNode[i / 2], &pHeap->rootNode[i]);
		i /= 2;
	}
}

void displayHeap(heap *pHeap)
{
	printf("currentElementCount : %d\n", pHeap->currentElementCount);
	printf("maxElementCount : %d\n", pHeap->maxElementCount);
	for (int i = 1 ; i <= pHeap->currentElementCount ; i++)
		printf("weight : %d, from : <%d>, to : <%d> \n", pHeap->rootNode[i].weight, pHeap->rootNode[i].from, pHeap->rootNode[i].to);
	printf("\n");
}
/*
int main(void)
{
	heap *maxHeap;
	heapNode element;

	maxHeap = createHeap(10);
	element.weight = 30;
	insertMinHeapNode(maxHeap, element);
	display(maxHeap);
	element.weight = 20;
	insertMinHeapNode(maxHeap, element);
	display(maxHeap);
	element.weight = 40;
	insertMinHeapNode(maxHeap, element);
	display(maxHeap);
	element.weight = 10;
	insertMinHeapNode(maxHeap, element);
	display(maxHeap);
	element.weight = 24;
	insertMinHeapNode(maxHeap, element);
	display(maxHeap);
	element.weight = 34;
	insertMinHeapNode(maxHeap, element);
	display(maxHeap);
	element.weight = 46;
	insertMinHeapNode(maxHeap, element);
	// display(maxHeap);
	printf("%d\n", deleteMinHeapNode(maxHeap));
	printf("%d\n", deleteMinHeapNode(maxHeap));
	printf("%d\n", deleteMinHeapNode(maxHeap));
	printf("%d\n", deleteMinHeapNode(maxHeap));
	printf("%d\n", deleteMinHeapNode(maxHeap));
	printf("%d\n", deleteMinHeapNode(maxHeap));
	printf("%d\n", deleteMinHeapNode(maxHeap));
	printf("%d\n", deleteMinHeapNode(maxHeap));
	printf("%d\n", deleteMinHeapNode(maxHeap));
	printf("%d\n", deleteMinHeapNode(maxHeap));
	// display(maxHeap);

	deleteHeap(maxHeap);
	maxHeap=NULL;
}*/