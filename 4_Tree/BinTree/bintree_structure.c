#include "bintree.h"
#include "../Queue/linkedqueue.h"
#include <stdio.h>
#include <stdlib.h>
#define max_mcr(x,y) ((x>y)?(x):(y))

static int setNodeIndexLevel(BinTreeNode *pNode, int index, int level);
void setTreeInfo(BinTree *pBinTree)
{
	if (!pBinTree)
		printf("invalid Tree\n");
	else
		pBinTree->depth = setNodeIndexLevel(pBinTree->pRootNode, 1, 1);
}
static int setNodeIndexLevel(BinTreeNode *pN, int I, int L)
{
	if (!pN)
		return (L - 1);
	int L_depth, R_depth, ret;
	pN->index = I;
	pN->level = L;
	L_depth = setNodeIndexLevel(pN->pLeftChild, 2 * I , L + 1);
	R_depth = setNodeIndexLevel(pN->pRightChild, 2 * I + 1, L + 1);
	ret = max_mcr(L_depth, R_depth);
	return (ret);
}

static void printDataAndBlank(QueueNode * qNode,int TreeDepth, int currIndex);
void showBinTreeStructure(BinTree *pTree)
{
	LinkedQueue *queue;
	QueueNode	*firstNode = NULL;
	QueueNode	tempNode;
	int			index = 1;

	if (!pTree)
		return ;
	tempNode.node = *(pTree->pRootNode);
	queue = createLinkedQueque();
	enqueueLQ(queue, tempNode);
	while(!isLinkedQueueEmpty(queue))
	{
		// printf("I : %d\n", index);
		firstNode = peekLQ(queue);
		if(firstNode->node.index == index)
		{
			// printf("node yes\n");
			firstNode = dequeueLQ(queue);
			if (firstNode->node.pLeftChild)
			{
				tempNode.node = *(firstNode->node.pLeftChild);
				enqueueLQ(queue, tempNode);
			}
			if (firstNode->node.pRightChild)
			{
				tempNode.node = *(firstNode->node.pRightChild);
				enqueueLQ(queue, tempNode);
			}
		}
		else
			firstNode = NULL;
		printDataAndBlank(firstNode, pTree->depth, index);
		index++;
	}
	printf("\n");
	free(firstNode);
	deleteLinkedQueue(queue);
}


static int power(int base, int power)
{
	int ret = 1;
	for (int i = 0 ; i < power ; i++)
		ret = ret * base;
	return (ret);
}
static int getLevelByIndex(int index)
{
	int level = 0;
	while (index > 0)
	{
		index = index / 2;
		level++;
	}
	return (level);
}
static void printDataAndBlank(QueueNode *qNode,int depth, int currI)
{
	int level, totalField, blanksize;

	char dataStr[4];
	dataStr[0] = '[';
	dataStr[1] = ' ';
	dataStr[2] = ']';
	dataStr[3] = 0;
	totalField = power(2, depth - 1) * (3 + 1); //3 : field for data, 1 : field for smallest blank;
	level = getLevelByIndex(currI);
	blanksize = totalField / power(2, level - 1) - 3;
	// printf("Depth : %d-> total field : %d curr level = %d -> blanksize : %d\n", depth, totalField, level, blanksize);
	if (qNode)
		dataStr[1] = qNode->node.data;
	if (currI == power(2, level - 1))
		printf("\nlevel%2d ", level);
	for (int i = 0 ; i < blanksize ; i++)
	{
		if (i == blanksize / 2) printf("%s", dataStr);
		printf(" ");
	}
	if (currI + 1== power(2, level))
		printf("\n");
}
