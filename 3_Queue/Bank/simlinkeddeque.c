#include "simlinkeddeque.h"
#include "simdef.h"

DequeNode *initNode()
{
	DequeNode *new_node;
	new_node = calloc(1, sizeof(DequeNode));
	if (!new_node)
		return (NULL);
	return (new_node);
}

static DequeNode *createNode(SimCustomer data)
{
	DequeNode * DQ_node;
	DQ_node = initNode();
	if (!DQ_node)
		return (NULL);
	DQ_node->customer_data.status = data.status;
	DQ_node->customer_data.arrivalTime = data.arrivalTime;
	DQ_node->customer_data.serviceTime = data.serviceTime;
	DQ_node->customer_data.startTime = data.startTime;
	DQ_node->customer_data.endTime = data.endTime;
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
	node = createNode(element.customer_data);
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
	node = createNode(element.customer_data);
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
		return (NULL);
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
	int i = 1;
	while(temp)
	{
		printf("-----Customer Info%.2d-----\n", i);
		printf("STATUS  : %.2d\n", temp->customer_data.status);
		printf("ARRIVAL : %.2d | ", temp->customer_data.arrivalTime);
		printf("SERVICE : %.2d\n", temp->customer_data.serviceTime);
		printf("START   : %.2d | ", temp->customer_data.startTime);
		printf("END     : %.2d\n", temp->customer_data.endTime);
		printf("-------------------------\n");
		temp = temp->pRLink;
		i++;
	}
}