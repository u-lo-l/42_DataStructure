#include "avl_tree.h"
#include <stdlib.h>
#include <stdio.h>


int calcHeight(BinTreeNode *pNode)
{
	int leftChildHeight;
	int rightChiidHeight;

	if (pNode == NULL)
		return (-1);
	leftChildHeight = calcHeight(pNode->pLeftChild);
	rightChiidHeight = calcHeight(pNode->pRightChild);
	pNode->height = 1 + max(leftChildHeight, rightChiidHeight);
	return (pNode->height);
}

int calcBalance(BinTreeNode *pNode)
{
	int leftChildHeight;
	int rightChiidHeight;
	if (!pNode)
		return (-1);
	leftChildHeight = calcHeight(pNode->pLeftChild);
	rightChiidHeight = calcHeight(pNode->pRightChild);
	pNode->balance = leftChildHeight - rightChiidHeight;
	return (pNode->balance);
}

void balanceTree(BinTreeNode *pNode)
{
	
	int balance;
	int subtreeBalance;
	if (!pNode)
		return ;
	
	balance = calcBalance(pNode);
	if (balance > 1) // LL or LR 문제
	{
		subtreeBalance = calcBalance(pNode->pLeftChild);
		if (subtreeBalance > 0) //LL 문제
			pNode = rotate_LL(pNode);
		else					//LR 문제
			pNode = rotate_LR(pNode);
	}
	else if (balance < -1) // RR or RL 문제
	{
		if (subtreeBalance < 0) //RR 문제
			pNode = rotate_RR(pNode);
		else					//RL 문제
			pNode = rotate_RL(pNode);
	}
	return (pNode);
}

BinTreeNode *rotate_LL(BinTreeNode *pNode)
{
	BinTreeNode *temp;

	temp = pNode->pLeftChild;
	pNode->pLeftChild = temp->pRightChild;
	temp->pRightChild = pNode;
	return (temp);
}
BinTreeNode *rotate_RR(BinTreeNode *pNode)
{
	BinTreeNode *temp;

	temp = pNode->pRightChild;
	pNode->pRightChild = temp->pLeftChild;
	temp->pLeftChild = pNode;
	return (temp);
}
BinTreeNode *rotate_LR(BinTreeNode *pNode)
{
	BinTreeNode *temp;

	temp = pNode->pLeftChild;
	pNode->pLeftChild = rotate_RR(temp);
	temp = rotate_LL(pNode);
	return (temp);
}
BinTreeNode *rotate_RL(BinTreeNode *pNode)
{
	BinTreeNode *temp;

	temp = pNode->pRightChild;
	pNode->pRightChild = rotate_LL(temp);
	temp = rotate_RR(pNode);
	return (temp);
}

int		addNodeAVL(BinTree *bst, BinTreeNode element)
{
	BinTreeNode *currNode;
	int newData;
	if (!bst)
	{
		printf("<ERR> Invalid tree\n");
		return (-1);
	}
	if (addNodeBSTrecursive(bst->pRootNode, element, balanceTree))
		return (TRUE);
	return (FALSE);
}

int		deleteNodeAVL(BinTree *binSearchTree, int data)
{
	deleteNodeBST(binSearchTree, data);
}
