#include "redblacktree.h"
#include "../Queue/linkedqueue.h"
#include <stdio.h>
#define max_mcr(x,y) ((x>y)?(x):(y))

int printNodeInfo(RBTreeNode *pNode)
{
	char p, l, r;
	if (!pNode)
		return (0);
	if (pNode->color == red)
		printf("\033[0;31m");
	else
		printf("\033[0;33m");
	p = pNode->pParent->data;
	l = pNode->pLeftChild->data;
	r = pNode->pRightChild->data;

	printf("I:%d[%c|%c, %c, %c]\n", pNode->index, pNode->data, p, l, r);
	printf("\033[0m");
	return (1);
}

void showTreePreorder(RBTree *pTree)
{
	printf("Print by PreOrder\n");
	preorderTraversal(pTree, pTree->pRootNode, printNodeInfo);
}

void showTreeInorder(RBTree *pTree)
{
	printf("Print by InOrder\n");
	inorderTraversal(pTree, pTree->pRootNode, printNodeInfo);
}

void showTreePostorder(RBTree *pTree)
{
	printf("Print by PostOrder\n");
	postorderTraversal(pTree, pTree->pRootNode, printNodeInfo);
}

void showTreeLevelorder(RBTree *pTree)
{
	printf("Print by LevelOrder\n");
	levelorderTraversal(pTree, printNodeInfo);
}

static int setNodeIndexLevel(RBTree *pRBTree, RBTreeNode *pNode, int index, int level);
void setTreeInfo(RBTree *pRBTree)
{
	if (!pRBTree)
		printf("invalid Tree\n");
	else
		pRBTree->treeheight = setNodeIndexLevel(pRBTree, pRBTree->pRootNode, 1, 1);
}
static int setNodeIndexLevel(RBTree *pTree, RBTreeNode *pN, int I, int L)
{
	if (!pN || pN == pTree->nilNode)
		return (L - 1);
	int L_depth, R_depth, ret;
	pN->index = I;
	pN->level = L;
	L_depth = setNodeIndexLevel(pTree, pN->pLeftChild, 2 * I , L + 1);
	R_depth = setNodeIndexLevel(pTree, pN->pRightChild, 2 * I + 1, L + 1);
	ret = max_mcr(L_depth, R_depth);
	return (ret);
}

static void printDataAndBlank(QueueNode * qNode,int TreeDepth, int currIndex);
void showRBTreeStructure(RBTree *pTree)
{
	LinkedQueue *queue;
	QueueNode	*firstNode = NULL;
	QueueNode	tempNode;
	int			index = 1;

	if (!pTree)
		return ;
	if (pTree->pRootNode == NULL || pTree->pRootNode == pTree->nilNode)
	{
		printf("\033[1;31m\tEmpty Tree\n\033[0m");
		return ;
	}
	setTreeInfo(pTree);
	tempNode.node = *(pTree->pRootNode);
	queue = createLinkedQueque();
	enqueueLQ(queue, tempNode);
	while(!isLinkedQueueEmpty(queue))
	{
		firstNode = peekLQ(queue);
		if(firstNode->node.index == index)
		{
			firstNode = dequeueLQ(queue);
			if (firstNode->node.pLeftChild != pTree->nilNode)
			{
				tempNode.node = *(firstNode->node.pLeftChild);
				enqueueLQ(queue, tempNode);
			}
			if (firstNode->node.pRightChild != pTree->nilNode)
			{
				tempNode.node = *(firstNode->node.pRightChild);
				enqueueLQ(queue, tempNode);
			}
		}
		else
			firstNode = NULL;
		printDataAndBlank(firstNode, pTree->treeheight, index);
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
static void printDataAndBlank(QueueNode *qNode,int treeheight, int currI)
{
	int level, totalField, blanksize;

	char dataStr[4];
	dataStr[0] = ' ';
	dataStr[1] = ' ';
	dataStr[2] = ' ';
	dataStr[3] = 0;
	totalField = power(2, treeheight - 1) * (3 + 1); //3 : field for data, 1 : field for smallest blank;
	level = getLevelByIndex(currI);
	blanksize = totalField / power(2, level - 1) - 3;
	// printf("treeheight : %d-> total field : %d curr level = %d -> blanksize : %d\n", treeheight, totalField, level, blanksize);
	if (currI == power(2, level - 1))
		printf("\nlevel%2d ", level);
	if (qNode)
	{
		dataStr[0] = '[';
		dataStr[1] = qNode->node.data;
		dataStr[2] = ']';
		if (qNode->node.color == red)
			printf("\033[0;31m");
		else if (qNode->node.color == black)
			printf("\033[0;90m");
	}
	for (int i = 0 ; i < blanksize ; i++)
	{
		if (i == blanksize / 2) printf("%s\033[0m", dataStr);
		printf(" ");
	}
	if (currI + 1== power(2, level))
		printf("\n");
}
