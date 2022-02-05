/*
 * Linked List
 * Author	: minjkim2, dkim2
 * Language	:  C
 */
#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
 * error() - Print error mesage and Exit
 *
 * return	: None
 * message	: Error Message
 */
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);
}

/*
 * createListNode() - Create List Node
 *
 * return	: node의 포인터
 * data		: node에 저장될 data
 */
ListNode *createListNode(point pos)
{
	ListNode *node;
	
	node = malloc(sizeof(ListNode));
	if (!node)
		error("Memory Allocation Error");
	node->data.row = pos.row;
	node->data.col = pos.col;
	node->pLink = NULL;
	return (node);
}

/*
 * createLinkedList() - Create Linked List
 *
 * return	: LinkedList의 포인터
 */
LinkedList *createLinkedList()
{
	LinkedList *list;

	list = (LinkedList *)calloc(1, sizeof(LinkedList));
	if (!list)
		error("Memory Allocation Error");
	return (list);
}

/*
 * addLLElement() - Linked List의 position 위치에 element 추가
 *
 * return	: 1 / 0
 * pList	: Linked List의 포인터
 * position : element를 추가할 위치
 * element	: 추가할 element
 */
int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *prev;
	ListNode *node;
	
	if (!pList || position < 0 || position > pList->currentElementCount)
		return (EXIT_FAILURE);
	node = createListNode(element.data);
	prev = getLLElement(pList, position - 1);
	node->pLink = prev->pLink;
	prev->pLink = node;
	pList->currentElementCount++;
	return (EXIT_SUCCESS);
}

/*
 * removeLLElement() - Linked List의 position 위치의 node 삭제
 *
 * return	: 1 / 0
 * pList	: Linked List의 포인터
 * position	: 삭제할 node의 위치
 */
int removeLLElement(LinkedList* pList, int position)
{
	ListNode *removed;
	ListNode *prev;

	if (!pList || position < 0 || position >= getLinkedListLength(pList) || !pList->headerNode.pLink)
		return (EXIT_FAILURE);
	prev = getLLElement(pList, position - 1);
	removed = prev->pLink;
	prev->pLink = removed->pLink;
	free(removed);
	pList->currentElementCount--;
	return (EXIT_SUCCESS);
}

/*
 * getLinkedListLength() - Linked List의 노드의 갯수 반환
 *
 * return	: 노드의 갯수
 * pList	: Linked List의 포인터
 */
int getLinkedListLength(LinkedList* pList)
{
	if (!pList)
		return (-1);
	return (pList->currentElementCount);
}

int isLinkedListEmpty(LinkedList* pList)
{
	if (!pList)
		return (-1);
	if (pList->currentElementCount == 0)
		return (1);
	else
		return (0);
}

/*
 * clearLinkedList() - Linked List의 노드 삭제
 *
 * return	: None
 * pList	: Linked List의 포인터
 */
void clearLinkedList(LinkedList* pList)
{
	ListNode *temp;
	ListNode *removed;

	if (!pList)
		return ;
	temp = pList->headerNode.pLink;
	if (!temp)
		return ;
	while (pList->currentElementCount)
	{
		removed = temp;
		temp = temp->pLink;
		free(removed);
		pList->currentElementCount--;
	}
	assert(pList->currentElementCount == 0);
}

/*
 * deleteLinkedList() - Destroy Linked List
 *
 * return	: None
 * pList	: Linked List의 포인터
 */
void deleteLinkedList(LinkedList* pList)
{
	if (!pList)
		return ;
	clearLinkedList(pList);
	free(pList);
}

/*
 * getLLElement() - position 위치의 node 반환
 *
 * return	: Node의 포인터
 * pList	: Linked List의 포인터
 * position	: 반환할 Node의 위치
 */
ListNode *getLLElement(LinkedList* pList, int position)
{
	ListNode *temp;
	int i;

	if (!pList || position < -1 || position >= pList->currentElementCount)
		return (NULL);
	if (position == -1)
		return (&pList->headerNode);
	temp = pList->headerNode.pLink;
	i = 0;
	while (i < position)
	{
		i++;
		temp = temp->pLink;
	}
	return (temp);
}

/*
 * display() - Linked List 내용 출력
 *
 * return	: None
 * pList	: Linked List의 포인터
 */
void display(LinkedList *pList)
{
	ListNode *temp;

	temp = pList->headerNode.pLink;
	printf("currentElementCount : %d\n", getLinkedListLength(pList));
	if (!temp)
	{
		printf("Empty List\n");
		return ;
	}
	while (temp)
	{
		printf(" (%.2d, %.2d)", temp->data.row, temp->data.col);
		temp = temp->pLink;
	}
	printf("\n");
}

/*
 * reverseLinkedList() - Linked List를 역순으로 변경
 *
 * return	: None
 * pList	: Linked List의 포인터
 */
void reverseLinkedList(LinkedList* pList)
{
	ListNode *prev, *curr = NULL, *node;
	
	if (!pList)
		return ;
	node = pList->headerNode.pLink;
	while (node != NULL)
	{
		prev = curr;
		curr = node;
		node = node->pLink;
		curr->pLink = prev;
	}
	pList->headerNode.pLink = curr;
}