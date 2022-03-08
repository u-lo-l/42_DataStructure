#include "prim.h"

static heapNode makeHeapNode(ListNode lNode, int from)
{
	heapNode node;
	node.weight = lNode.weight;
	node.from = from;
	node.to = lNode.ID;
	return node;
}


int insertEdgeToHeap(heap **ppHeap, LinkedList *pLL, int from)
{
	ListNode *temp;
	
	temp = pLL->headerNode.pLink;
	while (temp)
	{
		insertMinHeapNode((*ppHeap), makeHeapNode(*temp, from));
		temp = temp->pLink;
	}
	return (TRUE);
}

/* 0) LG와 같은 수의 vertex를 가지는 빈 그래프 생성(mst)
 * 1) 0번 노드부터 시작하는 알고리즘으로, mst->pVertex[0] = USED;
 *    LG->ppAdjEdge[0]의 edgeinfo heap에 insert.
 * 2) heap 에서 edgeinfo 하나 가져옴.
 * 3) heap에서 가져온 edgeinfo의 from과 to를 확인해서
 *    !(mst->pVertex[from] && mst->pVertex[to])이면 순환하지 않는다.
 * 4) to에 해당하는 vertex를 USED로 바꿔주고, edge를 추가한다.
 * 5) LG->ppAdjEdge[to]의 edgeinfo들을 heap에 insert
 * 6) 2)로 돌아가서 반복(mst->pVertex가 모드 USED가 될 때 까지)
 *    (= mst->maxcount == mst->currcount) 까지 반복
*/
LinkedGraph *prim(LinkedGraph *LG)
{
	LinkedGraph *mst;
	heap        *heap;

	if (!LG)
		return (0);
	if (LG->maxVertexCount != LG->currentVertexCount)
	{
		printf("Graph has 'not connected' Vertex\n");
		return (0);
	}
	mst = createLinkedGraph(LG->maxVertexCount);
	heap = createHeap(LG->currentEdgeCount * 2);
	insertEdgeToHeap(&heap,LG->ppAdjEdge[0],0);
	
	while (mst->currentVertexCount < mst->maxVertexCount)
	{
		heapNode node;
		if (isHeapEmpty(heap))
			break ;
		node = deleteMinHeapNode(heap);
		if (mst->pVertex[node.from] && mst->pVertex[node.to])
			continue ;
		addVertexLG(mst, node.to);
		addEdgewithWeightLG(mst, node.from, node.to, node.weight);
		insertEdgeToHeap(&heap,LG->ppAdjEdge[node.to],node.to);
	}
	deleteHeap(heap);
	if (mst->currentVertexCount != mst->maxVertexCount)
		return (NULL);
	return (mst);
}