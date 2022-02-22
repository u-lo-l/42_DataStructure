#include "avl_tree.h"
#include <stdlib.h>
#include <stdio.h>


int calcHeight(BinTreeNode *pNode)
{
	int leftChildHeight;
	int rightChildHeight;

	if (pNode == NULL)
		return (-1);
	// printf("<calhgh> : %d\n", pNode->data);
	leftChildHeight = calcHeight(pNode->pLeftChild);
	// printf("chL -> %d\n", leftChildHeight);
	rightChildHeight = calcHeight(pNode->pRightChild);
	// printf("chR -> %d\n", rightChildHeight);
	pNode->height = 1 + max(leftChildHeight, rightChildHeight);
	// printf("data : %d, height : %d\n", pNode->data, pNode->height);
	return (pNode->height);
}

int calcBalance(BinTreeNode *pNode)
{
	int leftChildHeight;
	int rightChildHeight;
	if (!pNode)
		return (-1);
	// printf("<calbal> : %d\n", pNode->data);
	leftChildHeight = calcHeight(pNode->pLeftChild);
	// printf("cbL -> %d\n", leftChildHeight);
	rightChildHeight = calcHeight(pNode->pRightChild);
	// printf("cbR -> %d\n", rightChildHeight);
	pNode->balance = leftChildHeight - rightChildHeight;
	// printf("data : %d, balance : %d\n", pNode->data, pNode->balance);
	return (pNode->balance);
}

BinTreeNode *balanceTree(BinTreeNode *pNode)
{
	printf("Balancing\n");
	int balance;
	int subtreeBalance;
	if (!pNode)
		return (NULL);
	// printf("pivot : %d\n", pNode->data);
	balance = calcBalance(pNode);
	// printf("factor : %d\n", balance);
	if (balance > 1) // LL or LR 문제
	{
		subtreeBalance = calcBalance(pNode->pLeftChild);
		// printf("subfactor : %d\n", subtreeBalance);
		if (subtreeBalance > 0) //LL 문제
			pNode = rotate_LL(pNode);
		else					//LR 문제
			pNode = rotate_LR(pNode);
	}
	else if (balance < -1) // RR or RL 문제
	{
		subtreeBalance = calcBalance(pNode->pRightChild);
		// printf("subfactor : %d\n", subtreeBalance);
		if (subtreeBalance < 0) //RR 문제
			pNode = rotate_RR(pNode);
		else					//RL 문제
			pNode = rotate_RL(pNode);
	}
	else
		printf("balanced!\n");
	// printf("PNODE -> %d\n", pNode->data);
	return (pNode);
}

BinTreeNode *rotate_LL(BinTreeNode *pNode)
{
	BinTreeNode *temp;
	printf("LL Rotation\n");
	temp = pNode->pLeftChild;
	pNode->pLeftChild = temp->pRightChild;
	temp->pRightChild = pNode;
	return (temp);
}
BinTreeNode *rotate_RR(BinTreeNode *pNode)
{
	BinTreeNode *temp;
	printf("RR Rotation\n");
	temp = pNode->pRightChild;
	pNode->pRightChild = temp->pLeftChild;
	temp->pLeftChild = pNode;
	return (temp);
}
BinTreeNode *rotate_LR(BinTreeNode *pNode)
{
	BinTreeNode *temp;
	printf("LR Rotation\n");
	temp = pNode->pLeftChild;
	pNode->pLeftChild = rotate_RR(temp);
	temp = rotate_LL(pNode);
	return (temp);
}
BinTreeNode *rotate_RL(BinTreeNode *pNode)
{
	BinTreeNode *temp;
	printf("RL Rotation\n");
	temp = pNode->pRightChild;
	pNode->pRightChild = rotate_LL(temp);
	temp = rotate_RR(pNode);
	return (temp);
}

int		addNodeAVL(BinTree *bst, BinTreeNode element)
{
	if (!bst)
	{
		printf("\033[0;31m<ERR> Invalid tree\n\033[0m");
		return (-1);
	}
	bst->pRootNode = addNodeBSTrecursive(bst->pRootNode, element, balanceTree);
}

int		deleteNodeAVL(BinTree *bst, int data)
{
	printf("\033[0;31mtarget data : %d\n\033[0;36m", data);
	bst->pRootNode = deleteNodeBSTrecursive(bst, bst->pRootNode, data, balanceTree);
}