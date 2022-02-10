#include "arraystack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArrayStack	*createArrayStack(int maxElementCount)
{
	ArrayStack	*pReturn = NULL;

	if (!maxElementCount)
		return (NULL);
	pReturn = (ArrayStack *)malloc(sizeof(ArrayStack));
	if (!pReturn)
		return (NULL);
	memset(pReturn, 0, sizeof(ArrayStack));
	pReturn->maxElementCount = maxElementCount;
	pReturn->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);
	if (!(pReturn->pElement))
		return (NULL);
	memset(pReturn->pElement, 0, sizeof(ArrayStackNode) * maxElementCount);

	return (pReturn);
}

int	pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	int	ret = FALSE;

	if (pStack)
	{
		if (isArrayStackFull(pStack) == FALSE)
		{
			pStack->pElement[pStack->currentElementCount] = element;
			pStack->currentElementCount++;
			ret = TRUE;
		}
	}
	return (ret);
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
	ArrayStackNode*	ret = NULL;

	if (pStack)
	{
		if (isArrayStackEmpty(pStack) == FALSE)
		{
			ret = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
			if (ret)
			{
				*ret = pStack->pElement[pStack->currentElementCount - 1];
				pStack->currentElementCount--;
			}
		}
	}
	return (ret);
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
	ArrayStackNode*	ret = NULL;

	if (pStack)
	{
		if (isArrayStackEmpty(pStack) == FALSE)
			ret = &(pStack->pElement[pStack->currentElementCount - 1]);
	}
	return (ret);
}

void deleteArrayStack(ArrayStack* pStack)
{
	if (pStack)
	{
		if (pStack->pElement)
			free(pStack->pElement);
		free(pStack);
	}
}

int isArrayStackFull(ArrayStack* pStack)
{
	int	ret = FALSE;

	if (pStack)
	{
		if (!(pStack->pElement))
		{
			if (pStack->currentElementCount == pStack->maxElementCount)
				ret = TRUE;
		}
	}
	return (ret);
}

int	isArrayStackEmpty(ArrayStack* pStack)
{
	int	ret = FALSE;

	if (pStack)
	{
		if (!(pStack->pElement))
		{
			if (pStack->currentElementCount == 0)
				ret = TRUE;
		}
	}
	return (ret);
}