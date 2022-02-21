#include "bintree.h"
#include "bintree_traversal.h"
#include <stdlib.h>
#include <stdio.h>

/* 이진 트리 노드 생성*/
BinTreeNode *makeBinTreeNode(char data)
{
	BinTreeNode *newTreeNode;

	newTreeNode = calloc(1, sizeof(BinTreeNode));
	if (newTreeNode == NULL)
	{
		printf("<ERR>  Fail to allocate memory for BinTreeNode\n");
		return (NULL);
	}
	newTreeNode->data = data;
	return (newTreeNode);
}

int	deleteBinTreeNode(BinTreeNode *node)
{
	free(node);
	return(TRUE);
}
/* 이진 트리 생성*/
BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree* newTree;

	newTree = malloc(sizeof(BinTree));
	if (newTree == NULL)
	{
		printf("<ERR> Fail to allocate memory for BinTree\n");
		return (NULL);
	}
	newTree->pRootNode = makeBinTreeNode(rootNode.data);
	if (!newTree->pRootNode)
	{
		printf("fail to set root node\n");
		free(newTree);
		return (NULL);
	}
	return (newTree);
}
/* 이진 트리의 루트노드의 포인터 반환*/
BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (pBinTree == NULL)
		return (NULL);
	return (pBinTree->pRootNode);
}
/*
 * 아무런 조건 없이 (트리의 모양과 관계 없이, 왼쪽자식의 유무와 관계 없이) 그냥 추가만 하는 함수 
*/
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *leftchildnode;

	leftchildnode = makeBinTreeNode(element.data);
	if (leftchildnode == NULL)
		return (NULL);
	pParentNode->pLeftChild = leftchildnode;
	return (leftchildnode);
}

/*
 * 아무런 조건 없이 (트리의 모양과 관계 없이, 오른쪽자식의 유무와 관계 없이) 그냥 추가만 하는 함수 
*/
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *rightchildnode;

	rightchildnode =makeBinTreeNode(element.data);
	if (rightchildnode == NULL)
		return (NULL);
	pParentNode->pRightChild = rightchildnode;
	return (rightchildnode);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (pNode == NULL)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (pNode == NULL)
		return (NULL);
	return (pNode->pRightChild);
}

static void deleteAllBinTreeNodeRecursive(BinTreeNode *Node)
{
	if (Node == NULL)
		return ;
	deleteAllBinTreeNodeRecursive(Node->pLeftChild);
	deleteAllBinTreeNodeRecursive(Node->pRightChild);
	free(Node);
}

void deleteBinTree(BinTree* pBinTree)
{
	if (!pBinTree || !pBinTree->pRootNode)
		return ;
	deleteAllBinTreeNodeRecursive(pBinTree->pRootNode);
	free(pBinTree);
}

int isLeafNode(BinTreeNode *pNode)
{
	if (!pNode)
		return (-1);
	if (!pNode->pLeftChild || !pNode->pRightChild)
		return (FALSE);
	return (TRUE);
}

int showBinTreeNode(BinTreeNode *node)
{
	if (node == NULL)
		return (FALSE);
	printf("---------------\n");
	printf("data : %d\n", node->data);
	printf("height : %d\n", node->height);
	printf("balance : %d\n", node->balance);
	printf("---------------\n");

	return (TRUE);
}


void showBinTree(BinTree *tree)
{
	int (*shownode)(BinTreeNode *) = showBinTreeNode;
	printf("SHOW TREE\n");
	levelorderTraversal(tree, shownode);
	// postorderTraversal(tree->pRootNode, shownode);
	// preorderTraversal(tree->pRootNode, shownode);
	return ;
}