#include "polynomial.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

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

DoublyListNode *createNode(t_coef c, t_exp e)
{
	DoublyListNode *node;

	node = calloc(1, sizeof(DoublyListNode));
	if (!node)
		return (NULL);
	node->data.coef = c;
	node->data.exp = e;
	return (node);
}

int addDLElement(DoublyList* pList, int position, t_coef c, t_exp e)
{
	DoublyListNode *node;
	DoublyListNode *prev;

	if (!pList || position < 0 ||position > pList->currentElementCount)
		return (EXIT_FAILURE);
	node = createNode(c, e);
	prev = getDLElement(pList, position - 1);
	node->pLLink = prev;
	node->pRLink = prev->pRLink;
	prev->pRLink->pLLink = node;
	prev->pRLink = node;
	pList->currentElementCount++;
	return (EXIT_SUCCESS);
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode *target;
	DoublyListNode *prev;

	if (!pList || position < 0 || position >= pList->currentElementCount || pList->headerNode.pRLink == &pList->headerNode)
		return (EXIT_FAILURE);;
	target = getDLElement(pList, position);
	prev = target->pLLink;
	prev->pRLink = target->pRLink;
	target->pRLink->pLLink = target->pLLink;
	free(target);
	pList->currentElementCount--;
	return (EXIT_SUCCESS);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode *node;
	int i;

	if (!pList || position < -1 || position >= pList->currentElementCount)
		return (NULL);
	if (position == -1)
		return (&pList->headerNode);
	if (position < pList->currentElementCount / 2)
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

int getDoublyListLength(DoublyList* pList)
{
	if (!pList)
		return (-1);
	return (pList->currentElementCount);
}

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

void deleteDoublyList(DoublyList* pList)
{
	if (!pList)
		return ;
	clearDoublyList(pList);
	free(pList);
}

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
		printf("%.1fX^%d + ", temp->data.coef, temp->data.exp);
		temp = temp->pRLink;
	}
	printf("\n");
}

DoublyList *addPolynomials(DoublyList *poly1, DoublyList *poly2)
{
	DoublyList *ret;
	DoublyListNode *node1;
	DoublyListNode *node2;

	if (!poly1 || !poly2)
		return (NULL);
	ret = createDoublyList();
	node1 = poly1->headerNode.pRLink;
	node2 = poly2->headerNode.pRLink;

	// 하나가 끝나기 전에 차수 비교해서 저장	
	while (node1 != &poly1->headerNode && node2 != &poly2->headerNode)
	{
		if (node1->data.exp > node2->data.exp)
		{
			addDLElement(ret, ret->currentElementCount, node1->data.coef, node1->data.exp);
			node1 = node1->pRLink;
		}
		else if (node1->data.exp < node2->data.exp)
		{
			addDLElement(ret, ret->currentElementCount, node2->data.coef, node2->data.exp);
			node2 = node2->pRLink;
		}
		else // 차수가 같을떄
		{
			if (node1->data.coef + node2->data.coef)
			{
				int temp_coef = node1->data.coef + node2->data.coef;
				addDLElement(ret, ret->currentElementCount, temp_coef, node1->data.exp);
			}
			node1 = node1->pRLink;
			node2 = node2->pRLink;
		}
	}
	// node 1 나머지 저장
	while (node1 != &poly1->headerNode)
	{
		addDLElement(ret, ret->currentElementCount, node1->data.coef, node1->data.exp); 
		node1 = node1->pRLink;
	}
	// node 2 나머지 저장
	while (node2 != &poly2->headerNode)
	{
		addDLElement(ret, ret->currentElementCount, node2->data.coef, node2->data.exp);
		node2 = node2->pRLink;
	}
	return (ret);
}

int main(void)
{
	DoublyList *poly1 = createDoublyList();
	DoublyList *poly2 = createDoublyList();

	addDLElement(poly1, 0, 1, 6);
	addDLElement(poly1, 1, 2, 3);
	addDLElement(poly1, 2, 3, 1);
	displayDoublyList(poly1); // x^6 + 2x^3 + 3x

	addDLElement(poly2, 0, 3, 5);
	addDLElement(poly2, 1, -2, 3);
	addDLElement(poly2, 2, 1, 0);
	displayDoublyList(poly2); // 3x^5 + -2x^3 + 1x^0

	DoublyList *ret = addPolynomials(poly1, poly2);
	displayDoublyList(ret);
	// x^6 + 3x^5 + 3x^1 + 1x^0
}
