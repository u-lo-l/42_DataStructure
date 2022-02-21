#include "binsearchtree.h"
#include <stdio.h>

static BinTreeNode *addNodeBSTrecursive(BinTreeNode *root, BinTreeNode element)
{
	if (element.data == root->data)
	{
		printf("Duplicated value is not allowed\n");
		return (NULL);
	}
	else if (element.data < root->data)
	{
		if (root->pLeftChild)
			addNodeBSTrecursive(root->pLeftChild, element);
		else
			insertLeftChildNodeBT(root->pLeftChild, element);
	}
	else
	{
		if (root->pRightChild)
			addNodeBSTrecursive(root->pRightChild, element);
		else
			insertRightChildNodeBT(root->pRightChild, element);
	}
}
int addNodeBST(BinTree *bst, BinTreeNode element)
{
	BinTreeNode *currNode;
	int newData;
	if (!bst)
	{
		printf("<ERR> Invalid tree\n");
		return (NULL);
	}
	addNodeBSTrecursive(bst->pRootNode, element);
}

static BinTreeNode* getNodeByDataBSTreculsive(BinTreeNode *root, int data)
{
	if (root == NULL)
		return (NULL);
	if (data == root->data)
		return (root);
	else if (data < root->data)
		return (getNodeByDataBSTreculsive(root->pLeftChild, data));
	else
		return (getNodeByDataBSTreculsive(root->pRightChild, data));
}
BinTreeNode* getNodeByDataBST(BinTree* bst, int data)
{
	BinTreeNode *currNode;
	if (!bst)
	{
		printf("<ERR> Invalid tree\n");
		return (NULL);
	}
	return (getNodeByDataBSTreculsive(bst->pRootNode, data));
}

static BinTreeNode *deleteNodeBSTrecursive(BinTreeNode *root, int data)
{
	BinTreeNode *successor;

	if (root == NULL)
		return (NULL);
	if (data < root->data)
		root->pLeftChild = deleteNodeBSTrecursive(root->pLeftChild, data);
	else if (data > root->data)
		root->pRightChild = deleteNodeBSTrecursive(root->pRightChild, data);
	else
	{
		if (root->pLeftChild == NULL)
		{
			// 왼쪽 자식이 없으면, 오른쪽 자식으로 연결한다.
			// 오른쪽 자식이 없더라도, NULL이기 때문에 상관 없다.
			successor = root->pRightChild;
			deleteBinTreeNode(root);
			return (successor);
		}
		else if (root->pRightChild == NULL)
		{
			// 왼쪽 자식만 있는 경우이다.
			successor = root->pLeftChild;
			deleteBinTreeNode(root);
			return (successor);
		}
		// 왼쪽 오른쪽 둘 다 자식노드가 존재하는 상황이다.
		successor = root->pRightChild;
		while (successor->pLeftChild)
			successor = successor->pLeftChild;
		root->data = successor->data;
		root->pRightChild = deleteNodeBSTrecursive(root->pRightChild, successor->data);
	}
	return (root);
}
int deleteNodeBST(BinTree *bst, int data)
{
	if (bst == NULL)
		return (-1);
	if (deleteNodeBSTrecursive(bst->pRootNode, data))
		return(TRUE);
	return (FALSE);
}