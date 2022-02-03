/*
 * Circular List
 * Author	: minjkim2, dkim2
 * Language	:  C
 */
#include "circularlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
 * createCircularList() - Create Circular List
 *
 * return	: Pointer of circular list
 */
CircularList *createCircularList()
{
	CircularList *list;
	
	list = (CircularList *)malloc(sizeof(CircularList));
	if (!list)
		return (NULL);
	list->currentElementCount = 0;
	list->pLink = NULL;
	return (list);
}


/*
 * createCListNode() - Create Circular List Node
 *
 * return	: Node의 포인터
 * data		: Node의 data
 */
CircularListNode *createCListNode(int data)
{
	CircularListNode *node;

	node = (CircularListNode *)malloc(sizeof(CircularListNode));
	if (!node)
		return (NULL);
	node->data = data;
	node->pLink = NULL;
	return (node);
}


/*
 * addFirst() - list의 처음에 node 추가
 *
 * return	: 0 / 1
 * pList	: Circular List의 포인터
 * node		: 추가할 노드
 */
int addFirst(CircularList *pList, CircularListNode *node)
{
	CircularListNode *last_node;

	if (!pList || !node)
		return (EXIT_FAILURE);
	if (!pList->pLink) // 공백 리스트인 경우
	{
		pList->pLink = node;
		node->pLink = node;
	}
	else // 공백 리스트가 아닌 경우
	{
		last_node = getCLElement(pList, pList->currentElementCount - 1);
		last_node->pLink = node;
		node->pLink = pList->pLink;
		pList->pLink = node;
	}
	return (EXIT_SUCCESS);
}

/*
 * addCLElement() - Circular List의 position 위치에 node 추가
 *
 * return	: 0 / 1
 * pList	: Circular List의 포인터
 * position	: 노드를 추가할 위치
 * element	: 추가할 노드의 데이터
 */
int addCLElement(CircularList* pList, int position, CircularListNode element)
{
	CircularListNode *node;
	CircularListNode *temp;

	if (!pList || position < 0 || position > pList->currentElementCount)
		return (EXIT_FAILURE);
	node = createCListNode(element.data);
	if (position == 0 || !pList->pLink) // List의 첫위치에 노드 추가
		addFirst(pList, node);
	else
	{
		temp = getCLElement(pList, position - 1);
		node->pLink = temp->pLink;
		temp->pLink = node;
	}
	pList->currentElementCount++;
	return (EXIT_SUCCESS);
}

/*
 * removeFirst() - Circular List의 첫 노드 삭제
 *
 * return	: 0 / 1
 * pList	: Circular List의 포인터
 */
int removeFirst(CircularList *pList)
{
	CircularListNode *removed;
	CircularListNode *node;

	if (!pList)
		return (EXIT_FAILURE);
	if (pList->currentElementCount == 1) // 전체 노드 개수 : 1
	{
		removed = pList->pLink;
		pList->pLink = NULL;
	}
	else
	{
		removed = pList->pLink;
		node = getCLElement(pList, pList->currentElementCount - 1);
		node->pLink = removed->pLink;
		pList->pLink = removed->pLink;
	}
	free(removed);
	return (EXIT_SUCCESS);
}

/*
 * removeCLElement() - Circular List의 position 위치의 node 삭제
 *
 * return	: 0 / 1
 * pList	: Circular List의 포인터
 * position	: 삭제할 노드의 위치
 */
int removeCLElement(CircularList* pList, int position)
{
	CircularListNode *removed;
	CircularListNode *node;

	if (!pList || position < 0 || position >= pList->currentElementCount || !pList->pLink)
		return (EXIT_FAILURE);
	if (position == 0) // 첫번째 위치의 노드 삭제
		removeFirst(pList);
	else
	{
		node = getCLElement(pList, position - 1);
		removed = node->pLink;
		node->pLink = removed->pLink;
		free(removed);
	}
	pList->currentElementCount--;
	return (EXIT_SUCCESS);
}

/*
 * getCLElement() - Circular List의 position 위치의 노드 반환
 *
 * return	: node의 포인터
 * pList	: Circular List의 포인터
 * position	: 반환할 노드의 위치
 */
CircularListNode* getCLElement(CircularList* pList, int position)
{
	CircularListNode *node;
	int i;

	if (!pList || position < 0 || position >= pList->currentElementCount)
		return (NULL);
	i = 0;
	node = pList->pLink;
	while (i < position)
	{
		node = node->pLink;
		i++;
	}
	return (node);
}

/*
 * clearCircularList() - Circular List의 전체 노드 삭제
 *
 * return	: None
 * pList	: Circular List의 포인터
 */
void clearCircularList(CircularList* pList)
{
	int i = 0;
	CircularListNode *temp;
	CircularListNode *removed;

	if (!pList)
		return ;
	temp = pList->pLink;
	while (i < pList->currentElementCount)
	{
		removed = temp;
		temp = temp->pLink;
		free(removed);
		pList->currentElementCount--;
	}
	assert(pList->currentElementCount == 0);	
}

/*
 * deleteCircularList() - Circular List 삭제
 *
 * return	: None
 * pList	: Circular List의 포인터
 */
void deleteCircularList(CircularList* pList)
{
	if (!pList)
		return ;
	clearCircularList(pList);
	free(pList);
}

/*
 * getCircularListLength() - Circular List의 길이 반환
 *
 * return	: Circular List의 노드 개수
 * pList	: Circular List의 포인터
 */
int getCircularListLength(CircularList* pList)
{
	if (!pList)
		return (EXIT_FAILURE);
	return (pList->currentElementCount);
}

/*
 * displayCircularList() - Circular List 출력
 *
 * return	: None
 * pList	: Circular List의 포인터
 */
void displayCircularList(CircularList* pList)
{
	int i;
	CircularListNode *node;

	if (!pList)
		return ;
	i = 0;
	node = pList->pLink;
	if (!node)
	{
		printf("NULL\n");
		return ;
	}
	while (i < pList->currentElementCount + 1)
	{
		printf("%d -> ", node->data);
		node = node->pLink;
		i++;
	}
	printf("\n");
}

int main(void)
{
	CircularList *list;
	CircularListNode node;

	list = createCircularList();
	node.data = 10;
	addCLElement(list, 0, node);
	displayCircularList(list);
	// 10

	node.data = 20;
	addCLElement(list, 0, node);
	displayCircularList(list);
	// 20 -> 10

	node.data = 30;
	addCLElement(list, 2, node);
	displayCircularList(list);
	// 20 -> 10 -> 30

	printf("length : %d\n", getCircularListLength(list));
	// removeCLElement(list, 1);
	// displayCircularList(list);
	// // 20 -> 30

	// removeCLElement(list, 0);
	// displayCircularList(list);
	// // 30

	// removeCLElement(list, 0);
	// displayCircularList(list);
	// // NULL

	clearCircularList(list);
	deleteCircularList(list);
	// system("leaks a.out");
}
