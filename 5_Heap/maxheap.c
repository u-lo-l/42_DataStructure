#include "maxheap.h"
#include <stdio.h>
#include <stdlib.h>

MaxHeap	*createMaxHeap(int depth)
{
	MaxHeap *newHeap;
	int 	maxElementCount = 1;

	if (depth < 1)
		return (NULL); 
	newHeap = (MaxHeap *)malloc(sizeof(MaxHeap));
	if (!newHeap)
		return (NULL);
	for (int i = 1 ; i <= depth ; i++)
		maxElementCount *= 2;
	newHeap->depth = depth;
	newHeap->maxElementCount = maxElementCount - 1;
	newHeap->currentElementCount = 0;
	newHeap->pRootNode = (MaxHeapNode *)calloc(1, sizeof(MaxHeapNode) * (maxElementCount));
	if (!newHeap->pRootNode)
	{
		free(newHeap);
		return (NULL);
	}
	return (newHeap);
}

int		getCurrentElementCount(MaxHeap *MaxHeap)
{
	if (!MaxHeap)
		return (ERROR);
	return (MaxHeap->currentElementCount);
}

int		isMaxHeapFull(MaxHeap *pMaxHeap)
{
	if (!pMaxHeap)
		return (ERROR);
	if (pMaxHeap->currentElementCount == pMaxHeap->maxElementCount)
		return (TRUE);
	return (FALSE);
}
int		isMaxHeapEmpty(MaxHeap *pMaxHeap)
{
	if (!pMaxHeap)
		return (ERROR);
	if (pMaxHeap->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

static void	swapHeapNode(MaxHeap *heap, int a, int b)
{
	int	tmp;

	if (a == b || a < 1 || b < 1 || a > heap->currentElementCount || b > heap->currentElementCount)
		return ;
	tmp = heap->pRootNode[a].data;
	heap->pRootNode[a].data = heap->pRootNode[b].data;
	heap->pRootNode[b].data = tmp;
}

int	insertMaxHeapData(MaxHeap *pMaxHeap, int data)
{
	int index;

	if (!pMaxHeap)
		return (ERROR);
	if (isMaxHeapFull(pMaxHeap))
	{
		printf("The heap is already full.\n");
		return (ERROR);
	}
	index = getCurrentElementCount(pMaxHeap) + 1;
	pMaxHeap->pRootNode[index].data = data;
	pMaxHeap->currentElementCount++;
	while (index / 2)
	{
		if (pMaxHeap->pRootNode[index].data <= pMaxHeap->pRootNode[index/2].data)
			return (TRUE);
		swapHeapNode(pMaxHeap, index, index / 2);
		index /= 2;
	}
	return (TRUE);
}

static int	getChildCount(MaxHeap *pMaxHeap, int index)
{
	if (pMaxHeap || index < 1 || index > pMaxHeap->currentElementCount)
		return (ERROR);
	if (index * 2 > pMaxHeap->currentElementCount)
		return (0);
	else if (index * 2 == pMaxHeap->currentElementCount)
		return (1);
	else
		return (2);
}

MaxHeapNode	*deleteMaxHeapData(MaxHeap *pMaxHeap)
{
	MaxHeapNode	*targetData;
	int			index;
	int			childIndex;
	int			childCount;

	if (!pMaxHeap || pMaxHeap->currentElementCount == 0)
		return (NULL);

	targetData = (MaxHeapNode *)malloc(sizeof(MaxHeapNode));
	if (!targetData)
		return (NULL);

	*targetData = pMaxHeap->pRootNode[1];
	index = 1;
	pMaxHeap->pRootNode[1] = pMaxHeap->pRootNode[getCurrentElementCount(pMaxHeap)];
	pMaxHeap->currentElementCount--;
	childCount = getChildCount(pMaxHeap, index);
	while (childCount)
	{
		if (childCount == 1)
			childIndex = index * 2;
		else if (childCount == 2)
		{
			if (pMaxHeap->pRootNode[index * 2].data > pMaxHeap->pRootNode[index * 2 + 1].data)
				childIndex = index * 2;
			else
				childIndex = index * 2 + 1;
		}
		if (pMaxHeap->pRootNode[index].data > pMaxHeap->pRootNode[childIndex].data)
			break ;
		swapHeapNode(pMaxHeap, index, childIndex);
		index = childIndex;
		childCount = getChildCount(pMaxHeap, index);
	}
	return (targetData);
}

void	deleteMaxHeap(MaxHeap **pMaxHeap)
{
	if (!pMaxHeap || !(*pMaxHeap))
		return ;
	free((*pMaxHeap)->pRootNode);
	free(*pMaxHeap);
	*pMaxHeap = NULL;
}

static int	getPowerOfTwo(int num)
{
	int	tmp;
	int	maxInt;
	int power;

	maxInt = 2147483647;
	tmp = 1;
	power = 0;
	while (tmp <= maxInt && tmp > 0)
	{
		if (tmp == num)
			return (power);
		tmp *= 2;
		power++;
	}
	return (-1);
}

void	displayMaxHeap(MaxHeap *pMaxHeap)
{
	int	power;

	if (!pMaxHeap)
		return ;
	printf("------------ Max Heap ------------\n");
	if (isMaxHeapEmpty(pMaxHeap))
	{
		printf("The heap is empty.\n");
		return ;
	}
	else if (isMaxHeapFull(pMaxHeap))
		printf("The heap is full.\n");
	printf("Max element count : %i\n", pMaxHeap->maxElementCount);
	printf("Current element count : %i\n", pMaxHeap->currentElementCount);
	printf("----------------------------------\n");
	for (int i = 1; i <= pMaxHeap->currentElementCount; i++)
	{
		power = getPowerOfTwo(i);
		if (power > -1)
			printf("\nLevel[%i] : ", power + 1);
		printf("[%i] ", pMaxHeap->pRootNode[i].data);
	}
	printf("\n----------------------------------\n");
}
