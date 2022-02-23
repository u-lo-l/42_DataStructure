#ifndef _MAXHEAP_
# define _MAXHEAP_


typedef struct MaxHeapNodeType
{
	int data;
} MaxHeapNode;

typedef struct MaxHeapType
{
	int depth;
	int maxElementCount;
	int currentElementCount;
	MaxHeapNode *pRootNode;
} MaxHeap;

MaxHeap		*createMaxHeap(int depth);
int			getCurrentElementCount(MaxHeap *MaxHeap);
void		deleteMaxHeap(MaxHeap **pMaxHeap);
int			insertMaxHeapData(MaxHeap *pMaxHeap, int data);
MaxHeapNode	*deleteMaxHeapData(MaxHeap *pMaxHeap);
int			isMaxHeapFull(MaxHeap *pMaxHeap);
int			isMaxHeapEmpty(MaxHeap *pMaxHeap);
void		displayMaxHeap(MaxHeap *MaxHeap);

#endif

#ifndef _COMMON_HEAP_DEF_
# define _COMMON_HEAP_DEF_

# define TRUE	1
# define FALSE	0
# define ERROR	-1

#endif
