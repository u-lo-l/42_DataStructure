/*
 * Linked List
 * Author	: minjkim2, dkim2
 * Language	:  C
 */
#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);
}

ListNode *createListNode(int data, int weight)
{
	ListNode *node;
	
	node = (ListNode *)malloc(sizeof(ListNode));
	if (!node)
		error("Memory Allocation Error");
	node->ID = data;
	node->visited = 0;
	node->weight = weight;
	node->pLink = NULL;
	return (node);
}

LinkedList *createLinkedList()
{
	LinkedList *list;

	list = (LinkedList *)calloc(1, sizeof(LinkedList));
	if (!list)
		error("Memory Allocation Error");
	return (list);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *prev;
	ListNode *node;
	int i;
	
	if (!pList || position < 0 || position > pList->currentElementCount)
		return (EXIT_FAILURE);
	i = 0;
	node = createListNode(element.ID, element.weight);
	prev = getLLElement(pList, position - 1);
	node->pLink = prev->pLink;
	prev->pLink = node;
	pList->currentElementCount++;
	return (EXIT_SUCCESS);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode *removed;
	ListNode *prev;
	int i;

	if (!pList || position < 0 || position >= getLinkedListLength(pList) || !pList->headerNode.pLink)
		return (EXIT_FAILURE);
	prev = getLLElement(pList, position - 1);
	removed = prev->pLink;
	prev->pLink = removed->pLink;
	free(removed);
	pList->currentElementCount--;
	return (EXIT_SUCCESS);
}

int getLinkedListLength(LinkedList* pList)
{
	if (!pList)
		return (-1);
	return (pList->currentElementCount);
}

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

void deleteLinkedList(LinkedList* pList)
{
	if (!pList)
		return ;
	clearLinkedList(pList);
	free(pList);
}


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

void displayLinkedList(LinkedList *pList)
{
	ListNode *temp;

	temp = pList->headerNode.pLink;

	while (1)
	{
		if (temp == NULL)
		{
			printf("------>null");
			break ;
		}
		printf("-(%2d)->", temp->weight);
		printf("\033[1;32m[%2d]\033[0m", temp->ID);
		temp = temp->pLink;
	}
	printf("\n");
}

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