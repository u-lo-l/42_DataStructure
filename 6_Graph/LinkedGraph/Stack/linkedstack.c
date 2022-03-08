#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * createLSNode() - Create Linkedstake Node
 * 
 * return : 생성된 node의 포인터
 * data : Node에 저장될 데이터
 */
StackNode *createLSNode(char data)
{
	StackNode *lsnode;

	lsnode = (StackNode *)calloc(1, sizeof(StackNode));
	if (!lsnode)
		return (NULL);
	lsnode->data = data;
	return (lsnode);
}

/*
 * createLinkedStack() - Create Linked Stack
 * 
 * return : 생성된 Linked Stack의 포인터
 */
LinkedStack* createLinkedStack()
{
	LinkedStack *lstack;

	lstack = (LinkedStack *)calloc(1, sizeof(LinkedStack));
	if (!lstack)
		return (NULL);
	return (lstack);
}

/*
 * pushLS() - insert the passed node(item) at the top of the stack
 *
 * return : 0 for success or 1 for failure;
 */
int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode *new_item;

	if (!pStack)
		return (EXIT_FAILURE);
	new_item = createLSNode(element.data);
	new_item->pLink = pStack->pTopElement;
	pStack->pTopElement = new_item;
	pStack->currentElementCount++;
	return (EXIT_SUCCESS);
}

/*
 * popLS() - return the node(item) at the top of the stack
 *
 * return : 
 */
StackNode* popLS(LinkedStack* pStack)
{
	StackNode *node_to_pop;

	node_to_pop = peekLS(pStack);
	if (!node_to_pop)
		return (NULL);
	pStack->pTopElement = node_to_pop->pLink;
	node_to_pop->pLink = NULL;
	pStack->currentElementCount--;
	return(node_to_pop);
}

/*
 * peek() - return the item(node) on the top
 *
 * return : 스택의 가장 마지막 item(node)의 포인터
 */
StackNode* peekLS(LinkedStack* pStack)
{
	if (!pStack || isLinkedStackEmpty(pStack))
		return (NULL);
	return (pStack->pTopElement);
}

/*
 * deleteLinkedStack() - remove all items in the stack and destroy stack
 *
 * return nothing;
 */
void deleteLinkedStack(LinkedStack* pStack)
{
	if (!pStack)
		return ;
	while (pStack->pTopElement)
		free(popLS(pStack));
	free(pStack);
}

/*???*/
int isLinkedStackFull(LinkedStack* pStack);

/*
 * isLinkedStackEmpty() - Check pStack has any element
 *
 * return 1(TRUE) for 'pStack->ptopElement == NULL' or 0(FALSE) for not.
 */
int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack)
		return (FALSE);
	if (!pStack->pTopElement)
		return (TRUE);
	else
		return (FALSE);
}

void printLinkedStack(LinkedStack *pStack)
{
	StackNode *node;

	if (isLinkedStackEmpty(pStack))
	{
		printf("EMPTY STACK\n");
		return ;
	}
	node = pStack->pTopElement;
	printf("count : %d\n", pStack->currentElementCount);
	printf("[top]");
	while (node)
	{
		printf(" <%d>", node->data);
		node = node->pLink;
	}
	printf("\n");
	return ;
}