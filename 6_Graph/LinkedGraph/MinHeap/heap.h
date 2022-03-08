#ifndef HEAP_H
# define HEAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct heapNodeType{
	int weight;
	int from;
	int to;
}heapNode;

typedef struct heapType{
	int maxElementCount;
	int currentElementCount;
	heapNode *rootNode; // 배열
}heap;

heap *createHeap(int maxElementCount);
void deleteHeap(heap *pHeap);
void insertMaxHeapNode(heap *pHeap, heapNode element);
void insertMinHeapNode(heap *pHeap, heapNode element);
heapNode deleteMaxHeapNode(heap *pHeap);
heapNode deleteMinHeapNode(heap *pHeap);
void swap(int *a, int *b);
int isHeapEmpty(heap *pHeap);
int isHeapFull(heap *pHeap);
void displayHeap(heap *pHeap);
#define TRUE 1
#define FALSE 0

#endif
