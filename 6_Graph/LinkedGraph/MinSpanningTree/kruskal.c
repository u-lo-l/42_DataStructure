#include "spanningTree.h"

static heapNode makeHeapNode(ListNode lNode, int from)
{
	heapNode node;
	node.weight = lNode.weight;
	node.from = from;
	node.to = lNode.ID;
	return node;
}

heap *sortEdge(LinkedGraph *LG)
{
	heap *sortedEdge;
	ListNode *curr;

	sortedEdge = createHeap(LG->currentEdgeCount * 2);

	for (int i = 0; i < LG->maxVertexCount ; i++)
	{
		if (LG->pVertex[i] == NOT_USED)
			continue;
		curr = LG->ppAdjEdge[i]->headerNode.pLink;
		while (curr != NULL)
		{
			if (curr->visited == 0)
			{
				insertMinHeapNode(sortedEdge, makeHeapNode(*curr, i));
				curr->visited = 1;
			}
			curr = curr->pLink;
		}
	}
	return (sortedEdge);
}

/*
 * 1. 본체 그래프 LG를 받아온다.
 * 2. LG의 최소 신장트리가 될 그래프를 생성한다.
 * 3. LG의 edge들을 MinHeap에 저장한다
 * (sortEdge함수에서 처리하고 minheap을 반환한다.)
 * 4. mst의 노드의 개수 - 1 이 mst의 edge수 와 같을 때 까지
 *		MinHeap에서 하나씩 뽑아와서 circular인지 확인
 *		순환하면 다음 것 확인.
 *		순환하지 않는다면 edge추가.	
*/
LinkedGraph	*kruskal(LinkedGraph *LG)
{
	LinkedGraph *mst;
	heap *sortedEdge;
	int *circularTable;
	
	if (!LG)
		return (0);
	if (!isGraphConnected(LG))
	{
		printf("Graph has 'not connected' Vertex\n");
		return (0);
	}
	circularTable = (int *)malloc(sizeof(int) * LG->maxVertexCount);
	if (!circularTable)
		return (0);
	for (int i = 0 ; i < LG->maxVertexCount; i++)
		circularTable[i] = i;
	sortedEdge = sortEdge(LG);
	// printf("\nSorted Edge\n");
	// displayHeap(sortedEdge);
	mst = createLinkedGraph(LG->maxVertexCount);
	
	// printf("mst init done\n");
	for (int i = 0 ; i < LG->maxVertexCount ; i++)
	{
		if (LG->pVertex[i] == USED)
			addVertexLG(mst, i);
	}
	// printf("======Circular Table======\n");
	// for (int i = 0 ; i < LG->maxVertexCount ; i++)
	// 	printf("[%d] ",circularTable[i]);
	// printf("\n=========================\n");
	while (LG->maxVertexCount != (mst->currentEdgeCount) - 1)
	{
		heapNode node;
		if (isHeapEmpty(sortedEdge))
			break ;
		node = deleteMinHeapNode(sortedEdge);
		// printf("maxV %d, curE %d\n", LG->maxVertexCount, mst->currentEdgeCount);
		// printf("from :%d, to :%d\n", node.from, node.to);
		if (!findParent(circularTable, node.from, node.to))
		{
			addEdgewithWeightLG(mst, node.from, node.to, node.weight);
			unionParent(circularTable, node.from, node.to);
		}
		else
			continue ;
	}
	deleteHeap(sortedEdge);
	free(circularTable);
	return (mst);
}