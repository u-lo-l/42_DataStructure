/*
 * Doubly List
 * Author	: minjkim2, dkim2
 * Language	:  C
 */
#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
 * createDoublyList() - Create Doubly List
 *
 * return	: Pointer of doubly list
 */
DoublyList *createDoublyList()
{
	DoublyList *list;

	list = (DoublyList *)calloc(1, sizeof(DoublyList));
	if (!list)
		return (NULL);
	list->headerNode.pLLink = &list->headerNode;
	list->headerNode.pRLink = &list->headerNode;
	return (list);
}

/*
 * createNode() - Create Doubly List Node
 *
 * return	: Pointer of Node
 */
DoublyListNode *createNode(int data)
{
	DoublyListNode *node;

	node = calloc(1, sizeof(DoublyListNode));
	if (!node)
		return (NULL);
	node->data = data;
	return (node);
}

/*
 * addDLElement() - List의 position 위치에 element 추가
 *
 * return	: 1 / 0
 * pList	: List의 포인터
 * position	: 추가할 노드의 위치
 * element	: 추가할 node
 */
int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *node;
	DoublyListNode *prev;

	if (!pList || position < 0 ||position > pList->currentElementCount)
		return (EXIT_FAILURE);
	node = createNode(element.data);
	// prev node prev->pRLink
	prev = getDLElement(pList, position - 1); // 추가할 위치의 전 노드를 가져옴
	node->pLLink = prev; // node의 왼쪽 링크 연결
	node->pRLink = prev->pRLink; // node의 오른쪽 링크 연결
	prev->pRLink->pLLink = node; // 추가할 위치의 다음 노드의 왼쪽 링크 연결
	prev->pRLink = node; // 추가할 위치의 전 노드의 오른쪽 링크 연결
	pList->currentElementCount++;
	return (EXIT_SUCCESS);
}

/*
 * removeDLElement() - List의 position 위치의 노드 삭제
 *
 * return	: 1 / 0
 * pList	: List의 포인터
 * position	: 삭제할 노드의 위치
 */
int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode *target;
	DoublyListNode *prev;

	if (!pList || position < 0 || position >= pList->currentElementCount || pList->headerNode.pRLink == &pList->headerNode)
		return (EXIT_FAILURE);;
	target = getDLElement(pList, position); // target : 삭제할 노드
	prev = target->pLLink; // prev : 삭제할 노드의 전 노드
	prev->pRLink = target->pRLink; // prev의 오른쪽 링크를 taget의 오른쪽 링크로 연결
	target->pRLink->pLLink = target->pLLink; // target의 오른쪽 노드의 왼쪽 링크를 target의 왼쪽 노드로 연결
	free(target); // targe 삭제
	pList->currentElementCount--;
	return (EXIT_SUCCESS);
}

/*
 * getDLElement() - List의 position 위치의 노드 반환
 *
 * return	: Node의 포인터
 * pList	: List의 포인터
 * position	: 반환할 노드의 위치
 */
DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode *node;
	int i;

	if (!pList || position < -1 || position >= pList->currentElementCount)
		return (NULL);
	if (position == -1) // position이 -1 이면 headerNode의 주소 반환
		return (&pList->headerNode);
	if (position < pList->currentElementCount / 2) // position의 위치에 따라 앞 / 뒤에서부터 검색
	{
		i = 0;
		node = pList->headerNode.pRLink;
		while (i < position)
		{
			node = node->pRLink;
			i++;
		}
	}
	else
	{
		i = pList->currentElementCount - 1;
		node = pList->headerNode.pLLink;
		while (i > position)
		{
			node = node->pLLink;
			i--;
		}
	}
	return (node);
}

/*
 * getDoublyListLength() - List의 길이 반환
 *
 * return	: List의 노드의 갯수
 * pList	: List의 포인터
 */
int getDoublyListLength(DoublyList* pList)
{
	if (!pList)
		return (-1);
	return (pList->currentElementCount);
}

/*
 * clearDoublyList() - List의 노드 전체 삭제
 *
 * return	: None
 * pList	: List의 포인터
 */
void clearDoublyList(DoublyList* pList)
{
	DoublyListNode *temp;
	DoublyListNode *removed;

	if (!pList)
		return ;
	temp = pList->headerNode.pRLink;
	while (0 < pList->currentElementCount)
	{
		removed = temp;
		temp = temp->pRLink;
		free(removed);
		pList->currentElementCount--;
	}
	assert(pList->currentElementCount == 0);
}

/*
 * deleteDoublyList() - List 삭제
 *
 * return	: None
 * pList	: List의 포인터
 */
void deleteDoublyList(DoublyList* pList)
{
	if (!pList)
		return ;
	clearDoublyList(pList);
	free(pList);
}

/*
 * displayDoublyList() - List 출력
 *
 * return	: None
 * pList	: List의 포인터
 */
void displayDoublyList(DoublyList* pList)
{
	DoublyListNode *temp;
	
	if (!pList)
		return ;
	temp = pList->headerNode.pRLink;
	printf("currElementCount : %d\n", getDoublyListLength(pList));
	if (temp == &pList->headerNode)
	{
		printf("Empty\n");
		return ;
	}
	while (temp != &pList->headerNode)
	{
		printf("%d -> ", temp->data);
		temp = temp->pRLink;
	}
	printf("\n");
}

int	main(void)
{
	DoublyList *list;
	DoublyListNode node;

	list = createDoublyList();

	node.data = 10;
	addDLElement(list, 0, node);
	displayDoublyList(list);
	// 10

	node.data = 20;
	addDLElement(list, 0, node);
	displayDoublyList(list);
	// 20 -> 10

	node.data = 30;
	addDLElement(list, 2, node);
	displayDoublyList(list);
	// 20 -> 10 -> 30

	// removeDLElement(list, 0);
	// displayDoublyList(list);
	// // 10 -> 30

	// removeDLElement(list, 1);
	// displayDoublyList(list);
	// // 10

	// removeDLElement(list, 0);
	// displayDoublyList(list);
	// // NULL
	clearDoublyList(list);
	deleteDoublyList(list);
	// system("leaks a.out");
}
