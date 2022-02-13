#include "linkeddeque.h"

static DequeNode *createNode(char data)
{
    DequeNode *DQ_node;
    DQ_node = calloc(1, sizeof(DequeNode));
    if (!DQ_node)
        return (NULL);
    DQ_node->data = data;
    return (DQ_node);
}

LinkedDeque* createLinkedDeque()
{
	LinkedDeque *LDQ;
	LDQ = calloc(1,sizeof(LinkedDeque));
	if(!LDQ)
		return NULL;
	return (LDQ);
}
int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *node;
	if (!pDeque)
		return (FALSE);
	node = createNode(element.data);
	if (isLinkedDequeEmpty(pDeque) == TRUE)
	{
		pDeque->pFrontNode = node;
		pDeque->pRearNode = node;
	}
	else if (isLinkedDequeEmpty(pDeque) == FALSE)
	{
		pDeque->pFrontNode->pLLink = node;
		node->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode = node;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}
int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *node;
	if (!pDeque)
		return (FALSE);
	node = createNode(element.data);
	if (isLinkedDequeEmpty(pDeque) == TRUE)
	{
		pDeque->pRearNode = node;
		pDeque->pFrontNode = node;
	}
	else if (isLinkedDequeEmpty(pDeque) == FALSE)
	{
		pDeque->pRearNode->pRLink = node;
		node->pLLink = pDeque->pRearNode;
		pDeque->pRearNode = node;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}
DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	int count;
	DequeNode *pReturn;
	count = pDeque->currentElementCount;
	if (!pDeque)
		return NULL;
	if (isLinkedDequeEmpty(pDeque))
	{
		printf("is already EMPTY\n");
		return (FALSE);
	}	
	pReturn = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	pReturn->pRLink = NULL;
	if (count == 1)
		pDeque->pRearNode = NULL;
	else
		pDeque->pFrontNode->pLLink = NULL;
	pDeque->currentElementCount--;
	return (pReturn);
	
}
DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	int count;
	DequeNode *pReturn;
	count = pDeque->currentElementCount;
	if (!pDeque)
		return NULL;
	if (isLinkedDequeEmpty(pDeque))
	{
		printf("is already EMPTY\n");
		return (FALSE);
	}	
	pReturn = pDeque->pRearNode;
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	pReturn->pLLink = NULL;
	if (count == 1)
		pDeque->pFrontNode = NULL;
	else
		pDeque->pRearNode->pRLink = NULL;
	pDeque->currentElementCount--;
	return (pReturn);
}
DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	if (!pDeque)
		return (NULL);
	return (pDeque->pFrontNode);
}
DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	if (!pDeque)
		return (NULL);
	return (pDeque->pRearNode);
}
void deleteLinkedDeque(LinkedDeque* pDeque)
{
	if (!pDeque)
		return ;
	DequeNode *curr;
	DequeNode *next;
	curr = pDeque->pFrontNode;
	while (curr)
	{
		next = curr->pRLink;
		free(curr);
		curr = next;
	}
	free(pDeque);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
    if (!pDeque)
        return (-1);
    if (pDeque->pFrontNode == NULL && pDeque->pRearNode == NULL)
        return (TRUE);
    else
        return(FALSE);
}
void display(LinkedDeque *pDeque)
{
	DequeNode *temp;
	temp = pDeque->pFrontNode;
	while(temp)
	{
		printf("[%c] <-> ",(*temp).data);
		temp = temp->pRLink;
	}
	printf("\n");
}

int main()
{
	LinkedDeque *test;

	test = createLinkedDeque();

	DequeNode node_arr[10];

	for (int i = 0 ; i < 6 ; i++)
	{
		node_arr[i].data = 'a' + i;
		insertFrontLD(test, node_arr[i]);
		display(test);
	}
	for (int i = 0 ; i < 6 ; i++)
	{
		node_arr[i].data = 'z' - i;
		insertRearLD(test, node_arr[i]);
		display(test);
	}
	for (int i = 0 ; i < 6 ; i++)
	{
		DequeNode *temp = deleteFrontLD(test);
		free(temp);
		display(test);
	}
	// for (int i = 0 ; i < 6 ; i++)
	// {
	// 	deleteRearLD(test);
	// 	display(test);
	// }
	system("leaks a.out");
}