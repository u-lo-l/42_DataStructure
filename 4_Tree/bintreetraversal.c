#include "bintreequeue.h"
#include "bintree.h"
#include <stdlib.h>

/*
이진 트리의 레벨 순회를 위한 큐
*/
/*
새로운 큐 생성
*/
t_LOQ* createLOQ()
{
	t_LOQ *myQueue;

	myQueue = (t_LOQ *)calloc(1, sizeof(t_LOQ));
	if (!myQueue)
		return NULL;
	return (myQueue);
}

/*
Enque: 큐의 리어에 새 노드 추가
*/
int enqueueLOQ(t_LOQ* pQueue, t_LOQNode element)
{
	t_LOQNode	*rearNode;

	if (!pQueue)
		return FALSE;
	rearNode = (t_LOQNode *)malloc(sizeof(t_LOQNode));
	if (!rearNode)
		return FALSE;
	*rearNode = element;
	
	if (isLOQEmpty(pQueue))
		pQueue->pFrontNode = rearNode;
	else
		pQueue->pRearNode->pElement = rearNode;
	pQueue->pRearNode = rearNode;
	rearNode->pElement = NULL;
	
	pQueue->currentElementCount++;
	return (TRUE);
}

/*
Dequeue: 큐의 프론트 노드 삭제
*/
t_LOQNode*	dequeueLOQ(t_LOQ* pQueue)
{
	t_LOQNode *delNode;
	
	if (!pQueue)
		return NULL;
	if (isLOQEmpty(pQueue))
		return NULL;

	delNode = pQueue->pFrontNode;
	if (pQueue->currentElementCount == 1)
	{
		pQueue->pFrontNode = NULL;
		pQueue->pRearNode = NULL;
	}
	else
		pQueue->pFrontNode = delNode->pElement;
	pQueue->currentElementCount--;
	return (delNode);
}

/*
Peek: 큐의 프론트 노드 반환
*/
t_LOQNode* peekLOQ(t_LOQ* pQueue)
{
	t_LOQNode *frontNode;
	
	if (!pQueue)
		return NULL;
	frontNode = pQueue->pFrontNode;
	return (frontNode);
}

/*
큐가 비어있는가?
*/
int	isLOQEmpty(t_LOQ* pQueue)
{
	if (!pQueue)
		return FALSE;
	if (pQueue->currentElementCount == 0)
		return TRUE;
	else
		return FALSE;
}

/*
큐 삭제
*/
void	deleteLOQ(t_LOQ** pQueue)
{
	t_LOQNode	*curr;	
	t_LOQNode	*temp;
	
	if (!pQueue || !(*pQueue))
		return ;
	curr = (*pQueue)->pFrontNode;
	while (curr)
	{
		temp = curr;
		curr = curr->pElement;
		free(temp);
		temp = NULL;
	}
	free(*pQueue);
	*pQueue = NULL;
}

/*
(Custom) 큐의 모든 노드의 데이터 출력
*/
void	displayLOQ(t_LOQ *pQueue)
{
	t_LOQNode	*curr;
	int				i;
	
	if (!pQueue)
		return ;
	curr = pQueue->pFrontNode;
	i = 0;
	while (curr)
	{
		printf("Index : %d, data : %d\n", i, curr->treeNode.data);
		curr = curr->pElement;
		i++;
	}
	return ;
}
