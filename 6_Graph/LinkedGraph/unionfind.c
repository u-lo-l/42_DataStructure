#include "linkedgraph.h"
#include <stdlib.h>

int *initParentTable(LinkedGraph *pGraph)
{
	int	*parentTable;

	if (!pGraph || pGraph->maxVertexCount < 1)
		return (NULL);
	parentTable = malloc(sizeof(int) * pGraph->maxVertexCount);
	if (!parentTable)
		return (NULL);
	for (int i = 0 ; i < pGraph->maxVertexCount ; i++)
		parentTable[i] = i;
	return (parentTable);
}

int	getUnionParent(int *circularTable, int a)
{
	if (circularTable[a] == a)
		return (a);
	circularTable[a] = getUnionParent(circularTable, circularTable[a]);
	return (circularTable[a]);
}

void unionParent(int *circularTable, int a, int b)
{
	a = getUnionParent(circularTable, a);
	b = getUnionParent(circularTable, b);
	if (a < b)
		circularTable[b] = a;
	else
		circularTable[a] = b;
}

int	findParent(int *circularTable, int a, int b)
{
	a = getUnionParent(circularTable, a);
	b = getUnionParent(circularTable, b);
	if (a == b)
		return (1);
	else
		return (0);
}

int isGraphConnected(LinkedGraph *pGraph)
{
	int *unionArray;
	ListNode *curr;

	if (!pGraph)
		return (ERROR);
	if (pGraph->maxVertexCount != pGraph->currentVertexCount)
		return (FALSE);
	unionArray = initParentTable(pGraph);
	for (int i = 0; i < pGraph->maxVertexCount ; i++)
	{
		curr = pGraph->ppAdjEdge[i]->headerNode.pLink;
		while (curr != NULL)
		{
			unionParent(unionArray, i, curr->ID);
			curr=curr->pLink;
		}
		if (unionArray[i] != 0)
		{
			free(unionArray);
			return (FALSE);
		}
	}
	free(unionArray);
	return (TRUE);
}