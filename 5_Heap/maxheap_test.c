#include "maxheap.h"
#include <stdio.h>

static void printdata(int data, int blanksize);
static int	power(int base, int power);
void showHeapTree(MaxHeap *heap);

int main()
{
	MaxHeap	*heap;

	heap = createMaxHeap(5);
	if (!heap)
		return 1;
	printf("data ->\n");
	for (int i = 1; i < 28; i++)
	{
		printf("[%2d] ", i);
		if (i % 15 == 0) printf("\n");
		insertMaxHeapData(heap, i);
		printf("\n");
		showHeapTree(heap);
	}
	printf("\n");
	showHeapTree(heap);
//	displayMaxHeap(heap);
	deleteMaxHeap(&heap);
	return 0;
}

static void printdata(int d, int bs)
{
	int i = 0;
	for (; i < bs/2 ; i++)
		printf(" ");
	printf("[%3d]", d);
	for(; i < bs ; i++)
		printf(" ");
}

static int power(int b, int p)
{
	int ret = 1;
	for (int i = 0 ; i < p ; i++)
		ret = ret * b;
	return (ret);
}

void showHeapTree(MaxHeap *H)
{
	int depth = H->depth;
	int total = H->currentElementCount;
	int level = 0;
	int field = 5;
	int initblank = 1;
	int totalfield = power(2, depth - 1) * (field + initblank);
	int blanksize = totalfield;
	
	for (int i = 0 ; i < totalfield / 2 ; i++)
		printf("=");
	printf("MAXHEAP");
	for (int i = 0 ; i < totalfield / 2 ; i++)
		printf("=");
	printf("\n");
	
	for (int i = 1 ; i <= total ; i++)
	{
		if (i == power(2, level))
			printf("\n\nlevel%2d ", level++ + 1);
		blanksize = totalfield / power(2, level - 1) - field;
		printdata(H->pRootNode[i].data, blanksize);
	}
	printf("\n");
	for (int i = 0 ; i < totalfield + 7 ; i++)
		printf("=");
	
	printf("\n");
}
